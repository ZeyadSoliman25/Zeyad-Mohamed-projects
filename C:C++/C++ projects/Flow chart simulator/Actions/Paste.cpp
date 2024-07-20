#include "Paste.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

#include <sstream>
using namespace std;



// Constructor for the Paste class
Paste::Paste(ApplicationManager* pAppManager) : Action(pAppManager)
{
    // Initialize the statement to be pasted as null
    pPasteStatment = nullptr;
}

// Function to read the action parameters
void Paste::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Select a point in which statement will be copied");
    Input* pIn = pManager->GetInput();

    pIn->GetPointClicked(PointOfPaste);

    // Get the statement to be pasted from the clipboard
    pPasteStatment = pManager->GetClipboard();
}

// Function to execute the paste action
void Paste::Execute()
{
    ReadActionParameters();
    Output* pOut = pManager->GetOutput();

    // Check if there is a statement to paste
    if (pPasteStatment == nullptr)
    {
        pOut->PrintMessage("Error: No statement to paste");
        return;
    }

    else
    {
        Statement* pNewStatement = pPasteStatment->Clone();
        // Add the statement to be pasted to the manager
        pNewStatement->SetLeftCorner(PointOfPaste);
        pManager->AddStatement(pNewStatement);
        pOut->PrintMessage("Output Pasted");
    }
}