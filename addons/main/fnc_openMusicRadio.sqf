#include "script_component.hpp"
disableSerialization;
#define IDC_main_TREEVIEW 10

#define WINDOW_W 140

GVAR(RadioMenuDisplay) = createDialog QGVAR(RadioMenu);
systemChat format ["Tried opening display %1, returned: %2", QGVAR(RadioMenu), str GVAR(RadioMenuDisplay)];

