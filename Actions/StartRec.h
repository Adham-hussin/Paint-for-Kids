#ifndef START_REC_H
#define START_REC_H

#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"

class StartRec : public Action
{
private:
    
public:
    StartRec(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);
	virtual void sound(bool);
};

#endif