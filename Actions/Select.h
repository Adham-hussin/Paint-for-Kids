#pragma once
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class Select : public Action
{
private:
    Point P1;
public:
    Select(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	Action* copy(){return new Select(*this);}
	virtual void sound(bool);
};
