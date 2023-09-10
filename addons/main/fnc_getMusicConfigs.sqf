#include "script_component.hpp"
disableSerialization;

private _musicConfigs = "true" configClasses (configFile >> "CfgMusic");
private _musicThemes = [];
private _musicConfigHashMap = createHashMap;
{
	// Current result is saved in variable _x
	private _values = ["","","","","","",""];
	// "_configName","_musicPath","_name","_theme","_type","_musicClass","_config"
	private _configName = configName _x;
	private _musicPath = (_x >> "sound") select 0;
	private _name = getText (_x >> "name");
	if (_name == "") then { continue };

	if (isNil "_musicPath" || isNil "_name") then {
		continue;
	};

	private _theme = toLower(getText (_x >> "theme"));
	if (isNil "_theme") then { _theme = "" };
	_musicThemes pushBackUnique _theme;
	private _type = toLower (getText (_x >> "type"));
	if (isNil "_type") then { _type = "" };
	private _musicClass = toLower (getText (_x >> "musicClass"));
	if (isNil "_musicClass") then { _musicClass = "" };
	private _duration = getNumber (_x >> "duration");
	if (isNil "_duration") then { _duration = 999 };

	_values = [_configName, _musicPath, _name, _theme, _type, _musicClass, _x, _duration];

	_musicConfigHashMap insert [[toLower(configName _x), _values]];
} forEach _musicConfigs;

GVAR(musicConfigs) = _musicConfigHashMap;
GVAR(musicThemes) = _musicThemes;