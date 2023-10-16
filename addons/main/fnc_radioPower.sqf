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

if (count GVAR(radioListeners) > 1) then {
	[] remoteExecCall [QFUNC(processQueueList), GVAR(radioListeners) get (groupId group player)];
};

if (isNil QGVAR(musicEventHandle)) then {
	GVAR(musicEventHandle) = addMusicEventHandler ["MusicStop", {
		if (GVAR(radioPower)) then {
			[] call FUNC(processQueue);
		}
	}];
};

if (isNil(QGVAR(playerEventHandlerRadio))) then {
	GVAR(player_event_handler_radio) = ["loadout", {
		private _hasRad = [] call FUNC(hasRadio);
		[_hasRad] call FUNC(radioPower);
	}] call CBA_fnc_addPlayerEventHandler;
};

GVAR(radioPower)