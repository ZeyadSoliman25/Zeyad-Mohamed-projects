#pragma once

#include "Statement.h"
class Read : public Statement
{
	string Variable;	//variable of the write (name of a variable)

	Connector* pOutConn;	//Write Stat. has one Connector to next statement	

	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	Read(Point Lcorner, string variable = "");

	virtual void Draw(Output* pOut) const;

	void Edit(const string& L); // edit

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	bool IsStatement(Point p);
	void SetLeftCorner(Point p);

	virtual Read* Clone();

	virtual Point GetInlet();
	virtual Point GetOutlet();

	virtual void SetOutConnector(Connector*&);

	void Simulate();
	
	virtual Connector* StatementConnector();

	virtual bool IsValid();
};

