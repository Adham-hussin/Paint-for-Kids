#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo), Corner1(P1), Corner2(P2)
{

}

CRectangle::CRectangle()
{
}

void CRectangle::Load(ifstream& Infile)
{
	string drw, fil;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> drw >> fil;
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

bool CRectangle::IsIn(float x, float y)
{
	bool x_cond = abs(x - Corner1.x) <= abs(Corner1.x - Corner2.x) && abs(x - Corner2.x) <= abs(Corner1.x - Corner2.x);
	bool y_cond = abs(y - Corner1.y) <= abs(Corner1.y - Corner2.y) && abs(y - Corner2.y) <= abs(Corner1.y - Corner2.y);
	if (x_cond && y_cond)
		return true;
	return false;
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "RECT\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t"
		<< Corner2.x << "\t" << Corner2.y << "\t"
		<< ClrToStr(FigGfxInfo.DrawClr) << "\t" << (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL") << endl;
}

void CRectangle::Move(Point p)
{
	float l = abs(Corner1.x - Corner2.x);
	float w = abs(Corner1.y - Corner2.y);
	Corner1.x = p.x - l / 2;
	Corner1.y = p.y - w / 2;
	Corner2.x = p.x + l / 2;
	Corner2.y = p.y + w / 2;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

CFigure* CRectangle::copy()
{
	return new CRectangle(*this);
}

void CRectangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The selected figure is a RECTANGLE\t \t \t ID: " + to_string(ID) + "\t \t \t P1(" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ")\t \t \t P2("
		+ to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")\t \t \t Draw Color: "
		+ ClrToStr(FigGfxInfo.DrawClr) + "\t \t \t Fill Color: " + (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL"));
}

 int CRectangle::type()
 {
	 return 0;
 }

  Point CRectangle::GetCenter()
 {
	 Point p;
	 p.x = (Corner1.x + Corner2.x) / 2.0;
	 p.y = (Corner1.y + Corner2.y) / 2.0;
	 return p;
 }