#include "PlayRec.h"

PlayRec::PlayRec(ApplicationManager* app) : Action(app)
{
    
}

void PlayRec::ReadActionParameters()
{

}

void PlayRec::Execute(bool readparams)
{
	if(pManager->getrecorded())
	{
	pManager -> Setplayingrec(true);
	pManager -> ClearAllFigs();
	pManager ->	ClearUndoList();
	pManager -> PlayRecording();
	pManager -> Setplayingrec(false);
	}
}

void PlayRec::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/playrec.wav")), NULL, SND_SYNC);
}