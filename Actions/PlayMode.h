#ifndef PLAY_MODE_H
#define PLAY_MODE_H
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class PlayMode : public Action
{
private:
public:
    PlayMode(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};

#endif