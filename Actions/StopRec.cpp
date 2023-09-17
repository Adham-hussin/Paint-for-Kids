#include "StopRec.h"

StopRec::StopRec(ApplicationManager* app) : Action(app)
{

}

void StopRec::ReadActionParameters()
{

}

void StopRec::Execute(bool readparams)
{
	ReadActionParameters();
	if(pManager->Getrecording())
	{
		pManager -> Setrecording(false);
		pManager->Setrecorded(true);
	}

}

void StopRec::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/stoprec.wav")), NULL, SND_SYNC);
}