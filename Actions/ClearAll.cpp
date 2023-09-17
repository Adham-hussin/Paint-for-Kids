#include "ClearAll.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
ClearAll::ClearAll(ApplicationManager* app) : Action(app)
{

}

void ClearAll::ReadActionParameters()
{


}

void ClearAll::Execute(bool readparams)
{
	pManager -> ClearAllFigs();
	pManager ->ClearUndoList();
	if(!pManager->Getrecording() && !pManager->Getplayingrec())
	{
		pManager->ClearRecList();
		pManager -> Setbeginning(true);
		pManager->Setrecorded(false);
	}
	UI.isfilled = 0;
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.choose = 0;
	UI.sound = 1;
	if (pManager -> Getrecording())
		pManager -> AddRecAction(this->copy());
}

void ClearAll::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/clear.wav")), NULL, SND_SYNC);
}