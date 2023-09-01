#include "script_component.hpp"
disableSerialization;
#define IDC_main_TREEVIEW 10

#define WINDOW_W 140

GVAR(RadioMenuDisplay) = createDialog QGVAR(RadioMenu);
systemChat format ["Tried opening display %1, returned: %2", QGVAR(RadioMenu), str GVAR(RadioMenuDisplay)];

private _ctrlTree = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_TREE_IDC;
private _ctrlQueueButton = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_QUEUEBUTTON_IDC;
private _ctrlVolume = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_VOLUME_IDC;

if (isNil QGVAR(musicConfigs)) then { [] call FUNC(getMusicConfigs); };

_ctrlTree tvAdd [[], "Lead"];
_ctrlTree tvAdd [[], "Action"];
_ctrlTree tvAdd [[], "Stealth"];
_ctrlTree tvAdd [[], "Calm"];
_ctrlTree tvAdd [[], "Default"];

{
	// Current result is saved in variable _x
	// values _y
	_y params ["_configName", "_musicPath", "_name", "_theme", "_type", "_musicClass"];
	private _musicFolder = 4;
	switch (_musicClass) do {
		case "lead": { _musicFolder = 0; };
		case "action": { _musicFolder = 1; };
		case "stealth": { _musicFolder = 2; };
		case "calm": { _musicFolder = 3; };
		default { };
	};
	private _tvEntry = _ctrlTree tvAdd [[_musicFolder], _name];
	_ctrlTree tvSetData [[_musicFolder, _tvEntry], _configName];
	//systemChat format ["Added entry: %1", _name];
	
} forEach GVAR(musicConfigs);
_ctrlTree tvSort [[0], false];
_ctrlTree tvSort [[1], false];
_ctrlTree tvSort [[2], false];
_ctrlTree tvSort [[3], false];
_ctrlTree tvSort [[4], false];

systemChat format ["button: %1 %2", _ctrlQueueButton, _ctrlVolume];
_ctrlQueueButton ctrlAddEventHandler ["onButtonClick", {
	params ["_ctrl"];
	private _ctrlTree = ctrlParent _ctrl displayCtrl RADIO_MENU_TREE_IDC;
	private _className = _ctrlTree tvData (tvCurSel _ctrlTree);
	playMusic _className;
	systemChat format ["playing %1", _className];
}];

_ctrlVolume ctrlAddEventHandler ["onSliderPosChanged", {
	params ["_ctrl", "_value"];
	GVAR(musVolume) = _value;
	systemChat format ["volume: %1", _value];
}];