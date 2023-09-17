#pragma once
#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\Figures\CFigure.h"
class UndoAction : public Action
{
private:
  
public:
    UndoAction(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	int type() {return 1;}
	Action* copy(){return new UndoAction(*this);}
	virtual void sound(bool);
};