#include "script_component.hpp"

params ["_power"];

GVAR(radioPower) = _power;

systemChat format ["radio power: %1", _power];

