#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		name = CSTRING(COMPONENT);
		units[] = {};
		weapons[] = {"SMRA_musicRadio"};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"CBA_main", "ACE_main"};
		author = "You";
		url = "https://community.bistudio.com/wiki";
		VERSION_CONFIG;
	};
};

#include "CfgEventHandlers.hpp"

#include "CfgVehicles.hpp"

#include "CfgWeapons.hpp"

#include "gui.hpp"