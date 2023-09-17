#include "Load.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include <string>
#include "ClearAll.h"

#include<iostream>

Load::Load(ApplicationManager* app, bool a) : Action(app)
{
	b = a;
}

void Load::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (b == 0)
	{
		pOut->PrintMessage("Please, enter file name");
		name = pIn->GetSrting(pOut);
	}
	else 
		name = "saved";

}

void Load::Execute(bool readparams)
{
	ReadActionParameters();

	int c;
	string drw, fil, type;
	ifstream load(name+".txt", ios::in);

	if(load.is_open())
	{
		ClearAll clr(pManager);
		clr.Execute();
		load >> c;
		load >> drw >> fil;
		CFigure* loaded;
		UI.DrawColor = pManager->StrToClr(drw);
		UI.FillColor = pManager->StrToClr(fil);
		for (int i = 0; i < c; i++)
		{
			load >> type;
			if (type == "CIRC")
			{
				loaded = new CCircle;

			}
			else if(type == "HEX")
			{
				loaded = new CHexagon;
			}
			else if (type == "RECT")
			{
				loaded = new CRectangle;
			}
			else if (type == "SQR")
			{
				loaded = new CSquare;
			}
			else if (type == "TRI")
			{
				loaded = new CTriangle;
			}

			loaded->Load(load);
			pManager->AddFigure(loaded);
			pManager -> Setbeginning(false);
		}
		
	}
}


void Load::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/load.wav")), NULL, SND_SYNC);
}