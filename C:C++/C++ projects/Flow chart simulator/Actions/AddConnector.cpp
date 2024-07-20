#include "AddConnector.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

AddConnector::AddConnector(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//Read the (Position) parameter
	pOut->PrintMessage("Click on Source statement");

	pIn->GetPointClicked(Position_1);
	pOut->ClearStatusBar();

	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Click on Destination statement");
	pIn->GetPointClicked(Position_2);
	pOut->ClearStatusBar();
}

void AddConnector::Execute()
{
	ReadActionParameters();

	Statement* srcStatement;
	Statement* destStatement;

	Connector* pConnector;

	srcStatement = pManager->GetStatement(Position_1);
	destStatement = pManager->GetStatement(Position_2);

	pConnector = new Connector(srcStatement, destStatement);

	pConnector->setStartPoint(srcStatement->GetOutlet());
	pConnector->setEndPoint(destStatement->GetInlet());

	srcStatement->SetOutConnector(pConnector);
	pManager->Addconnector(pConnector); // Adds the created connector to application manger's statement list
}