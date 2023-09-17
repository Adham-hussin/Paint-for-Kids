#include "CFigure.h"

int CFigure::unique = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	 //Default status is non-filled.
	ID = ++unique;
	Selected = false;
}

CFigure::CFigure()
{
}

int CFigure::GetId()
{
	return ID;
}

void CFigure::SetId(int id)
{
	ID = id;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

float CFigure::area(float x1, float x2, float x3, float y1, float y2, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0); //Triangle area using determinant
}

bool CFigure::IsSelected() const
{	return Selected; }

color CFigure::StrToClr(string str)
{
	if (str == "BLACK")
		return BLACK;
	else if (str == "YELLOW")
		return YELLOW;
	else if (str == "ORANGE")
		return ORANGE;
	else if (str == "GREEN")
		return GREEN;
	else if (str == "RED")
		return RED;
	else if (str == "BLUE")
		return BLUE;
}
/*int CFigure::getID()
{
return ID;
}
*/
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::ClrToStr(color clr)
{
	if (clr == BLACK) 
		return "BLACK";
	else if (clr == YELLOW) 
		return "YELLOW";
	else if (clr == ORANGE) 
		return "ORANGE";
	else if (clr == GREEN) 
		return "GREEN";
	else if (clr == RED) 
		return "RED";
	else if (clr == BLUE) 
		return "BLUE";
}

color CFigure::getFillColor()
{
	return FigGfxInfo.FillClr;
}

color CFigure::getDrawColor() 
{
	return FigGfxInfo.DrawClr;
}

void CFigure::ChngIsFilled(bool b)
{
	FigGfxInfo.isFilled = b;
}
bool CFigure::GetIsFilled()
{
	return FigGfxInfo.isFilled;
}
