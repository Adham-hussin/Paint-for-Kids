#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder;
			if (x < ITM_SELECT * UI.MenuItemWidth)
			{
				ClickedItemOrder = (x / UI.MenuItemWidth);
			}
			else
			{
				ClickedItemOrder = (x / (UI.MenuItemWidth / 2) - ITM_SELECT);
			}
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE : return DRAW_SQUARE;
			case ITM_TRI : return DRAW_TRI;
			case ITM_HEX : return DRAW_HEX;
			case ITM_CIRCLE : return DRAW_CIRCLE;
			case ITM_SELECT : return SELECT;
			case ITM_DRW_CLR : return DRW_CLR;
			case ITM_FILL_CLR : return FILL_CLR;
			case CLR_BLK : return BLK;
			case CLR_YEL : return YEL;
			case CLR_ORG : return ORG;
			case CLR_GRN : return GRN;
			case CLR_RED : return RD;
			case CLR_BLU : return BLU;
			case ITM_DEL : return DEL;
			case ITM_MOVE : return MOVE;
			case ITM_UNDO : return UNDO;
			case ITM_REDO : return REDO;
			case ITM_CLEAR : return CLEAR;
			case ITM_REC : return REC;
			case ITM_REC_STOP : return REC_STOP;
			case ITM_REC_PLAY : return REC_PLAY;
			case ITM_SAVE : return SAVE;
			case ITM_LOAD : return LOAD;
			case ITM_PLAY_MODE : return TO_PLAY;
			case ITM_EXIT_DRAW: return EXIT;	

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x >= UI.width - 1.5 * UI.MenuItemWidth / 2 && y <= 2 * UI.ToolBarHeight)
				return SOUND;
			else
				return DRAWING_AREA;	
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_FIG_TYPE: return PICK_FIG_TYPE;
			case ITM_FIG_FILL: return PICK_FIG_FILL;
			case ITM_FIG_TYPE_FILL: return PICK_FIG_TYPE_FILL;
			case ITM_DRAW_MODE: return TO_DRAW;
			case ITM_EXIT_PLAY: return EXIT;	

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x >= UI.width - 1.5 * UI.MenuItemWidth / 2 && y <= 2 * UI.ToolBarHeight)
				return SOUND;
			else
				return DRAWING_AREA;	
		}

		//[3] User clicks on the status bar
		return STATUS;
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////

Input::~Input()
{
}