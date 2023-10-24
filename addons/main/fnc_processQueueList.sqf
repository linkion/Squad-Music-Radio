#include "script_component.hpp"
disableSerialization;

private _queueList = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_QUEUELIST_IDC;
lnbClear _queueList;

_queueList lnbSetColumnsPos [0,0.05];

private _tempArrayQueue = [];
private _tempCount = 0;
{
	// Current result is saved in variable _x
	if (_tempCount == 0) then {
		_tempCount = _tempCount + 1;
		continue;
		//skip currently playing song
	};
	
	private _musClass = _x # 0;
	private _musName = (GVAR(musicConfigs) get (toLower(_musClass))) # 2;

	_queueList lnbAddRow [str (_tempCount), _musName];
	_tempCount = _tempCount + 1;
} forEach (GVAR(musQueue) get (groupId group player));

private _listenerList = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_LISTENERSLIST_IDC;
lbClear _listenerList;

{
	if (!alive _x) then {
		(GVAR(radioListeners) get (groupId group player)) deleteAt _forEachIndex;
	} else {
		_listenerList lbAdd (name _x);
	};
} forEach (GVAR(radioListeners) get (groupId group player));