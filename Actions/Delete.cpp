#include "Delete.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
Delete::Delete(ApplicationManager* app) : Action(app)
{

}

void Delete::ReadActionParameters()
{


}

void Delete::Execute(bool readparams)
{
	if(pManager->getselectedfig())
	{
		c = pManager -> getselectedfig() -> copy();
		pManager->DeleteFig();
		pManager -> AddUndoAction(this);
		if (pManager -> Getrecording())
			pManager -> AddRecAction(this -> copy());
	}
}

void Delete::Undo()
{
	//if(pManager->getselectedfig())
	c->SetSelected(false);
	pManager -> AddFigure(c -> copy());
}

void Delete::Redo()
{
	pManager -> DeleteFig(false,c,false);
}

void Delete::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/delete.wav")), NULL, SND_SYNC);
}