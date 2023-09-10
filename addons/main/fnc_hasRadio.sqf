#include "script_component.hpp"
disableSerialization;

private _items = items player;

if ("SMRA_musicRadio" in _items) then {
	true
} else {
	false
};