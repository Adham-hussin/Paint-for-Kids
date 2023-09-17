#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { MaxRecCount = 20 };
	enum { MaxUndoCount = 5 };
	

private:
	int FigCount;		//Actual number of figures
	int RecCount;       //Actual number of recorded operations
	int UndoCount;
	int UndoIndex;
	bool recording;
	bool recorded;
	bool playingrec;
	bool beginning;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	Action* LastAction;
	Action* RecList[MaxRecCount];
	Action* UndoList[MaxUndoCount];

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SaveAll(ofstream& save);
	void LoadAll(string name);
	void DeleteFig(bool = true, CFigure* = NULL, bool = false);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void AddRecAction(Action* pRecAct);
	void ClearUndoList();
	void AddUndoAction(Action* pRecAct);
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	// -- Interface Management Functions
	void Setrecorded(bool b);
	bool getrecorded();

	void Setselectedfig(CFigure*);
	CFigure* getselectedfig();

	string ClrToStr(color clr);

	color StrToClr(string str);
	
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void ClearAllFigs();
	void NewStart();
	void picktypes(int&, int&, int&, int&, int&);
	void ClearRecList();
	Action* GetLastAction();
	bool Getrecording();
	void Setrecording(bool b);

	bool Getplayingrec();
	void Setplayingrec(bool b);

	bool Getbeginning();
	void Setbeginning(bool b);

	void PlayRecording();

	void Undo();
	void Redo();

	int getrandom();
	CFigure* GetFigTypeifcolored();
	int getrndcnt(CFigure*);
	string TypeToStr(CFigure* s);
	int getrndbothcnt(CFigure*);

	void replace(CFigure*);
};

#endif