#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	
	//TODO: Add more items names here
	ITM_SQUARE,
	ITM_TRI,
	ITM_HEX,
	ITM_CIRCLE,
	ITM_SELECT,
	ITM_DRW_CLR,
	ITM_FILL_CLR,
	CLR_BLK,
	CLR_YEL,
	CLR_ORG,
	CLR_GRN,
	CLR_RED,
	CLR_BLU,
	ITM_DEL,
	ITM_MOVE,
	ITM_UNDO,
	ITM_REDO,
	ITM_CLEAR,
	ITM_REC,
	ITM_REC_STOP,
	ITM_REC_PLAY,
	ITM_SAVE,
	ITM_LOAD,
	ITM_PLAY_MODE,
	ITM_EXIT_DRAW,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_FIG_TYPE,
	ITM_FIG_FILL,
	ITM_FIG_TYPE_FILL,
	ITM_DRAW_MODE,
	ITM_EXIT_PLAY,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	int choose;
	bool isfilled;
	bool sound;


	/// Add more members if needed
	
}UI;	//create a global object UI

#endif