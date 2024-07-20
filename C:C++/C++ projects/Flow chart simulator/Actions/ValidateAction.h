#pragma once
#include "Action.h"

class ValidateAction : public Action
{
private:
	bool isValid;
public:
	ValidateAction(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

