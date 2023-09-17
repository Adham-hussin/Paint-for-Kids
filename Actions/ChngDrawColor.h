#ifndef CHNG_DRAW_COLOR_H
#define CHNG_DRAW_COLOR_H

#include "Action.h"

//Add Rectangle Action class
class ChngDrawColor: public Action
{
private:

public:
	ChngDrawColor(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	void Execute(bool readparams = true);
	Action* copy(){return new ChngDrawColor(*this);}
	virtual void sound(bool);

};

#endif