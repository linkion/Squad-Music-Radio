#include "script_component.hpp"
disableSerialization;

if (isNil QGVAR(musQueue)) then {
	GVAR(musQueue) = createHashMap;
};

private _currentQueue = GVAR(musQueue) get (groupId group player);

if (isNil "_currentQueue") exitWith { };

private _musClass = _currentQueue # 0 # 0;

if (isNil "_musClass") exitWith { };

private _musConfig = (GVAR(musicConfigs) get (toLower(_musClass))) # 6;
private _musName = (GVAR(musicConfigs) get (toLower(_musClass))) # 2;
private _musDur = getNumber (_musConfig >> "duration");
private _timeStarted = _currentQueue # 0 # 2;

private _currentTime = -1;
if (serverTime == 0) then {
	_currentTime = time;
} else {
	_currentTime = serverTime;
};

if ((_currentTime - _timeStarted) > _musDur && _timeStarted > 0) then {
	_currentQueue deleteAt 0;
	publicVariable QGVAR(musQueue);
	[] call FUNC(processQueue);
} else {
	if  (_timeStarted > 0) then {
		playMusic [_musClass, _currentTime - _timeStarted];
		GVAR(currentSong) = GVAR(musicConfigs) get (toLower(_musClass));
	} else {
		playMusic [_musClass, 0];

		private _values = (GVAR(musQueue) get (groupId group player));
		(_values select 0) set [2, _currentTime];
		publicVariable QGVAR(musQueue);
		GVAR(currentSong) = GVAR(musicConfigs) get (toLower(_musClass));
	};
};
[] call FUNC(processQueueList);

