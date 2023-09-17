#ifndef CHNG_FILL_COLOR_H
#define CHNG_FILL_COLOR_H

#include "Action.h"

//Add Rectangle Action class
class ChngFillColor: public Action
{
private:

public:
	ChngFillColor(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	void Execute(bool readparams = true);
	Action* copy(){return new ChngFillColor(*this);}
	virtual void sound(bool);

};

#endif