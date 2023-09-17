#include "Save.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include <string>
Save::Save(ApplicationManager* app, bool a) : Action(app)
{
	b = a;
}

void Save::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (b == 0)
	{
		pOut->PrintMessage("Please, enter file name");
		filename = pIn->GetSrting(pOut);
	}
	else
		filename = "saved";
}

void Save::Execute(bool readparams)
{
	if (readparams)
		ReadActionParameters();
	ofstream save;
	save.open(filename+".txt", ios::out);
	pManager->SaveAll(save);
	save.close();
}

void Save::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/save.wav")), NULL, SND_SYNC);
}