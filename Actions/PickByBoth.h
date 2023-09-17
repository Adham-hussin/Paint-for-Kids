#ifndef PICK_BY_BOTH_H
#define PICK_BY_BOTH_H

#include "Action.h"


class PickByBoth: public Action
{
private:

public:
	PickByBoth(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute(bool readparams = true) ;
	virtual void sound(bool);
	
};

#endif