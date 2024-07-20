#ifndef STATEMENT_H
#define STATEMENT_H

#include <fstream>
#include <string>
#include "..\defs.h"
#include "..\Connector.h"
//class Output;
#include "..\GUI\Output.h"

//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID --> must be unique
	string Text;	//Statement text (e.g.  "X = 5" OR "salary > 3000" and so on)
	bool Selected;	//true if the statement is selected on the folwchart


	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement();
	void SetSelected(bool s);
	bool IsSelected() const;

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	
	

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type

	virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file

	virtual void Edit() {};		//Edit the Statement parameter

	virtual void Simulate() {};	//Execute the statement in the simulation mode 

	//[BONUS] virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file


	///TODO: Add more functions if needed

	/*Setter and Getter for ID*/
	void SetID(int id);
	int GetID();

	/*Check if the point is within the statement*/
	virtual bool IsStatement(Point P) = 0;

	virtual void SetLeftCorner(Point p) = 0;

	//getter for the inlet and outlet points
	virtual Point GetInlet() = 0;
	virtual Point GetOutlet() = 0;

	virtual void SetOutConnector(Connector *&) = 0;

	virtual Statement* Clone() = 0;
	virtual Connector* StatementConnector() = 0;
	virtual bool IsValid() = 0;

}; 
#endif
