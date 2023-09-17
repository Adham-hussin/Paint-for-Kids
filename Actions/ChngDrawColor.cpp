#include "ChngDrawColor.h"
#include "..\Figures\CFigure.h"
#include "Select.h"
#include "PickColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngDrawColor::ChngDrawColor(ApplicationManager * pApp):Action(pApp)
{}

void ChngDrawColor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Pick a color to change the selected figure draw color to it");
}

//Execute the action
void ChngDrawColor::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();
	if(pManager->getselectedfig() != NULL && pManager->getselectedfig()->IsSelected())
	{
		UI.choose = 2;
	}
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
}

void ChngDrawColor::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/chngdrwclr.wav")), NULL, SND_SYNC);
}