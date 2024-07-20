#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

// Constructor
SelectAction::SelectAction(ApplicationManager* pAppmanager) : Action(pAppmanager)
{
}

// ReadActionParameters function
void SelectAction::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    //Read the (Position) parameter
    pOut->PrintMessage("Click to select Statement or Connector");
    // Code to read a statement or connector goes here
    pIn->GetPointClicked(Position);

    statement = pManager->GetStatement(Position);
	selectedstatement = pManager->GetSelectedStatement();

    pOut->ClearStatusBar();
 
}

// Execute function
void SelectAction::Execute()
{

    ReadActionParameters();

    if (statement)
    {
        if (statement->IsSelected())
        {
			statement->SetSelected(false);
        }
        else
        {
            statement->SetSelected(true);
        }

        if (selectedstatement != NULL)
        {
            selectedstatement->SetSelected(false);
            pManager->SetSelectedStatement(statement);
        }
        else
        {
            pManager->SetSelectedStatement(statement);
        }
    }
}
