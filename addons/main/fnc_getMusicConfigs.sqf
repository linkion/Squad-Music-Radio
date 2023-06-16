#include "script_component.hpp"

private _musicConfigs = "true" configClasses (configFile >> "CfgMusic");
private _musicConfigHashMap = createHashMap;
{
	// Current result is saved in variable _x
	private _values = ["","","","","",""];
	// "_configName","_musicPath","_name","_theme","_type","_musicClass"
	private _configName = configName _x;
	private _musicPath = (_x >> "sound") select 0;
	private _name = _x >> "name";

	if (isNil "_musicPath" || isNil "_name") then {
		continue;
	};

	private _theme = toLower (getText (_x >> "theme"));
	if (isNil "_theme") then { _musicClass = "" };
	private _type = toLower (getText (_x >> "type"));
	if (isNil "_type") then { _musicClass = "" };
	private _musicClass = toLower (getText (_x >> "musicClass"));
	if (isNil "_musicClass") then { _musicClass = "" };

	_values = [_configName, _musicPath, _name, _theme, _type, _musicClass];

	_musicConfigHashMap insert [[toLower(configName _x), _values]];
} forEach _musicConfigs;

GVAR(musicConfigs) = _musicConfigHashMap;