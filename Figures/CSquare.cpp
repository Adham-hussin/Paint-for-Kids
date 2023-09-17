#include "CSquare.h"


CSquare::CSquare(Point p1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = p1;
}

CSquare::CSquare()
{
}

void CSquare::Load(ifstream& Infile)
{
	string drw, fil;
	Infile >> ID >> center.x >> center.y >> drw >> fil;
	Selected = 0;
	FigGfxInfo.DrawClr = StrToClr(drw);
	if (fil == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.FillClr = StrToClr(fil);
		FigGfxInfo.isFilled = true;
	}
}

bool CSquare::IsIn(float x, float y)
{
	int n = 74;
	int range = 2 * n;
	bool x_cond = abs(x - center.x + n) <= range && abs(x - center.x - n) <= range;
	bool y_cond = abs(y - center.y + n) <= range && abs(y - center.y - n) <= range;
	if (x_cond && y_cond)
		return true;
	return false;
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQR\t" << ID << "\t" << center.x << "\t" << center.y << "\t"
		<< ClrToStr(FigGfxInfo.DrawClr) << "\t" << (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}
void CSquare::Move(Point p)
{
	center = p;
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqu to draw a square on the screen	
	pOut->DrawSqu(center, FigGfxInfo, Selected);
}

CFigure* CSquare::copy()
{
	return new CSquare(*this);
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The selected figure is a SQUARE, ID: " + to_string(ID) + "\t \t \t  P(" + to_string(center.x) + ", " + to_string(center.y)
		+ ")\t \t \t Draw Color: "
		+ ClrToStr(FigGfxInfo.DrawClr) + "\t \t \t Fill Color: " + (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL"));
}
 int CSquare::type()
 {
	 return 1;
 }

  Point CSquare::GetCenter()
 {
	 return center;
 }