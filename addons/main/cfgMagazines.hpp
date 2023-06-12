class CfgMagazines
{
    class CBA_MiscItem_ItemInfo;
    class CA_Magazine; //Inherits the base magazine
    class SMRA_musicRadio: CA_Magazine
    {
        displayName = "Squad Music Radio"; //Item's Display Name
        scope=2; //Scope 2 will show in editor
        author = "DarkShadow"; //Your Name
        picture = "pictureThing"; //Displays icon in your Inventory
        model = "\A3\Structures_F\Items\Electronics\FMradio_F.p3d"; //Path to A3 FM Radio Model
        icon = "iconObject_circle"; //Leave as is
        descriptionShort = "Item that enables use of Squad Music Radio."; //Description displayed when mouse is hovered over item in inventory
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };
};