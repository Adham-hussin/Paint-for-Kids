#ifndef STOP_REC_H
#define STOP_REC_H

#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"

class StopRec : public Action
{
private:
    
public:
    StopRec(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};

#endif