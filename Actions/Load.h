#ifndef LOAD_H
#define LOAD_H
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class Load : public Action
{
private:
	string name;
	bool b;
public:
	Load(ApplicationManager*, bool a = 0);
	void ReadActionParameters();
	void Execute(bool readparams = true);
	virtual void sound(bool);
};
#endif