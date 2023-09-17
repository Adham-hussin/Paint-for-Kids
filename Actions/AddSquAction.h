#ifndef ADD_SQUA_ACTION_H
#define ADD_SQUA_ACTION_H
#include "Action.h"

class AddSquAction :
	public Action
{
private:
	Point center;
	GfxInfo SquGfxInfo;
	CFigure* c;
public:
	AddSquAction(ApplicationManager *pApp);
	//Reads square parameters
	virtual void ReadActionParameters();
	
	//Add square to the ApplicationManager
	void Execute(bool readparams = true);
	void Undo();
	void Redo();
	virtual void sound(bool);
	~AddSquAction();
	Action* copy(){return new AddSquAction(*this);}
};

#endif