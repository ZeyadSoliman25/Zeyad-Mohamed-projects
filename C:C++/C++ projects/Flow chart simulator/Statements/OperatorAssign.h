#pragma once
#include "Statement.h"
#include "../HelperFn.h"

class OperatorAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string FirstOp_VAR;	//First operand (Variable)
	string ArithOp; //Arithmatic operator
	string SecondOp_VAR; //Second operand (variable)

	double FirstOp_VAL; //first operand (value)
	double SecondOp_VAL; //Second operand (value)

	int FirstOp_type; //first operand type to decide which data member will store the first operand 
	int SecondOp_type; //Second operand type to decide which data member will store the second operand 

	Connector* pOutConn;	//Operator Assignment Stat. has one Connector to next statement
	//Each statement type in flowchart has a predefined number of (output) connectors


	Point Inlet;	//A point where connections enters this statement 
	//It's used as the (End) point of the (Input) connectors
	Point Outlet;	//A point a connection leaves this statement
	//It's used as the (Start) point of the (Output) connector

	Point LeftCorner;	//left corenr of the statement block.

	virtual void UpdateStatementText();

public:
	OperatorAssign(Point Lcorner, string LeftHS = "", string Arith_operation = "",string first_op = "", string second_op = "", int first_op_type = VARIABLE_OP, int second_op_type = VARIABLE_OP);

	void setLHS(const string& L); //setter for the LHS
	void setFirstOp(const string& f, int first_op_type); // setter for the first operand 
	void setArithOp(const string& arth); // setter for the arithmatic operator
	void setSecondOp(const string& s, int second_op_type); // setter for the second operand 

	virtual void Draw(Output* pOut) const;

	void Edit(string LeftHS, string Arith_operation, string first_op, string second_op, int first_op_type, int second_op_type);

	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

	bool IsStatement(Point p);
	void SetLeftCorner(Point p);

	virtual OperatorAssign* Clone();

	virtual Point GetInlet();
	virtual Point GetOutlet();

	virtual void SetOutConnector(Connector*&);

	void Simulate();

	virtual Connector* StatementConnector();
	virtual bool IsValid();

};

