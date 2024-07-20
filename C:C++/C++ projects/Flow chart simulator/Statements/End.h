#pragma once
#include "Statement.h"


class End : public Statement
{
private:
	const string text = "End"; // constant text to represent the start stat

	Point Center;	//center of the statement block.

	Point Inlet;	//A point a connection enters this statement

	virtual void UpdateStatementText() {};	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	End(Point center); // constructor only needs the center to draw the start stat


	virtual void Draw(Output* pOut) const;	//Draw the statement

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	bool IsStatement(Point p);
	void SetLeftCorner(Point p);

	virtual End* Clone();

	virtual Point GetInlet();
	virtual Point GetOutlet() { return Inlet; };

	virtual void SetOutConnector(Connector*&) {};

	void Simulate();

	virtual Connector* StatementConnector();

	virtual bool IsValid();
};

