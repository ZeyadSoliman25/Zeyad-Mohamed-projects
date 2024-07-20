#pragma once
#include "../ApplicationManager.h"
#include "Action.h"


class Paste : public Action
{
private:
	Statement* pPasteStatment;
	Point PointOfPaste;

public:
	Paste(ApplicationManager* pAppManager);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};
