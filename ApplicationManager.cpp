#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquAction.h"
#include "Actions\AddTriaAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCirAction.h"
#include "Actions\Select.h"
#include "Actions\Delete.h"
#include "Actions\Move.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\ChngFillColor.h"
#include "Actions\ChngDrawColor.h"
#include "Actions\PickColor.h"
#include "Actions\ClearAll.h"
#include "Actions\PlayMode.h"
#include "Actions\Sound.h"
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "Figures\CSquare.h"
#include "Figures\CCircle.h"
#include "Figures\CHexagon.h"
#include "Figures\CTriangle.h"
#include <cstdlib>
#include <time.h>
#include "Actions\PickByFigType.h"
#include "Actions\PickByFillColor.h"
#include "Actions\PickByBoth.h"
#include "Actions\StartRec.h"
#include "Actions\StopRec.h"
#include "Actions\PlayRec.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"
#include <Windows.h>
#include "MMsystem.h"
#include "Actions\DrawMode.h"
#include "Actions\Exit.h"
#include <fstream>
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and outpute
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
	RecCount = 0;
	UndoCount = 0;
	UndoIndex = 0;
	beginning = true;
	recording = false;
	playingrec = false;
	recorded = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriaAction(this);
		break;
	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCirAction(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case LOAD:
		pAct = new Load(this);
		break;
	case MOVE:
		pAct = new Move(this);
		break;
	case FILL_CLR:
		pAct = new ChngFillColor(this);
		break;
	case DRW_CLR:
		pAct = new ChngDrawColor(this);
		break;
	case BLK:
		pAct = new PickColor(this, BLACK);
		break;
	case YEL:
		pAct = new PickColor(this, YELLOW);
		break;
	case ORG:
		pAct = new PickColor(this, ORANGE);
		break;
	case GRN:
		pAct = new PickColor(this, GREEN);
		break;
	case RD:
		pAct = new PickColor(this, RED);
		break;
	case BLU:
		pAct = new PickColor(this, BLUE);
		break;
	case CLEAR:
		pAct = new ClearAll(this);
		break;
	case TO_PLAY:
		pAct = new PlayMode(this);
		break;
	case PICK_FIG_TYPE:
		pAct = new PickByFigType(this);
		break;
	case PICK_FIG_FILL:
		pAct = new PickByFillColor(this);
		break;
	case PICK_FIG_TYPE_FILL:
		pAct = new PickByBoth(this);
		break;
	case REC:
		pAct = new StartRec(this);
		break;
	case REC_STOP:
		pAct = new StopRec(this);
		break;
	case REC_PLAY:
		pAct = new PlayRec(this);
		break;
	case UNDO:
		pAct = new UndoAction(this);
		break;
	case REDO:
		pAct = new RedoAction(this);
		break;
	case SOUND:
		pAct = new Sound(this);
		break;
	case TO_DRAW:
		pAct = new DrawMode(this);
		break;
	case EXIT:
		///create ExitAction here
		pAct = new Exit(this);
		break;	

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if(pAct != NULL)
	{
		pAct->sound(UI.sound);
		pAct->Execute();//Execute
		//delete pAct;	//You may need to change this line depending to your implementation
		LastAction = pAct;
		pAct = NULL;
	}
}
void ApplicationManager::SaveAll(ofstream& save)
{
	save << FigCount << endl
		<< ClrToStr(UI.DrawColor) << "\t" << ClrToStr(UI.FillColor) << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(save);
	save.close();
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->IsIn(x, y))
		{	
			if (!(FigList[i]->IsSelected()) && SelectedFig != NULL)
			{
				SelectedFig->SetSelected(0);
			}
			return FigList[i];
		}
		//Add your code here to search for a figure given a point x,y	
		//Remember that ApplicationManager only calls functions do NOT implement it.

		return NULL;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
	{
		if (FigList[i] != NULL)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	ClearUndoList();
	ClearRecList();
	delete pIn;
	delete pOut;

}


