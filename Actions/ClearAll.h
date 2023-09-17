#pragma once
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class ClearAll : public Action
{
public:
    ClearAll(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);

};
