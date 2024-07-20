#pragma once
#include "Action.h"
#include "../Connector.h"


class AddConnector : public Action
{
private:
	// in the data members of the actions
	// we put the paramaters of the action
	// to be set in ReadActionParameters() then used in Execute()

	Point Position_1;	//Position where the user clicks to select source statement.
	Point Position_2;	//Position where the user clicks to select destination statement


public:
	AddConnector(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

