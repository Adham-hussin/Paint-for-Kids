#include "CTriangle.h"


CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;
}

CTriangle::CTriangle()
{
}

void CTriangle::Load(ifstream& Infile)
{
	string drw, fil;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> drw >> fil;
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



bool CTriangle::IsIn(float x, float y)
{
	float FullArea = area(Corner1.x, Corner2.x, Corner3.x, Corner1.y, Corner2.y, Corner3.y);
	float A1 = area(x, Corner1.x, Corner2.x, y, Corner1.y, Corner2.y);
	float A2 = area(x, Corner1.x, Corner3.x, y, Corner1.y, Corner3.y);
	float A3 = area(x, Corner2.x, Corner3.x, y, Corner2.y, Corner3.y);
	if (FullArea == A1 + A2 + A3)
		return true;
	return false;
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRI\t" << to_string(ID) << "\t" << Corner1.x << "\t" << Corner1.y << "\t"
		<< Corner2.x << "\t" << Corner2.y << "\t"
		<< Corner3.x << "\t" << Corner3.y << "\t"
		<< ClrToStr(FigGfxInfo.DrawClr) << "\t" << (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}

void CTriangle::Move(Point p)
{
	Point centroid;
	centroid.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centroid.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	Point relative[3];
	relative[0].x = Corner1.x - centroid.x;
	relative[1].x = Corner2.x - centroid.x;
	relative[2].x = Corner3.x - centroid.x;
	relative[0].y = Corner1.y - centroid.y;
	relative[1].y = Corner2.y - centroid.y;
	relative[2].y = Corner3.y - centroid.y;

	Corner1.x = relative[0].x + p.x;
	Corner2.x = relative[1].x + p.x;
	Corner3.x = relative[2].x + p.x;
	Corner1.y = relative[0].y + p.y;
	Corner2.y = relative[1].y + p.y;
	Corner3.y = relative[2].y + p.y;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTria to draw a triangle on the screen	
	pOut->DrawTria(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

CFigure* CTriangle::copy()
{
	return new CTriangle(*this);
}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The selected figure is a TRIANGLE, ID: " + to_string(ID) + "\t \t \t  P1(" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ")\t \t \t P2("
		+ to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")\t \t \t P3("
		+ to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")\t \t \t Draw Color: "
		+ ClrToStr(FigGfxInfo.DrawClr) + "\t \t \t Fill Color: " + (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL"));
}


int CTriangle::type()
{
	return 4;
}

 Point CTriangle::GetCenter()
 {
	 Point p;
	 p.x = (Corner1.x + Corner2.x + Corner3.x) / 3.0;
	 p.y = (Corner1.y + Corner2.y + Corner3.y) / 3.0;
	 return p;
 }