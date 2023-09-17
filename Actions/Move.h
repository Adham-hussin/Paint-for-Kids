#ifndef MOVE_H
#define MOVE_H
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Figures/CFigure.h"
class Move : public Action
{
private:
    Point Pafter;
	Point Pbefore;
	CFigure * selected;
public:
    Move(ApplicationManager*);
    void ReadActionParameters();
    void Execute(bool readparams = true);

	void Undo();
	void Redo();
	Action* copy(){return new Move(*this);}
	virtual void sound(bool);
};
#endif