#include "PickByFigType.h"
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

PickByFigType::PickByFigType(ApplicationManager * pApp):Action(pApp)
{}

void PickByFigType::ReadActionParameters() 
{	

}

//Execute the action
void PickByFigType::Execute(bool readparams) 
{
	Load l(pManager, 1);
	l.Execute();
	pManager->UpdateInterface();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int corr , incorr;
	corr = incorr = 0;

	int n1, n2, n3, n4, n5;
	pManager->picktypes(n1, n2, n3, n4, n5);
	bool cont = true;
	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0)
	{
		pOut->PrintMessage("There are no figures");
		cont = false;
	}
	if (cont)

	{


		srand(time(0));
		int n = 5;
		int ran;

		bool done = false;

		while (done == false)
		{
			int count = 0;
			ran = rand() % n;
			if (n1 != 0 && ran == 0)
			{
				Point p;
				pOut->PrintMessage("pick all the rectangles");
				while (n1 != 0)
				{
					pIn->GetPointClicked(p.x, p.y);
					CFigure* c = pManager->GetFigure(p.x, p.y);
					if (dynamic_cast <CRectangle*> (c))
					{
						pManager->DeleteFig(false, c);
						corr++;
						c = NULL;
						n1--;
					}
					else if (c != NULL)
						incorr++;

					pManager->UpdateInterface();
				}
				done = true;
			}
			else if (n2 != 0 && ran == 1)
			{
				Point p;
				pOut->PrintMessage("pick all the squares");
				while (n2 != 0)
				{
					pIn->GetPointClicked(p.x, p.y);
					CFigure* c = pManager->GetFigure(p.x, p.y);
					if (dynamic_cast <CSquare*> (c))
					{
						pManager->DeleteFig(false, c);
						corr++;
						c = NULL;
						n2--;
					}
					else if (c != NULL)
						incorr++;

					pManager->UpdateInterface();

				}
				done = true;
			}
			else if (n3 != 0 && ran == 2)
			{
				Point p;
				pOut->PrintMessage("pick all the circles");
				while (n3 != 0)
				{
					pIn->GetPointClicked(p.x, p.y);
					CFigure* c = pManager->GetFigure(p.x, p.y);
					if (dynamic_cast <CCircle*> (c))
					{
						pManager->DeleteFig(false, c);
						corr++;
						c = NULL;
						n3--;
					}
					else if (c != NULL)
						incorr++;
					pManager->UpdateInterface();
				}
				done = true;
			}
			else if (n4 != 0 && ran == 3)
			{
				Point p;
				pOut->PrintMessage("pick all the hexagons");
				while (n4 != 0)
				{
					pIn->GetPointClicked(p.x, p.y);
					CFigure* c = pManager->GetFigure(p.x, p.y);
					if (dynamic_cast <CHexagon*> (c))
					{
						pManager->DeleteFig(false, c);
						corr++;
						c = NULL;
						n4--;
					}
					else if (c != NULL)
						incorr++;
					pManager->UpdateInterface();
				}
				done = true;
			}
			else if (n5 != 0 && ran == 4)
			{
				Point p;
				pOut->PrintMessage("pick all the triangles");
				while (n5 != 0)
				{
					pIn->GetPointClicked(p.x, p.y);
					CFigure* c = pManager->GetFigure(p.x, p.y);
					if (dynamic_cast <CTriangle*> (c))
					{
						pManager->DeleteFig(false, c);
						corr++;
						c = NULL;
						n5--;
					}
					else if (c != NULL)
						incorr++;
					pManager->UpdateInterface();
				}
				done = true;
			}
		}//for the bool while
		pOut->PrintMessage("correct picks = " + to_string(corr) + " , and the incorrect picks = " + to_string(incorr));
	}
}

void PickByFigType::sound(bool on)
{
	if (on)
		PlaySound(TEXT(("Sounds/picktype.wav")), NULL, SND_SYNC);
}
