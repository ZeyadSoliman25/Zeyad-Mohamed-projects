#include "AddVariableAssign.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;


//constructor: set the ApplicationManager pointer inside this action
AddVariableAssign::AddVariableAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}


void AddVariableAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Enter LHS (variable name)");

	LHS = pIn->GetVariable(pOut);

	//TODO: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Enter RHS (Variable name)");

	RHS = pIn->GetVariable(pOut);

	pOut->ClearStatusBar();

}


void AddVariableAssign::Execute()
{
	ReadActionParameters();


	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VariableAssign* pAssign = new VariableAssign(Corner, LHS, RHS);

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}