#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddHexAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center");

	//Read center and store in point center
	pIn->GetPointClicked(center.x, center.y);


	HexGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();

	//Create a square with the parameters read from the user
	c = new CHexagon(center, HexGfxInfo);
	//Add the square to the list of figures
	pManager->AddFigure(c->copy());

	pManager -> Setbeginning(false);

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
}

void AddHexAction::Undo()
{
	pManager -> DeleteFig(false,NULL,true);
}

void AddHexAction::Redo()
{
	pManager -> AddFigure(c -> copy());
}

AddHexAction::~AddHexAction()
{
	delete c;
}

void AddHexAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/hexagon.wav")), NULL, SND_SYNC);
}