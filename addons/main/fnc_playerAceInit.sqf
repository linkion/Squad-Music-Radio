#include "script_component.hpp"

params ["_player"];

/*
 * Argument:
 * 0: Action name <STRING>
 * 1: Name of the action shown in the menu <STRING>
 * 2: Icon <STRING>
 * 3: Statement <CODE>
 * 4: Condition <CODE>
 * 5: Insert children code <CODE> (Optional)
 * 6: Action parameters <ANY> (Optional)
 * 7: Position (Position array, Position code or Selection Name) <ARRAY>, <CODE> or <STRING> (Optional)
 * 8: Distance <NUMBER> (Optional)
 * 9: Other parameters [showDisabled,enableInside,canCollapse,runOnHover,doNotCheckLOS] <ARRAY> (Optional)
 * 10: Modifier function <CODE> (Optional)
 */
private _actions = [];

if (false) then {
	_actions
};

private _actionText = "";
switch (_radioPower) do {
	case false: { _actionText = "Turn On" };
	default { _actionText = "Turn Off" };
};

private _actions = [
	"MusicRadioPower",
	_actionText,
	"",
	[] call FUNC(radioPowerOn),
	true,
] call ace_interact_menu_fnc_createAction;

_actions append _action;


[] call FUNC(getMusicConfigs);
hint format["%1", GVAR(musicConfigs)];

_actions