#pragma once
#include "../ApplicationManager.h"
#include "Action.h"


class Delete : public Action
{
private:
	Statement* pDeleteStatment;
	Point PointOfDelete;

public:
	Delete(ApplicationManager* pAppManager);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};
