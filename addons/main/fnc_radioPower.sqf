#include "script_component.hpp"
disableSerialization;

params ["_power"];

if (isNil QGVAR(musicConfigs)) then { [] call FUNC(getMusicConfigs); };
if (isNil QGVAR(radioListeners)) then { GVAR(radioListeners) = createHashMap; };


GVAR(radioPower) = _power;


if (_power) then {
	[] spawn FUNC(processQueue);

	private _listeners = GVAR(radioListeners) get (groupId group player);
	if (isNil "_listeners") then {
		GVAR(radioListeners) set [groupId group player, [player]];
	} else {
		(GVAR(radioListeners) get (groupId group player)) pushBackUnique player;
	};
	publicVariable QGVAR(radioListeners);
} else {
	playMusic "";
	private _listeners = GVAR(radioListeners) get (groupId group player);
	if (!(isNil "_listeners")) then {
		private _pos = (GVAR(radioListeners) get (groupId group player)) findIf { _x == player};

		(GVAR(radioListeners) get (groupId group player)) deleteAt _pos;
	};
	publicVariable QGVAR(radioListeners);
};

if (isNil QGVAR(musicEventHandle)) then {
	GVAR(musicEventHandle) = addMusicEventHandler ["MusicStop", {
		if (GVAR(radioPower)) then {
			[] call FUNC(processQueue);
		}
	}];
};

GVAR(radioPower)