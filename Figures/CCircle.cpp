#include "CCircle.h"
#include <iostream>
CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;
}

CCircle::CCircle()
{
}

void CCircle::Load(ifstream& Infile)
{
	string drw, fil;
	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> drw >> fil;
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

bool CCircle::IsIn(float x, float y) 
{
	float dist = sqrt( (P1.x - (int)x)* (P1.x - (int)x) + (P1.y - (int)y)* (P1.y - (int)y));
	rad = sqrt((P1.x - P2.x)* (P1.x - P2.x) + (P1.y - P2.y)* (P1.y - P2.y));
	if (dist <= rad)
		return true;
	return false;
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRC\t" << ID << "\t" << P1.x << "\t" << P1.y << "\t"
		<< P2.x << "\t" << P2.y << "\t"
		<< ClrToStr(FigGfxInfo.DrawClr) << "\t" << (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr): "NO_FILL") << endl;

}
void CCircle::Move(Point p)
{
	P1 = p;
	P2.x = p.x + rad;
	P2.y = P1.y;

}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pOut->DrawCir(P1, P2, FigGfxInfo, Selected);
}
CFigure* CCircle::copy()
{
	return new CCircle(*this);
}
void CCircle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The selected figure is a CIRCLE, ID: " + to_string(ID) + "\t \t \t  P1(" + to_string(P1.x) + ", " + to_string(P1.y) + ")\t \t \t P2("
		+ to_string(P2.x) + ", " + to_string(P2.y) + ")\t \t \t Draw Color: "
		+ ClrToStr(FigGfxInfo.DrawClr) + "\t \t \t Fill Color: " + (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL"));
}

 int CCircle::type()
 {
	 return 2;
 }

 Point CCircle::GetCenter()
 {
	 return P1;
 }