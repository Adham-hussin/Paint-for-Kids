#pragma once
#include "c:\users\eslam\onedrive\desktop\new folder\phase2 - code f22\actions\action.h"

class AddSquAction :
	public Action
{
private:
	Point center;
	GfxInfo RectGfxInfo;
public:
	AddSquAction(ApplicationManager *pApp);
	//Reads square parameters
	virtual void ReadActionParameters();
	
	//Add square to the ApplicationManager
	virtual void Execute() ;
	~AddSquAction(void);
};

