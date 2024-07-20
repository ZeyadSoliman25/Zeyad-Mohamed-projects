#pragma once

#include "Statement.h"

class Start : public Statement
{
private:
	const string text = "Start"; // constant text to represent the start stat

	Connector* pOutConn;	//Value Assignment Stat. has one Connector to next statement

	Point Center;	//center of the statement block.

	Point Outlet;	//A point a connection leaves this statement

	virtual void UpdateStatementText() {};	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Start(Point center); // constructor only needs the center to draw the start stat


	virtual void Draw(Output* pOut) const;	//Draw the statement

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	bool IsStatement(Point p);
	void SetLeftCorner(Point p);

	virtual Start* Clone();

	virtual Point GetInlet() { return Outlet; };
	virtual Point GetOutlet();

	virtual void SetOutConnector(Connector*&);

	void Simulate();

	virtual Connector* StatementConnector();

	virtual bool IsValid();
};

