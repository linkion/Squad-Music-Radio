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
			y = QUOTE(1.25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
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
			y = QUOTE(2.75 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(38 * GUI_GRID_CENTER_W);
			h = QUOTE(18 * GUI_GRID_CENTER_H);
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
		class QueueButton: ctrlButton
		{
			idc = RADIO_MENU_QUEUEBUTTON_IDC;
			text = "Queue Music";
			x = QUOTE(1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(6 * GUI_GRID_CENTER_W);
			h = QUOTE(2 * GUI_GRID_CENTER_H);
		};
		class SkipButton: ctrlButton
		{
			idc = RADIO_MENU_SKIPBUTTON_IDC;
			text = "Vote to Skip";
			x = QUOTE(8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(6 * GUI_GRID_CENTER_W);
			h = QUOTE(2 * GUI_GRID_CENTER_H);
		};
		class nowPlayingStatic: ctrlStatic
		{
			x = QUOTE(14.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(20.75 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(16 * GUI_GRID_CENTER_W);
			h = QUOTE(1.2 * GUI_GRID_CENTER_H);
			text = "Now Playing";
		};
		class currentSongText: ctrlStatic
		{
			idc = RADIO_MENU_CURRENTSONGTEXT_IDC;
			x = QUOTE(15.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(21.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(16 * GUI_GRID_CENTER_W);
			h = QUOTE(1.5 * GUI_GRID_CENTER_H);
			text = "Your mom's a hoe";
			sizeEx = 0.05;
		};
		class progressBar: ctrlProgress
		{
			idc = RADIO_MENU_PROGRESSBAR_IDC;
			x = QUOTE(14.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(22.85 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(18 * GUI_GRID_CENTER_W);
			h = QUOTE(0.5 * GUI_GRID_CENTER_H);
			colorFrame[] = {256,256,256,256};
		};
		class progressText: ctrlStatic
		{
			idc = RADIO_MENU_PROGRESSTEXT_IDC;
			x = QUOTE(15.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
			y = QUOTE(23.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
			w = QUOTE(16 * GUI_GRID_CENTER_W);
			h = QUOTE(1 * GUI_GRID_CENTER_H);
			text = "00:00 / 00:00";
			sizeEx = 0.03;
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