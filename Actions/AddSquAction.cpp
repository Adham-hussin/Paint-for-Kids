#include "AddSquAction.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquAction::AddSquAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddSquAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(center.x, center.y);


	SquGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquAction::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();

	//Create a square with the parameters read from the user
	c = new CSquare(center, SquGfxInfo);
	//Add the square to the list of figures
	pManager->AddFigure(c->copy());


	pManager -> Setbeginning(false);

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
}

void AddSquAction::Undo()
{
	pManager -> DeleteFig(false,NULL,true);
}

void AddSquAction::Redo()
{
	pManager -> AddFigure(c -> copy());
}

AddSquAction::~AddSquAction()
{
	delete c;
}

void AddSquAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/square.wav")), NULL, SND_SYNC);
}