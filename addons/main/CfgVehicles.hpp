class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class SMRA_Interact {
                    displayName = "Music Radio";
                    condition = QUOTE([] call FUNC(hasRadio));
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    statement = ""; // With no statement the action will only show if it has children
                    priority = 0.1;
                    icon = "";
                    class GVAR(RadioPowerOn) {
                        displayName = "Radio Power On";
                        condition = QUOTE(!GVAR(radioPower));
                        icon = QUOTE();
                        statement = QUOTE([true] call FUNC(radioPower));
                    };
                    class GVAR(RadioPowerOff) {
                        displayName = "Radio Power Off";
                        condition = QUOTE(GVAR(radioPower));
                        icon = QUOTE();
                        statement = QUOTE([false] call FUNC(radioPower));
                    };
                    class GVAR(TuneRadio) {
                        displayName = "Tune Radio";
                        condition = QUOTE(GVAR(radioPower));
                        icon = QUOTE();
                        statement = QUOTE([] call FUNC(openMusicRadio));
                    };
                };
            };
        };
    };
};

class Extended_EventHandlers;   	// External class reference
class Extended_PostInit_EventHandlers
{
    class SMRA_postInitCalls
    {
        clientInit = QUOTE(GVAR(radioPower) = false);
    };
};