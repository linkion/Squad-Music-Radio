class RscButton;
class ctrlButtonClose;

class GVAR(RadioMenu) {
	idd = RADIO_MENU_IDD;
	class ControlsBackground {
		class Background: ctrlStaticBackground
		{
			idc = 2200;
			x = QUOTE(0 * GUI_GRID_W + GUI_GRID_X);
			y = QUOTE(0 * GUI_GRID_H + GUI_GRID_Y);
			w = QUOTE(40 * GUI_GRID_W);
			h = QUOTE(25 * GUI_GRID_H);
		};
		class Header: ctrlStaticTitle
		{
			text = "Squad Music Radio";
			x = QUOTE(0);
			y = QUOTE(0);
			w = QUOTE(40 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};
	};
	class Controls {

		class RscListbox_1500: RscListbox
		{
			idc = 1500;
			x = QUOTE(1 * GUI_GRID_W + GUI_GRID_X);
			y = QUOTE(1 * GUI_GRID_H + GUI_GRID_Y);
			w = QUOTE(38 * GUI_GRID_W);
			h = QUOTE(20 * GUI_GRID_H);
		};
		class RscButton_1600: RscButton
		{
			idc = 1600;
			text = "Play Music";
			x = QUOTE(1 * GUI_GRID_W + GUI_GRID_X);
			y = QUOTE(22 * GUI_GRID_H + GUI_GRID_Y);
			w = QUOTE(6 * GUI_GRID_W);
			h = QUOTE(2 * GUI_GRID_H);
		};
		class RscButton_1601: RscButton
		{
			idc = 1601;
			text = "Stop Music";
			x = QUOTE(9 * GUI_GRID_W + GUI_GRID_X);
			y = QUOTE(22 * GUI_GRID_H + GUI_GRID_Y);
			w = QUOTE(6 * GUI_GRID_W);
			h = QUOTE(2 * GUI_GRID_H);
		};
		class Close: ctrlButtonClose
		{
			idc = 1602;
			text = "Close";
			x = QUOTE(33 * GUI_GRID_W + GUI_GRID_X);
			y = QUOTE(22 * GUI_GRID_H + GUI_GRID_Y);
			w = QUOTE(6 * GUI_GRID_W);
			h = QUOTE(2 * GUI_GRID_H);
		};
	};
};