#include "StartRec.h"

StartRec::StartRec(ApplicationManager* app) : Action(app)
{

}

void StartRec::ReadActionParameters()
{

}

void StartRec::Execute(bool readparams)
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (pManager -> Getbeginning() && !pManager->Getrecording())
	{
		pOut->PrintMessage("Recording started");
		pManager -> ClearRecList();
		pManager -> Setrecording(true);
	}
	else 
		pOut->PrintMessage("You are not allowed to record in this case!");
	pManager -> Setbeginning(false);
}

void StartRec::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/strtrec.wav")), NULL, SND_SYNC);
}