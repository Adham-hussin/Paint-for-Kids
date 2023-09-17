#pragma once
#include "c:\users\eslam\onedrive\desktop\new folder\phase2 - code f22\figures\cfigure.h"
class CSquare :
	public CFigure
{
private:
	Point center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

