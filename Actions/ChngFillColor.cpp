#include "ChngFillColor.h"
#include "..\Figures\CFigure.h"
#include "Select.h"
#include "PickColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngFillColor::ChngFillColor(ApplicationManager * pApp):Action(pApp)
{}

void ChngFillColor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->getselectedfig() != NULL)
		pOut->PrintMessage("Pick a color to change the selected figure fill color to it");
}

//Execute the action
void ChngFillColor::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();
	if(pManager->getselectedfig() != NULL && pManager->getselectedfig()->IsSelected())
	{
		UI.choose = 1;
	}
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());

}


void ChngFillColor::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/chngfillclr.wav")), NULL, SND_SYNC);
}