#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	c =new CRectangle(P1, P2, RectGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(c ->copy());



	pManager -> Setbeginning(false);

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
}

void AddRectAction::Undo()
{
	pManager -> DeleteFig(false,NULL,true);
}

void AddRectAction::Redo()
{
	pManager -> AddFigure(c -> copy());
}

AddRectAction::~AddRectAction()
{
	delete c;
}

void AddRectAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/rectangle.wav")), NULL, SND_SYNC);
}