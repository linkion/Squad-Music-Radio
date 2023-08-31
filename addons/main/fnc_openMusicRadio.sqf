#include "script_component.hpp"
disableSerialization;
#define IDC_main_TREEVIEW 10

#define WINDOW_W 140

GVAR(RadioMenuDisplay) = createDialog QGVAR(RadioMenu);
systemChat format ["Tried opening display %1, returned: %2", QGVAR(RadioMenu), str GVAR(RadioMenuDisplay)];

private _ctrlTree = findDisplay RADIO_MENU_IDD displayCtrl RADIO_MENU_TREE_IDC;

if (isNil GVAR(musicConfigs)) then { [] call FUNC(getMusicConfigs); };

{
	// Current result is saved in variable _x
	// values _y
	_y params ["_configName", "_musicPath", "_name", "_theme", "_type", "_musicClass"];
	switch (_type) do {
		case "value": { };
		default { };
	};
	private _tvEntry = _ctrlTree tvAdd [[], _name];
	systemChat format ["Added entry: %1", _name];
	
} forEach GVAR(musicConfigs);
