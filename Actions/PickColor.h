#ifndef PICK_COLOR_H
#define PICk_COLOR_H

#include "Action.h"

//Add Rectangle Action class
class PickColor: public Action
{
private:
	color c;
	CFigure* before;
	CFigure* after;
	CFigure* selected;

public:
	PickColor(ApplicationManager *pApp, color c);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	color getcolor();
	void Execute(bool readparams = true);
	void Undo();
	void Redo();
	Action* copy(){return new PickColor(*this);}
	virtual void sound(bool);
};

#endif