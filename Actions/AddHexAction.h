#pragma once
#include "Action.h"

class AddHexAction :
	public Action
{
private:
	Point center;
	GfxInfo HexGfxInfo;
	CFigure* c;
public:
	AddHexAction(ApplicationManager *pApp);
	//Reads hexagon parameters
	virtual void ReadActionParameters();
	
	//Add hexagon to the ApplicationManager
	void Execute(bool readparams = true);
	void Undo();
	void Redo();
	Action* copy(){return new AddHexAction(*this);}
	virtual ~AddHexAction();
	virtual void sound(bool);

};

