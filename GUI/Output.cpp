#include "Output.h"
#include <cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = LIGHTGREEN;
	UI.PenWidth = 3;	//width of the figures frames
	UI.isfilled = 0;
	UI.choose = 0;
	UI.sound = 1;

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\MENU_RECT.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\MENU_SQUARE.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\MENU_TRI.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\MENU_HEX.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\MENU_CIRCLE.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\MENU_SELECT.jpg";
	MenuItemImages[ITM_DRW_CLR] = "images\\MenuItems\\MENU_DRW_CLR.jpg";
	MenuItemImages[ITM_FILL_CLR] = "images\\MenuItems\\MENU_FILL_CLR.jpg";
	MenuItemImages[CLR_BLK] = "images\\MenuItems\\CLR_BLK.jpg";
	MenuItemImages[CLR_YEL] = "images\\MenuItems\\CLR_YEL.jpg";
	MenuItemImages[CLR_ORG] = "images\\MenuItems\\CLR_ORG.jpg";
	MenuItemImages[CLR_GRN] = "images\\MenuItems\\CLR_GRN.jpg";
	MenuItemImages[CLR_RED] = "images\\MenuItems\\CLR_RED.jpg";
	MenuItemImages[CLR_BLU] = "images\\MenuItems\\CLR_BLU.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\MENU_DEL.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\MENU_MOVE.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\MENU_UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\MENU_REDO.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\MENU_CLEAR.jpg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\MENU_REC.jpg";
	MenuItemImages[ITM_REC_STOP] = "images\\MenuItems\\MENU_REC_STOP.jpg";
	MenuItemImages[ITM_REC_PLAY] = "images\\MenuItems\\MENU_REC_PLAY.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\MENU_SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\MENU_LOAD.jpg";
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\MENU_PLAY_MODE.jpg";
	MenuItemImages[ITM_EXIT_DRAW] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_SELECT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	for(int i=0; i<DRAW_ITM_COUNT-5; i++)
		pWind->DrawImage(MenuItemImages[i+5], 5*UI.MenuItemWidth + i*UI.MenuItemWidth/2, 0, UI.MenuItemWidth/2, UI.ToolBarHeight);
	pWind->DrawImage("images\\MenuItems\\sound.jpg", UI.width - 1.5 * UI.MenuItemWidth / 2, UI.ToolBarHeight, UI.MenuItemWidth / 2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(LIGHTBLUE, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE, 2);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_FIG_TYPE] = "images\\MenuItems\\MENU_SHAPE.jpg";
	MenuItemImages[ITM_FIG_FILL] = "images\\MenuItems\\MENU_CLR.jpg";
	MenuItemImages[ITM_FIG_TYPE_FILL] = "images\\MenuItems\\MENU_SHAPE_CLR.jpg";
	MenuItemImages[ITM_DRAW_MODE] = "images\\MenuItems\\MENU_DRAW.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_Exit1.jpg";
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(ORANGE, 2);
	pWind->DrawLine(0, UI.ToolBarHeight+1, UI.width, UI.ToolBarHeight+1);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	if (UI.sound)
		pWind->DrawImage("images\\MenuItems\\sound.jpg", UI.width - 1.5 * UI.MenuItemWidth / 2, UI.ToolBarHeight, UI.MenuItemWidth / 2, UI.ToolBarHeight);
	else
		pWind->DrawImage("images\\MenuItems\\mute.jpg", UI.width - 1.5 * UI.MenuItemWidth / 2, UI.ToolBarHeight, UI.MenuItemWidth / 2, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.3), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}


void Output::DrawSqu(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	Point P2;
	Point P3;
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	int n = 74;
	P2.x = P1.x - n;
	P2.y = P1.y - n;
	P3.x = P1.x + n;
	P3.y = P1.y + n;
	
	pWind->DrawRectangle(P2.x, P2.y, P3.x, P3.y, style);
	
}
void Output::DrawTria(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	
}

void Output::DrawHexa(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int Px[6];
	int Py[6];
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	int n = 100 ;
	float height = sqrt(n *n - (n / 2) *(n / 2) );
	Px[0] = P1.x - n ;
	Py[0] = P1.y;
	Px[1] = P1.x - n / 2;
	Py[1] = P1.y - height;
	Px[2] = P1.x + n / 2 ;
	Py[2] = P1.y - height;
	Px[3] = P1.x + n ;
	Py[3] = P1.y;
	Px[4] = P1.x + n / 2 ;
	Py[4] = P1.y + height;
	Px[5] = P1.x - n / 2 ;
	Py[5] = P1.y + height;
	pWind->DrawPolygon(Px, Py, 6 ,style);
	
}

void Output::DrawCir(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	int radius = sqrt(pow((P1.x - P2.x) , 2) + pow((P1.y - P2.y) , 2)) ;
	
	pWind->DrawCircle(P1.x, P1.y,radius , style);
	
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

