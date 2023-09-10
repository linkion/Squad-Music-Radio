#include "script_component.hpp"
disableSerialization;

params ["_power"];

if (isNil QGVAR(musicConfigs)) then { [] call FUNC(getMusicConfigs); };

GVAR(radioPower) = _power;

systemChat format ["radio power: %1", _power];

if (_power) then {
	[] spawn FUNC(processQueue);
} else {
	playMusic "";
};

if (isNil QGVAR(musicEventHandle)) then {
	GVAR(musicEventHandle) = addMusicEventHandler ["MusicStop", {
		[] call FUNC(processQueue);
	}];
};

GVAR(radioPower)