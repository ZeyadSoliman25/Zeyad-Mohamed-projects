#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "Actions\AddOperatorAssign.h"
#include "Actions\AddVariableAssign.h"
#include "Actions\AddCondition.h"
#include "Actions\AddStart.h"
#include "Actions\AddEnd.h"
#include "Actions\AddRead.h"
#include "Actions\AddWrite.h"
#include "Actions\AddConnector.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions/Copy.h"
#include "Actions/Paste.h"
#include "Actions/Delete.h"
#include "Actions/SelectAction.h"
#include "Actions/ValidateAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_START:
			///create AddStart Action here
			pAct = new AddStart(this);
			break; 

		case ADD_END:
			///create AddEnd Action here
			pAct = new AddEnd(this);
			break; 

		case ADD_VAR_ASSIGN:
			///create AddVariableAssign Action here
			pAct = new AddVariableAssign(this);
			break;

		case ADD_OPER_ASSIGN:
			///create AddOperatorAssign Action here
			pAct = new AddOperatorAssign(this);
			break;

		case ADD_VALUE_ASSIGN:
			///create AddValueAssign Action here
			pAct = new AddValueAssign(this);
			break;

		case ADD_CONDITION:
			///create AddCondition Action here
			pAct = new AddCondition(this);
			break; 
	
		case ADD_READ:
			///create AddRead Action here
			pAct = new AddRead(this);
			break;

		case ADD_WRITE:
			///create AddWrite Action here
			pAct = new AddWrite(this);
			break;
			
		case ADD_CONNECTOR:
			///create AddConnector Action here
			pAct = new AddConnector(this);
			break; 

		case SELECT:
			///create Select Action here
			pAct = new SelectAction(this);
			break;

		case EXIT:
			///create Exit Action here
			
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case COPY:
			pAct = new Copy(this); 
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case SWITCH_SIM_MODE:
			pOut->CreateSimulationToolBar();
			break;

		case SWITCH_DSN_MODE:
			pOut->CreateDesignToolBar();
			break;
		
		case VALIDATE:
			pAct = new ValidateAction(this);
			break;

		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if (StatCount < MaxCount)
	{
		pStat->SetID(StatCount);
		StatList[StatCount++] = pStat;
	}

	
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i]->IsStatement(P))
		{
			return StatList[i];
		}
	}

	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
//set the number of statements during load flowcharts
void ApplicationManager::SetStatCount(int count)
{
	StatCount = count;
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::GetStatDeleted(int id)
{
	StatList[id] = StatList[StatCount-1];
	StatCount--;

	for (int i = 0; i < StatCount; i++)
	{
		StatList[i]->SetID(i);
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement *ApplicationManager::GetClipboard() const
{	return pClipboard;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Save all the statements and connectors 
void ApplicationManager::SaveAll(ofstream& OutFile)
{
	OutFile << StatCount << endl;

	for (int i = 0; i < StatCount; i++)
	{
		StatList[i]->Save(OutFile);
	}
}

///////////////////////////////////////////////////////////////////////////////////
//Load all the stat
void ApplicationManager::LoadAll(ifstream& InFile)
{
	
	for (int i = 0; i < StatCount; i++)
	{
		StatList[i]->Load(InFile);
	}
}

////////////////////////////////////////////////////////////////////////////////////
bool ApplicationManager::ValidateALL()
{
	for (int i = 0; i < StatCount; i++)
	{
		if (!(StatList[i]->IsValid()))
		{
			return false;
		}
	}
	return true;
}

//==================================================================================//
//						Connectors Management Functions								//
//==================================================================================//

//Add connector to the list of connectors
void ApplicationManager:: Addconnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
}

/////////////////////////////////////////////////////////////////////////////////////

//search for a Connector where point P belongs
Connector* ApplicationManager:: Getconnector(Point P) const
{

	return NULL;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
