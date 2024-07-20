#ifndef SELECTACTION_H
#define SELECTACTION_H

#include "Action.h" 
#include "..\Statements\Statement.h"
#include "..\Connector.h"

class SelectAction : public Action
{
private:
    Statement* statement;
	Statement* selectedstatement;
	Point Position; // Position of selected statement
public:
    // Constructor
    SelectAction(ApplicationManager* pAppManager);

    virtual void ReadActionParameters();

    // Overriding the execute function
    virtual void Execute();
};

#endif
