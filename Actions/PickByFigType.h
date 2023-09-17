#ifndef PICK_BY_FIG_TYPE_H
#define PICK_BY_FIG_TYPE_H

#include "Action.h"


class PickByFigType: public Action
{
public:
	PickByFigType(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute(bool readparams = true) ;
	virtual void sound(bool);
	
};

#endif