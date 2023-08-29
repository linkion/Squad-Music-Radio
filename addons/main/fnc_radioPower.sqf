#include "script_component.hpp"

params ["_power"];
//uiNamespace setVariable ["SMRA_squadMusicRadioPower", true];
GVAR(radioPower) = _power;

systemChat format ["radio power: %1", _power];

