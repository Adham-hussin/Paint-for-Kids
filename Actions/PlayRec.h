#ifndef PLAY_REC_H
#define PLAY_REC_H

#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"

class PlayRec : public Action
{
private:
    
public:
    PlayRec(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};

#endif