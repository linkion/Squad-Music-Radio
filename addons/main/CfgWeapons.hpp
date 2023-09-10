class CfgWeapons {
	class ItemCore;
	class InventoryItem_Base_F;
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
    class SMRA_musicRadio: CBA_MiscItem
    {
        displayName = "Squad Music Radio"; //Item's Display Name
        scope=2; //Scope 2 will show in editor
        author = "DarkShadow"; //Your Name
		picture = "\A3\Drones_F\Weapons_F_Gamma\Items\data\UI\gear_UAV_controller_oli_CA.paa"; //Displays icon in your Inventory
        model = "\A3\Structures_F\Items\Electronics\FMradio_F.p3d"; //Path to A3 FM Radio Model
		count = 1;
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_InventoryItems";
        icon = "iconObject_circle"; //Leave as is
        descriptionShort = "Item that enables use of Squad Music Radio."; //Description displayed when mouse is hovered over item in inventory
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };
};