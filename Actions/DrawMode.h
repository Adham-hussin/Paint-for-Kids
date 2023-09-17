#ifndef DRAW_MODE_H
#define DRAW_MODE_H
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class DrawMode : public Action
{
public:
    DrawMode(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};

#endif