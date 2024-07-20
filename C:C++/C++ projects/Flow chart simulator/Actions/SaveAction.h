#pragma once
#include "Action.h"
#include <fstream>

class SaveAction : public Action 
{
	private: 
		string FileName;
		ofstream OutFile;

	public: 
		SaveAction(ApplicationManager* pAppManager);

		//Read parameters
		virtual void ReadActionParameters();

		//Create the new file with the info of statements
		virtual void Execute();
};

