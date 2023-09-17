#include "UndoAction.h"

UndoAction::UndoAction(ApplicationManager* app) : Action(app)
{

}

void UndoAction::ReadActionParameters()
{

}

void UndoAction::Execute(bool readparams)
{
	ReadActionParameters();
	pManager -> Undo();

	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());

	pManager -> Setbeginning(false);
}

void UndoAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/undo.wav")), NULL, SND_SYNC);
}