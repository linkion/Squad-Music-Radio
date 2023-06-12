class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class SMRA_Interact {
                displayName = "Music Radio";
                condition = QUOTE(true);
                exceptions[] = {"isNotInside", "isNotSitting"};
                statement = ""; // With no statement the action will only show if it has children
                insertChildren = QUOTE(call FUNC(playerAceInit));
                priority = 0.1;
                icon = "";
            };
        };
    };
};