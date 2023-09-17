#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* app) : Action(app)
{

}

void RedoAction::ReadActionParameters()
{

}

void RedoAction::Execute(bool readparams)
{
	ReadActionParameters();
	if (pManager -> GetLastAction() -> type() == 1 || pManager -> Getplayingrec())
		pManager -> Redo();

	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());

	pManager -> Setbeginning(false);
}

void RedoAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/redo.wav")), NULL, SND_SYNC);
}