void ApplicationManager::Setselectedfig(CFigure* fig)
{
	SelectedFig = fig;
}

CFigure* ApplicationManager::getselectedfig()
{
	return SelectedFig;
}

string ApplicationManager::ClrToStr(color clr)
{
	if (clr == BLACK)
		return "BLACK";
	else if (clr == YELLOW)
		return "YELLOW";
	else if (clr == ORANGE)
		return "ORANGE";
	else if (clr == GREEN)
		return "GREEN";
	else if (clr == RED)
		return "RED";
	else if (clr == BLUE)
		return "BLUE";
}

color ApplicationManager::StrToClr(string str)
{
	if (str == "BLACK")
		return BLACK;
	else if (str == "YELLOW")
		return YELLOW;
	else if (str == "ORANGE")
		return ORANGE;
	else if (str == "GREEN")
		return GREEN;
	else if (str == "RED")
		return RED;
	else if (str == "BLUE")
		return BLUE;
}

void ApplicationManager::DeleteFig(bool selected, CFigure* c, bool biggestID)
{
	if (selected)
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (SelectedFig == FigList[i])
			{
				delete FigList[i];
				SelectedFig = NULL;
				for (int j = i; j < FigCount - 1; j++)
					FigList[j] = FigList[j + 1];
				FigCount--;
				break;
			}
		}
	}
	else if (biggestID)
	{
		int maxID = 0;
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i] -> GetId() > maxID)
				maxID = FigList[i] -> GetId();
		}
		for (int i = 0; i < FigCount; i++)
		{
			if (FigList[i] -> GetId() == maxID)
			{
				delete FigList[i];
				for (int j = i; j < FigCount - 1; j++)
					FigList[j] = FigList[j + 1];
				FigCount--;
				break;
			}
		}
	}
	else if (c)
	{
		for (int i = 0; i < FigCount; i++)
		{
			if (c -> GetId() == FigList[i] -> GetId())
			{
				delete FigList[i];
				for (int j = i; j < FigCount - 1; j++)
					FigList[j] = FigList[j + 1];
				FigCount--;
				break;
			}
		}
	}
}


void ApplicationManager::ClearAllFigs()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	SelectedFig = NULL;
	FigCount = 0;
	LastAction = NULL;
}


void ApplicationManager::picktypes(int &n1, int &n2, int &n3, int &n4, int &n5)
{
	n1 = n2 = n3 = n4 = n5 = 0;
	CFigure* c = NULL;
	for (int i = 0; i <FigCount ; i++)
	{
		if(c = dynamic_cast <CRectangle*> (FigList[i]))
			n1++;
		else if(c = dynamic_cast <CSquare*> (FigList[i]))
			n2++;
		else if(c = dynamic_cast <CCircle*> (FigList[i]))
			n3++;
		else if(c = dynamic_cast <CHexagon*> (FigList[i]))
			n4++;
		else if(c = dynamic_cast <CTriangle*> (FigList[i]))
			n5++;
	}
}

int ApplicationManager::getrandom()
{
	srand(time(0));
	int n = FigCount;
	if (n == 0) 
		return -1;
	int ran = rand() % n;
	return ran;
}


Action* ApplicationManager::GetLastAction()
{
	return LastAction;
}

void ApplicationManager::AddRecAction(Action* pRecAct)
{
	if (RecCount < MaxRecCount)
	{
		RecList[RecCount++] = pRecAct;
	}
	else
	{
		recording = false;
	}
}

void ApplicationManager::ClearRecList()
{
	for (int i = 0; i < RecCount; i++)
	{
		delete RecList[i];
		RecList[i] = NULL;
	}
	RecCount = 0;
}


void ApplicationManager::ClearUndoList()
{
	for (int i = 0; i < UndoCount; i++)
	{
		//delete UndoList[i];
		UndoList[i] = NULL;
	}
	UndoCount = 0;
	UndoIndex = 0;
}

