#include "SaveAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SaveAction::SaveAction(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void SaveAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Enter file name to be saved");

	FileName = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();

	FileName += ".txt";

	OutFile.open(FileName, ios::out);

	pManager->SaveAll(OutFile);

	OutFile.close();
}