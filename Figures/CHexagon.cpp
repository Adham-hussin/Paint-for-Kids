#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P1;
}

CHexagon::CHexagon()
{
}

void CHexagon::Load(ifstream& Infile)
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

bool CHexagon::IsIn(float x, float y)
{
	float n = 100;
	float h = sqrt(n * n - (n / 2) * (n / 2));

	float AHex = 3 * sqrt(3) * n * n / 2;

	float A1 = area(x, center.x - n, center.x - n / 2, y, center.y, center.y - h);

	float A2 = area(x, center.x + n / 2, center.x - n / 2, y, center.y - h, center.y - h);
	
	float A3 = area(x, center.x + n / 2, center.x + n, y, center.y - h, center.y);
	
	float A4 = area(x, center.x + n / 2, center.x + n, y, center.y + h, center.y);
	
	float A5 = area(x, center.x - n / 2, center.x + n / 2, y, center.y + h, center.y + h);
	
	float A6 = area(x, center.x - n / 2, center.x - n, y, center.y + h, center.y);
	
	float Asum = A1 + A2 + A3 + A4 + A5 + A6;

	float error = abs(AHex - Asum);
	if (error < 1)
		return true;
	return false;
}

void CHexagon::Save(ofstream& OutFile)
{
	
	OutFile << "HEX\t" << ID << "\t" << center.x << "\t" << center.y << "\t"
			   << ClrToStr(FigGfxInfo.DrawClr) << "\t" << (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL") <<endl;
}
	
void CHexagon::Move(Point p)
{
	center = p;
}
void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexa to draw a hexagon on the screen	
	pOut->DrawHexa(center, FigGfxInfo, Selected);
}

CFigure* CHexagon::copy()
{
	return new CHexagon(*this);
}

void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("The selected figure is a HEXAGON, ID: " + to_string(ID) + "\t \t \t  P(" + to_string(center.x) + ", " + to_string(center.y)
		+ ")\t \t \t Draw Color: "
		+ ClrToStr(FigGfxInfo.DrawClr) + "\t \t \t Fill Color: " + (FigGfxInfo.isFilled ? ClrToStr(FigGfxInfo.FillClr) : "NO_FILL"));
}
 int CHexagon::type()
 {
	 return 3;
 }

  Point CHexagon::GetCenter()
 {
	 return center;
 }