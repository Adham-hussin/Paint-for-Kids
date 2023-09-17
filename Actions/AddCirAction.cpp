#include "AddCirAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCirAction::AddCirAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCirAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CirGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CirGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CirGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCirAction::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();

	//Create a circle with the parameters read from the user
	c = new CCircle(P1, P2, CirGfxInfo);
	//Add the circle to the list of figures
	pManager -> AddFigure(c->copy());

	pManager -> Setbeginning(false);

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
}

void AddCirAction::Undo()
{
	pManager -> DeleteFig(false,NULL,true);
}

void AddCirAction::Redo()
{
	pManager -> AddFigure(c -> copy());
}

AddCirAction::~AddCirAction()
{
	delete c;
}

void AddCirAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/circle.wav")), NULL, SND_SYNC);
}
