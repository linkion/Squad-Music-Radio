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
                    class SMRA_RadioPowerOn {
                        displayName = "Radio Power On";
                        condition = QUOTE(true);
                        icon = QUOTE();
                        statement = QUOTE([true] call FUNC(radioPower));
                    };
                    class SMRA_RadioPowerOff {
                        displayName = "Radio Power Off";
                        condition = QUOTE(true);
                        icon = QUOTE();
                        statement = QUOTE([false] call FUNC(radioPower));
                    };
                };
            };
        };
    };
};