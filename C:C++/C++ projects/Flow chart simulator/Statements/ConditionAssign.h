#pragma once

#include "Statement.h"

class ConditionAssign : public Statement
{
	string LHS;	//Left Handside of the assignment (name of a variable)
	string CompOp; // comparison operator
	string RHS_VAR;	//Right Handside (variable)
	double RHS_VAL; //Right Handside (value)

	int RHS_type; //Type of the right hand side

	Connector* pOutConn_1;	//Condition Assignment Stat. has two Connectors to next statement
	Connector* pOutConn_2; 

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet_1;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector
	Point Outlet_2;

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	ConditionAssign(Point Lcorner, string LeftHS = "", string comp_op = "", string RightLHS = "", int RightHs_type = VARIABLE_OP);

	void setLHS(const string& L); // setter for left hand side variable 
	void setRHS(const string& R, int righths_type); // setter for the right hand side value or variable
	void setCompOp(const string& comp); //setter for the comparison operator 

	virtual void Draw(Output* pOut) const;

	bool IsStatement(Point p);
	void SetLeftCorner(Point p);

	void Edit(string lefths, string comp_op, string righths, int righths_type);

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	virtual ConditionAssign* Clone();


	virtual Point GetInlet();
	virtual Point GetOutlet();

	virtual void SetOutConnector(Connector*&);

	void Simulate();

	virtual Connector* StatementConnector();

	virtual bool IsValid();

};

