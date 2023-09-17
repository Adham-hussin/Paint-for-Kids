#ifndef CCIR_H
#define CCIR_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;	
	Point P2;
	float rad;
public:
	CCircle(Point , Point, GfxInfo FigureGfxInfo );
	CCircle();
	virtual void Load(ifstream& Infile);
	bool IsIn(float x, float y);
	virtual void Save(ofstream& OutFile);
	virtual void Move(Point p);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);
	virtual int type();
	CFigure* copy();
	Point GetCenter();
};

#endif