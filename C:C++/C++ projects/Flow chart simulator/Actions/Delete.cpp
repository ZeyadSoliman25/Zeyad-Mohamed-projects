
#include "Delete.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <sstream>

using namespace std;

// Constructor
Delete::Delete(ApplicationManager* pAppManager) : Action(pAppManager)
{
    pDeleteStatment = nullptr;
}


void Delete::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    pOut->PrintMessage("Please Select an Item to be deleted");

    pIn->GetPointClicked(PointOfDelete);

    pDeleteStatment = pManager->GetStatement(PointOfDelete);
}


void Delete::Execute()
{
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();
    string text;
    int statement_id = 0;

    if (pDeleteStatment != nullptr)
    {
        pOut->PrintMessage("Item deleted");

        statement_id = pDeleteStatment->GetID();   

        delete pDeleteStatment;
        pManager->GetStatDeleted(statement_id);
    }
    else
    {
        pOut->PrintMessage("Delete operation failed. No item selected.");
    }
}