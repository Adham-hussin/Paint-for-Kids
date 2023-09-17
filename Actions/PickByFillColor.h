#ifndef PICK_BY_FILL_COLOR_H
#define PICK_BY_FILL_COLOR_H

#include "Action.h"


class PickByFillColor: public Action
{
private:

public:
	PickByFillColor(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute(bool readparams = true) ;
	virtual void sound(bool);
	
};

#endif