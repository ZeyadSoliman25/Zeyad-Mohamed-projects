#include "AddOperatorAssign.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddOperatorAssign::AddOperatorAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddOperatorAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Operator Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter LHS (variable name)");

	LHS = pIn->GetVariable(pOut);

	//TODO: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Enter First Operand");

	while (FirstOp_type == INVALID_OP)
	{
		FirstOp = pIn->GetString(pOut);
		FirstOp_type = ValueOrVariable(FirstOp);
	}

	pOut->PrintMessage("Enter Arithmatic Operator (*,/,+,-)");

	ArithOp = pIn->GetArithOperator(pOut);

	pOut->PrintMessage("Enter Second Operand");

	while (SecondOp_type == INVALID_OP)
	{
		SecondOp = pIn->GetString(pOut);
		SecondOp_type = ValueOrVariable(SecondOp);
	}

	pOut->ClearStatusBar();
}

void AddOperatorAssign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	OperatorAssign* pAssign = new OperatorAssign(Corner, LHS, ArithOp, FirstOp, SecondOp, FirstOp_type, SecondOp_type);
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}
