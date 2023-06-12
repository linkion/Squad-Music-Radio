#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		name = CSTRING(component);
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

#include "CfgMagazines.hpp"

#include "CfgVehicles.hpp"
