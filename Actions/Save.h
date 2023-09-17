#ifndef SAVE_H
#define SAVE_H
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class Save : public Action
{
private:
    string filename;
	bool b;
public:
    Save(ApplicationManager*, bool a = 0);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};
#endif