#ifndef ADD_CIR_ACTION_H
#define ADD_CIR_ACTION_H

#include "Action.h"

//Add circle Action class
class AddCirAction: public Action
{
private:
	Point P1, P2; //Circle center and radius
	GfxInfo CirGfxInfo;
	CFigure* c;
public:
	AddCirAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	void Execute(bool readparams = true);
	void Undo();
	void Redo();

	Action* copy(){return new AddCirAction(*this);}
	virtual ~AddCirAction();
	virtual void sound(bool);
};

#endif