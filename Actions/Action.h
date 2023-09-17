#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\Figures\CFigure.h"
#include <Windows.h>
#include "MMsystem.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
public:

	Action(ApplicationManager *pApp) { pManager = pApp;}	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() = 0;
	
	//Execute action (code depends on action type)
	virtual void Execute(bool readparams = true) = 0;
	virtual void Undo(){};
	virtual int type(){return 0;}
	virtual void Redo(){};
	virtual Action* copy(){return this;} 
	

	virtual void sound(bool on) = 0;


	virtual ~Action (){};
};

#endif