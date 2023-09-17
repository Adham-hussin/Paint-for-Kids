#ifndef CTRIA_H
#define CTRIA_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );
	CTriangle();
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