#include "gui_defines.hpp"

class GVAR(RadioMenu) {
	idd = RADIO_MENU_IDD;
	
	class ControlsBackground {
		class Background: ctrlStaticBackground
		{
			idc = -1;
			x = QUOTE(0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(40 * GUI_GRID_CENTER_W);
			h = QUOTE(25 * GUI_GRID_CENTER_H);
		};
		class Header: ctrlStaticTitle
		{
			text = "Squad Music Radio";
			x = QUOTE(0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(40 * GUI_GRID_CENTER_W);
			h = QUOTE(1 * GUI_GRID_CENTER_H);
		};
	};
	class Controls {
		class MusicTreeSearch
		{
			
			idc = RADIO_MENU_TREESEARCH_IDC;
			type = 2;
			style = "512";
			x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(38 * GUI_GRID_CENTER_W);
			h = QUOTE(1 * GUI_GRID_CENTER_H);
			font = "PuristaMedium";
			sizeEx = 0.04;
			autocomplete = "";
			canModify = QUOTE(true);
			maxChars = 100;
			forceDrawCaret = QUOTE(false);
			colorSelection[] = {0,1,0,1};
			colorText[] = {1,1,1,1};
			colorDisabled[] = {1,0,0,1};
			colorBackground[] = {0,0,0,0.8};
			text = "";
			tooltip = "Type to search";
		};
		class MusicTree: ctrlTree
		{
			idc = RADIO_MENU_TREE_IDC;
			moving = 0;
			type = CT_TREE;
			style = ST_LEFT;
			x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(2.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(38 * GUI_GRID_CENTER_W);
			h = QUOTE(16 * GUI_GRID_CENTER_H);
			sizeEx = 0.04;
			font = "RobotoCondensed";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
			colorDisabled[] = {1,1,1,0.25};
			shadow = 0;
			access = 0;

			/* CT_TREE specific properties */
			idcSearch = RADIO_MENU_TREESEARCH_IDC;
			colorSelect[] = {1,1,1,0.7};
			colorSelectText[] = {0,0,0,1};
			colorBorder[] = {0,0,0,0};
			colorSearch[] =
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
			};
			colorMarked[] = {0.2,0.3,0.7,1};
			colorMarkedText[] = {0,0,0,1};
			colorMarkedSelected[] = {0,0.5,0.5,1};
			multiselectEnabled = 0;
			colorPicture[] = {1,1,1,1};
			colorPictureSelected[] = {0,0,0,1};
			colorPictureDisabled[] = {1,1,1,0.25};
			colorPictureRight[] = {1,1,1,1};
			colorPictureRightSelected[] = {0,0,0,1};
			colorPictureRightDisabled[] = {1,1,1,0.25};
			colorArrow[] = {1,1,1,1};
			maxHistoryDelay = 1;
			colorSelectBackground[] = {0,0,0,0.5};
			colorLines[] = {0,0,0,0};
			class ScrollBar: ScrollBar
			{
			};
			expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa";
			hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa";
			rowHeight = 0.0439091;
			borderSize = 0;
			expandOnDoubleclick = 1;

			/* CT_TREE user interface eventhandlers */
			//onTreeSelChanged = "systemChat str ['onTreeSelChanged',_this]; false";
			//onTreeLButtonDown = "systemChat str ['onTreeLButtonDown',_this]; false";
			//onTreeDblClick = "systemChat str ['onTreeDblClick',_this]; false";
			//onTreeExpanded = "systemChat str ['onTreeExpanded',_this]; false";
			//onTreeCollapsed = "systemChat str ['onTreeCollapsed',_this]; false";
			//onTreeMouseMove = "systemChat str ['onTreeMouseMove',_this]; false";
			//onTreeMouseHold = "systemChat str ['onTreeMouseHold',_this]; false";
			//onTreeMouseExit = "systemChat str ['onTreeMouseExit',_this]; false";
		};
		class PlayButton: ctrlButton
		{
			idc = 1600;
			text = "Queue Music";
			x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(6 * GUI_GRID_CENTER_W);
			h = QUOTE(2 * GUI_GRID_CENTER_H);
		};
		class StopButton: ctrlXSliderH
		{
			idc = 1601;
			text = "Volume";
			x = QUOTE(9 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(16 * GUI_GRID_CENTER_W);
			h = QUOTE(2 * GUI_GRID_CENTER_H);
		};
		class Cancel: ctrlButtonClose
		{
			idc = 1602;
			text = "Close";
			action = QUOTE(findDisplay RADIO_MENU_IDD closeDisplay 1);
			x = QUOTE(33 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(6 * GUI_GRID_CENTER_W);
			h = QUOTE(2 * GUI_GRID_CENTER_H);
		};
	};
};