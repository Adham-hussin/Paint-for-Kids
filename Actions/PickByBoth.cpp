#include "PickByBoth.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include <time.h>
#include <stdlib.h>
#include <string>
#include "Save.h"
#include "Load.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickByBoth::PickByBoth(ApplicationManager* pApp) :Action(pApp)
{}

void PickByBoth::ReadActionParameters()
{

}

//Execute the action
void PickByBoth::Execute(bool readparams)
{
	Load l(pManager, 1);
	l.Execute();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	bool cont = true;
	CFigure* s = pManager->GetFigTypeifcolored();
	if(s == NULL)
	{
		pOut->PrintMessage("There are no colored figures");
		cont = false;
	}

	if(cont)
	{
		color c = s->getFillColor();
		int cnt = pManager->getrndbothcnt(s);
		Point p;

		pOut->PrintMessage("pick all the " + pManager->ClrToStr(c) + " " + pManager->TypeToStr(s));
		int corr, incorr;
		corr = incorr = 0;
		while (cnt != 0)
		{
			pIn->GetPointClicked(p.x, p.y);
			CFigure* c2 = pManager->GetFigure(p.x, p.y);
			if (c2 != NULL)
			{
				if (c2->getFillColor() == c && c2->type() == s->type())// how to compare these 2 objects
				{
					pManager->DeleteFig(false, c2);
					corr++;
					c2 = NULL;
					cnt--;
				}
				else
					incorr++;
				pManager->UpdateInterface();
			}
		}
		pOut->PrintMessage("correct picks = " + to_string(corr) + " , and the incorrect picks = " + to_string(incorr));

	}
}

void PickByBoth::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/picktypeclr.wav")), NULL, SND_SYNC);
}
