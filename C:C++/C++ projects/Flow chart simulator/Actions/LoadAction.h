#pragma once
#include "Action.h"
#include <fstream>

class LoadAction : public Action
{
	private:
		string FileName;
		ifstream InFile;

	public:
		LoadAction(ApplicationManager* pAppManager);

		//Read parameters
		virtual void ReadActionParameters();

		//Create the new file with the info of statements
		virtual void Execute();
	};

