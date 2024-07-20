#pragma once
#include "Action.h"
#include "../Statements/ConditionAssign.h"

class AddCondition : public Action 
{
private:
	// in the data members of the actions
	// we put the paramaters of the action
	// to be set in ReadActionParameters() then used in Execute()

	Point Position;	//Position where the user clicks to add the stat.
	//TODO: you should add LHS and RHS of the assignment statement as parameters
	string LHS;

	string RHS;

	int RHS_type = INVALID_OP;

	string CompOp;



public:
	AddCondition(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

