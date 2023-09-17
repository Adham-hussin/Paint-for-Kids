#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	static int unique;
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	int GetId();
	void SetId(int);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	//int getID();
	virtual void Draw(Output* pOut) const  = 0 ;//Draw the figure
	float area(float x1, float x2, float x3, float y1, float y2, float y3);
	virtual bool IsIn(float ,float) = 0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	string ClrToStr(color);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual void Move(Point p) = 0;
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	color StrToClr(string str);

	virtual CFigure* copy() = 0;

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	color getFillColor();
	color getDrawColor();

	void ChngIsFilled(bool b);
	bool GetIsFilled();

	virtual int type() = 0;
	virtual void PrintInfo(Output* pOut) = 0;

	virtual Point GetCenter() = 0;
};

#endif