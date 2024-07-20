#include "AddCondition.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddCondition::AddCondition(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddCondition::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Condition Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter LHS (variable name)");

	LHS = pIn->GetVariable(pOut);

	//Getting the comparison operator from the user 
	pOut->PrintMessage("Enter valid comparison operator(>,<,>=,<=,==,!=");
	CompOp = pIn->GetCompOperator(pOut);

	//Getting the right hand side of the comparison operator
	pOut->PrintMessage("Enter RHS");

	while (RHS_type == INVALID_OP)
	{
		RHS = pIn->GetString(pOut);
		RHS_type = ValueOrVariable(RHS);
	}

	pOut->ClearStatusBar();
}

void AddCondition::Execute()
{
	ReadActionParameters();


	//Calculating left corner of Condition statement block
	Point Corner;
	Corner.x = Position.x;
	Corner.y = Position.y - UI.ASSGN_HI/2;

	ConditionAssign* pAssign = new ConditionAssign(Corner, LHS, CompOp ,RHS, RHS_type);

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}