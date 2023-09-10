#include "script_component.hpp"
disableSerialization;
#define IDC_main_TREEVIEW 10

#define WINDOW_W 140

GVAR(RadioMenuDisplay) = createDialog QGVAR(RadioMenu);

private _ctrlTree = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_TREE_IDC;
private _ctrlQueueButton = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_QUEUEBUTTON_IDC;
private _ctrlSkipButton = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_SKIPBUTTON_IDC;

if (isNil QGVAR(musicConfigs)) then { [] call FUNC(getMusicConfigs); };

_ctrlTree tvAdd [[], "Lead"];
_ctrlTree tvAdd [[], "Action"];
_ctrlTree tvAdd [[], "Stealth"];
_ctrlTree tvAdd [[], "Calm"];
_ctrlTree tvAdd [[], "Default"];

{
	// Current result is saved in variable _x
	// values _y
	_y params ["_configName", "_musicPath", "_name", "_theme", "_type", "_musicClass", "_config", "_duration"];
	private _musicFolder = 4;
	switch (_musicClass) do {
		case "lead": { _musicFolder = 0; };
		case "action": { _musicFolder = 1; };
		case "stealth": { _musicFolder = 2; };
		case "calm": { _musicFolder = 3; };
		default { };
	};
	private _text = format ["%1 %2", [_duration, "MM:SS"] call BIS_fnc_secondsToString, _name];
	private _tvEntry = _ctrlTree tvAdd [[_musicFolder], _text];
	_ctrlTree tvSetData [[_musicFolder, _tvEntry], _configName];
	_ctrlTree tvSetValue [[_musicFolder, _tvEntry], _duration];
	//systemChat format ["Added entry: %1", _name];
	
} forEach GVAR(musicConfigs);
_ctrlTree tvSortByValue [[0], true];
_ctrlTree tvSortByValue [[1], true];
_ctrlTree tvSortByValue [[2], true];
_ctrlTree tvSortByValue [[3], true];
_ctrlTree tvSortByValue [[4], true];

_ctrlQueueButton ctrlAddEventHandler ["ButtonClick", {
	params ["_ctrl"];
	private _ctrlTree = ctrlParent _ctrl displayCtrl RADIO_MENU_TREE_IDC;
	private _className = _ctrlTree tvData (tvCurSel _ctrlTree);
	if (isNil QGVAR(musQueue)) then {
		GVAR(musQueue) = createHashMap;
	};
	private _queue = GVAR(musQueue) get (groupId group player);
	if (isNil "_queue") then {
		GVAR(musQueue) set [(groupId group player), []];
		_queue = GVAR(musQueue) get (groupId group player);
	};

	// [music class, player who queued, time started playing]
	_queue pushBack [_className, player, -1];

	publicVariable QGVAR(musQueue);

	if (GVAR(radioPower)) then {
		[] call FUNC(processQueue);
	};
}];

_ctrlSkipButton ctrlAddEventHandler ["ButtonClick", {
	params ["_ctrl"];
	private _currentQueue = GVAR(musQueue) get (groupId group player);
	private _listeners = GVAR(radioListeners) get (groupId group player);
	private _skipArray = GVAR(radioSkip) get (groupId group player);
	if (isNil "_currentQueue") exitWith { systemChat "No song playing" };
	if (isNil "_listeners") exitwith {
		systemChat "Can't skip. You're not listening to the radio.";
	};
	if (isNil "_skipArray") then {
		_skipArray = [];
		GVAR(radioSkip) set [groupId group player, [player]];
	};

	private _votes = count _skipArray;
	_votes = _votes + 1;
	private _votesNeeded = count _listeners;

	player groupChat format ["I'd like to skip the current song (%1/%2)", _votes, _votesNeeded];
	if (_votes >= _votesNeeded) then {
		player groupChat "Skipping...";
		
		_currentQueue deleteAt 0;

		publicVariable QGVAR(musQueue);
		remoteExec [QFUNC(processQueue), _listeners];
	} else {
		_skipArray pushBackUnique player;
	};
}];