#include "AddTriaAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriaAction::AddTriaAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriaAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriaGfxInfo.isFilled = UI.isfilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriaAction::Execute(bool readparams) 
{
	//This action needs to read some parameters first
	if (readparams)
		ReadActionParameters();

	//Create a triangle with the parameters read from the user
	c = new CTriangle(P1, P2, P3, TriaGfxInfo);
	//Add the triangle to the list of figures
	pManager->AddFigure(c->copy());

	pManager -> Setbeginning(false);

	pManager -> AddUndoAction(this);
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());
}

void AddTriaAction::Undo()
{
	pManager -> DeleteFig(false,NULL,true);
}

void AddTriaAction::Redo()
{
	pManager -> AddFigure(c -> copy());
}

AddTriaAction::~AddTriaAction()
{
	delete c;
}


void AddTriaAction::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/triangle.wav")), NULL, SND_SYNC);
}