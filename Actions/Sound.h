#ifndef SOUND_H
#define SOUND_H
#include "Action.h"
#include "../ApplicationManager.h"
class Sound :public Action
{
public:
    Sound(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};
#endif

