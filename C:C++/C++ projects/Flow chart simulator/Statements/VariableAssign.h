#pragma once
#include "Statement.h"

class VariableAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (name of a variable)

	Connector* pOutConn;	//Variable Assignment Stat. has one Connector to next statement

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	VariableAssign(Point Lcorner, string LeftHS = "", string RightHS = "");

	void setLHS(const string& L); // setter for the left hand side variable 
	void setRHS(const string& R); // setter for the right hand side variable

	virtual void Draw(Output* pOut) const;

	void Edit(string LeftHS, string RightHS);

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	bool IsStatement(Point p);
	void SetLeftCorner(Point p);

	virtual VariableAssign* Clone();

	virtual Point GetInlet();
	virtual Point GetOutlet();

	virtual void SetOutConnector(Connector*&);

	void Simulate();

	virtual Connector* StatementConnector();

	virtual bool IsValid();

};

