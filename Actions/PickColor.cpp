#include "PickColor.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickColor::PickColor(ApplicationManager * pApp, color C):Action(pApp)
{
	c = C;
}

void PickColor::ReadActionParameters() 
{	

}

//Execute the action
void PickColor::Execute(bool readparams) 
{
	selected = pManager -> getselectedfig();
	if (pManager->getselectedfig() != NULL)
		before = pManager -> getselectedfig() -> copy();
	if (UI.choose == 1)
	{
		UI.isfilled = 1;
		UI.FillColor = c;
		if(pManager->getselectedfig() != NULL)
			pManager->getselectedfig()->ChngFillClr(UI.FillColor);
	}
	else if (UI.choose == 2)
	{
		UI.DrawColor = c;
		if(pManager->getselectedfig() != NULL)
			pManager->getselectedfig()->ChngDrawClr(UI.DrawColor);
	}
	UI.choose = 0;

	if (pManager->getselectedfig() != NULL)
		after = pManager -> getselectedfig() -> copy();

	pManager -> Setbeginning(false);

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
}

void PickColor::Undo()
{
	pManager -> replace(before);
}

void PickColor::Redo()
{
	pManager -> replace(after);
}


void PickColor::sound(bool on)
{

	if (on)
	{
		if(c == BLACK)
			PlaySound(TEXT(("Sounds/black.wav")), NULL, SND_SYNC);
		else if(c == YELLOW)
			PlaySound(TEXT(("Sounds/yellow.wav")), NULL, SND_SYNC);
		else if(c == ORANGE)
			PlaySound(TEXT(("Sounds/orange.wav")), NULL, SND_SYNC);
		else if(c == GREEN)
			PlaySound(TEXT(("Sounds/green.wav")), NULL, SND_SYNC);
		else if(c == RED)
			PlaySound(TEXT(("Sounds/red.wav")), NULL, SND_SYNC);
		else if(c == BLUE)
			PlaySound(TEXT(("Sounds/blue.wav")), NULL, SND_SYNC);
	}
}