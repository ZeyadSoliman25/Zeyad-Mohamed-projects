#include "LoadAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "../Statements/ValueAssign.h"
#include "../Statements/VariableAssign.h"
#include "../Statements/OperatorAssign.h"
#include "../Statements/ConditionAssign.h"
#include "../Statements/Start.h"
#include "../Statements/End.h"
#include "../Statements/Write.h"
#include "../Statements/Read.h"

LoadAction::LoadAction(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Enter file name to be loaded");

	FileName = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	string statcount;
	string statement_line;
	string statement;

	Statement* pStatement;

	Point default_point; //dummy point

	int StatCount = 0;

	ReadActionParameters();


	pManager->SetStatCount(StatCount);

	FileName += ".txt";

	InFile.open(FileName, ios::in);

	getline(InFile, statcount);

	StatCount = stoi(statcount);

	for (int i = 0; i < StatCount; i++)
	{
		getline(InFile, statement_line);
		statement = statement_line.substr(0, statement_line.find_first_of('\t') ) ;

		if (statement == "VariaAssign")
		{
			pStatement = new VariableAssign(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "ValueAssign")
		{
			pStatement = new ValueAssign(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "OperaAssign")
		{
			pStatement = new OperatorAssign(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "CondtAssign")
		{
			pStatement = new ConditionAssign(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "Start")
		{
			pStatement = new Start(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "End")
		{
			pStatement = new End(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "WriteAssign")
		{
			pStatement = new Write(default_point);
			pManager->AddStatement(pStatement);
		}
		else if (statement == "Read_Assign")
		{
			pStatement = new Read(default_point);
			pManager->AddStatement(pStatement);
		}
	}
	InFile.close();

	InFile.open(FileName, ios::in);
	getline(InFile, statement_line);

	pManager->LoadAll(InFile);

	InFile.close();
}