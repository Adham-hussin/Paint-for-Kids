#ifndef ADD_TRIA_ACTION_H
#define ADDR_TRIA_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"
//Add triangle Action class
class AddTriaAction: public Action
{
private:
	Point P1, P2, P3; //triangle Corners
	GfxInfo TriaGfxInfo;
	CFigure* c;
public:
	AddTriaAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();
	
	//Add triangle to the ApplicationManager
	void Execute(bool readparams = true);
	void Undo();
	void Redo();
	Action* copy(){return new AddTriaAction(*this);}
	~AddTriaAction();
	virtual void sound(bool);
};

#endif