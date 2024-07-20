#include "ValidateAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;


ValidateAction::ValidateAction(ApplicationManager* pApp) :Action(pApp)
{}


void ValidateAction::ReadActionParameters()
{
	isValid = pManager->ValidateALL();
}


void ValidateAction::Execute()
{
	Output* pOutput = pManager->GetOutput();

	ReadActionParameters();

	if (isValid)
		pOutput->PrintMessage("Valid Chart");
	else 
		pOutput->PrintMessage("Invalid Chart");
}
