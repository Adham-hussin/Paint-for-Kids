#include "PlayMode.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "Save.h"
PlayMode::PlayMode(ApplicationManager* app) : Action(app)
{

}

void PlayMode::ReadActionParameters()
{
    

}

void PlayMode::Execute(bool readparams)
{
	Save s(pManager, true);
	s.Execute();
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}

void PlayMode::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/plymode.wav")), NULL, SND_SYNC);
}