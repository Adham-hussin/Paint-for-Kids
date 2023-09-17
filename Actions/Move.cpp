#include "Move.h"

Move::Move(ApplicationManager* app) : Action(app)
{
}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please, choose a point to move the figure to it");
	pIn->GetPointClicked(Pafter.x, Pafter.y);
}

void Move::Execute(bool readparams)
{
	Output* pOut = pManager->GetOutput();
	if (readparams)
		ReadActionParameters();
	selected = pManager->getselectedfig();
	if(selected)
	{
		Pbefore = selected -> GetCenter();
		selected->Move(Pafter);
	}

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
	pOut->ClearStatusBar();
}

void Move::Undo()
{
	selected -> Move(Pbefore);
}

void Move::Redo()
{
	selected -> Move(Pafter);
}

void Move::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/move.wav")), NULL, SND_SYNC);
}
