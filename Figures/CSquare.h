#ifndef CSQU_H
#define CSQU_H
#include "CFigure.h"
class CSquare :
	public CFigure
{
private:
	Point center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Load(ifstream& Infile);
	bool IsIn(float, float);
	virtual void Save(ofstream& OutFile);
	virtual void Move(Point p);
	virtual void Draw(Output* pOut) const;
	CFigure* copy();
	virtual void PrintInfo(Output* pOut);
	virtual int type();
	Point GetCenter();
};

#endif
