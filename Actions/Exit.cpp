#include "Exit.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "Save.h"
#include "Load.h"
Exit::Exit(ApplicationManager* app) : Action(app)
{

}

void Exit::ReadActionParameters()
{
}

void Exit::Execute(bool readparams)
{

	pManager->ClearAllFigs();
	delete pManager->GetInput();
	delete pManager->GetOutput();
}

void Exit::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/exit.wav")), NULL, SND_SYNC);
}