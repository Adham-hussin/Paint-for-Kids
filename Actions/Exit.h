#ifndef EXIT_H
#define EXIT_H
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class Exit : public Action
{
public:
    Exit(ApplicationManager*);
    void ReadActionParameters();
    void Execute (bool readparams = true);
	virtual void sound(bool);
};

#endif