bool ApplicationManager::Getrecording()
{
	return recording;
}

void ApplicationManager::Setrecording(bool b)
{
	recording = b;
}

bool ApplicationManager::Getplayingrec()
{
	return playingrec;
}

void ApplicationManager::Setplayingrec(bool b)
{
	playingrec = b;
}

bool ApplicationManager::Getbeginning()
{
	return beginning;
}

void ApplicationManager::Setbeginning(bool b)
{
	beginning = b;
}

void ApplicationManager::Setrecorded(bool b)
{
	recorded = b;
}

bool ApplicationManager::getrecorded()
{
	return recorded;
}

void ApplicationManager::PlayRecording()
{
	if (RecCount > 0)
	{
		UpdateInterface();
		recording = false;
		for (int i = 0; i < RecCount; i++)
		{
			RecList[i] -> Execute(false);
			Sleep(1000);
			UpdateInterface();
		}
	}
}

void ApplicationManager::AddUndoAction(Action* pRecAct)
{
	if (UndoIndex < UndoCount)
	{
		UndoCount = UndoIndex;
	}
	if (UndoCount < MaxUndoCount)
	{
		UndoList[UndoCount++] = pRecAct;
		UndoIndex++;
	}
	else
	{
		if (!recording && !playingrec)
			delete UndoList[0];
		for (int i = 0; i < MaxUndoCount - 1; i++)
		{
			UndoList[i] = UndoList[i + 1];
		}
		UndoList[MaxUndoCount - 1] = pRecAct;
	}

}

void ApplicationManager::Undo()
{
	if (UndoIndex > 0)
	{
		UndoList[UndoIndex - 1] -> Undo();
		UndoIndex--;
	}
}

void ApplicationManager::Redo()
{
	if (UndoIndex < UndoCount)
	{
		UndoList[UndoIndex] -> Redo();
		UndoIndex++;
	}
}

CFigure *ApplicationManager::GetFigTypeifcolored()
{
	bool found = false;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetIsFilled())
		{
			found = true;
			break;
		}
	}
	int a = getrandom();
	if(a == -1)
		return NULL;
	if (found)
	{
		while (FigList[a]->GetIsFilled() == false)
		{
			a = getrandom();
		}
		return FigList[a];
	}
	else return NULL;
}

int ApplicationManager::getrndcnt(CFigure* c)
{
	int cnt = 0;
	if(c)//counts the number of colored figure 
	{
		color r = c->getFillColor();
		for (int i = 0; i < FigCount; i++)
		{
			if(FigList[i]->getFillColor() == r && FigList[i]->GetIsFilled())
				cnt++;
		}
		return cnt;
	}
	return 0;
}

int ApplicationManager::getrndbothcnt(CFigure* c)
{
	if(c )//counts the number of the colored fig and its type
	{
		int cnt = 0;
		color r = c->getFillColor();
		int t = c->type();
		for (int i = 0; i < FigCount; i++)
		{
			if(FigList[i]->getFillColor() == r && FigList[i]->GetIsFilled() && FigList[i]->type() == t)
				cnt++;
		}
		return cnt;
	}
	return 0;
}

string ApplicationManager::TypeToStr(CFigure* s)
{
	if (dynamic_cast<CRectangle*>(s))
		return "Rectangles";
	else if (dynamic_cast<CSquare*>(s))
		return "Squares";
	else if (dynamic_cast<CCircle*>(s))
		return "Circles";
	else if (dynamic_cast<CHexagon*>(s))
		return "Hexagons";
	else if (dynamic_cast<CTriangle*>(s))
		return "Triangles";
}

void ApplicationManager::replace(CFigure* c)
{
	for (int i = 0; i < FigCount; i++)
		{
			if (c -> GetId() == FigList[i] -> GetId())
			{
				delete FigList[i];
				FigList[i] = c -> copy();
			}
		}
}