#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Load(ifstream& Infile);
	bool IsIn(float x, float y);
	virtual void Save(ofstream& OutFile);
	virtual void Move(Point p);
	virtual void Draw(Output* pOut) const;
	CFigure* copy();
	virtual void PrintInfo(Output* pOut);
	virtual int type();
	Point GetCenter();
};

#endif