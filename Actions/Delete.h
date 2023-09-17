#pragma once
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class Delete : public Action
{
private:
    CFigure* c;
public:
    Delete(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	void Undo();
	void Redo();
	Action* copy(){return new Delete(*this);}
	virtual void sound(bool);

};
