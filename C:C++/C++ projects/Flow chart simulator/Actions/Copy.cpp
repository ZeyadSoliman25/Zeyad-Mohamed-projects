#include "Copy.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Statements/ValueAssign.h"
#include <sstream>

using namespace std;

// Constructor
Copy::Copy(ApplicationManager* pAppManager) : Action(pAppManager)
{
    // Initialize the copied statement pointer to null
    pCopyStatement = nullptr;
}

// Reads the parameters required for the copy action
void Copy::ReadActionParameters()
{
    // Get the input and output pointers
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    // Ask the user to select an item to be copied
    pOut->PrintMessage("Please Select an Item to be copied");

    // Get the selected statement
    pIn->GetPointClicked(SelectedStatement);

    // Get the statement from the manager
    pCopyStatement = pManager->GetStatement(SelectedStatement);
}



// Executes the copy action
void Copy::Execute()
{
    // Read the parameters
    ReadActionParameters();

    // Get the output pointer
    Output* pOut = pManager->GetOutput();

    // If pCopyStatement is not nullptr, proceed with the copy operation
    if (pCopyStatement != nullptr)
    {
        // Notify the user that the item has been copied
        pOut->PrintMessage("Item Copied");
        // Set the clipboard to the copied statement
        pManager->SetClipboard(pCopyStatement);
    }
    else
    {
        // Notify the user that the copy operation failed
        pOut->PrintMessage("Copy operation failed. No item selected.");
    }
}

