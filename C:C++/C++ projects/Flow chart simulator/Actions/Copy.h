#pragma once
#include "../ApplicationManager.h"
#include "Action.h"
#include "../Statements/Start.h"
#include "../Statements/Statement.h"


class Copy : public Action
{
private:
	Statement* pCopyStatement;
	Point SelectedStatement;

public: 
	Copy(ApplicationManager* pAppManager);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};