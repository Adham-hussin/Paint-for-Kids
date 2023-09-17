#include "DrawMode.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "Save.h"
#include "Load.h"
DrawMode::DrawMode(ApplicationManager* app) : Action(app)
{

}

void DrawMode::ReadActionParameters()
{
    

}

void DrawMode::Execute(bool readparams)
{
	Load l(pManager, 1);
	l.Execute();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
}

void DrawMode::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/drwmode.wav")), NULL, SND_SYNC);
}