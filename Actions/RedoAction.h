#pragma once
#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\Figures\CFigure.h"
class RedoAction : public Action
{
private:
  
public:
    RedoAction(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	int type() {return 1;}
	Action* copy(){return new RedoAction(*this);}
	virtual void sound(bool);
};