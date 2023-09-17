#ifndef CHEXA_H
#define CHEXA_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point center;	
public:
	CHexagon(Point , GfxInfo FigureGfxInfo );
	CHexagon();
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