#include "Select.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include <string>
Select::Select(ApplicationManager* app) : Action(app)
{
    
}

void Select::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    pIn->GetPointClicked(P1.x, P1.y);
    
}

void Select::Execute(bool readparams)
{
    if (readparams)
		ReadActionParameters();
    Output* pOut = pManager->GetOutput();
    CFigure* selected_fig = pManager->GetFigure(P1.x,P1.y);
    if (selected_fig != NULL)
    {
        if (selected_fig->IsSelected())
		{
            selected_fig->SetSelected(false);
			pOut->ClearStatusBar();
		}
        else
		{
            selected_fig->SetSelected(true);
			selected_fig->PrintInfo(pOut);
		}
        pManager->Setselectedfig(selected_fig);
		
    }

	if (pManager -> Getrecording())
		pManager -> AddRecAction(this -> copy());

	pManager -> Setbeginning(false);
}

void Select::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/select.wav")), NULL, SND_SYNC);
}