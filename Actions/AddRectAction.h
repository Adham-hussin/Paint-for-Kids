#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* c;
public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	void Execute(bool readparams = true);
	void Undo();
	void Redo();
	Action* copy(){return new AddRectAction(*this);}
	virtual ~AddRectAction();
	virtual void sound(bool);

};

#endif