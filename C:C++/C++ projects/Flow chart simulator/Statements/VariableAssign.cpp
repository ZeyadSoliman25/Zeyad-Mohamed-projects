#include "VariableAssign.h"
#include <sstream>
using namespace std;


VariableAssign::VariableAssign(Point Lcorner, string LeftHS, string RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddVariableAssign) action
	//       before passing it to the constructor of VariableAssign
	setLHS(LeftHS);
	setRHS(RightHS);

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}



void VariableAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void VariableAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}

void VariableAssign::SetLeftCorner(Point p)
{
	LeftCorner = p;
}

void VariableAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssignVariable(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}
 
VariableAssign* VariableAssign:: Clone()
{
	return new VariableAssign(*this);
}


//This function should be called when LHS or RHS changes
void VariableAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << RHS;
	Text = T.str();
}


void VariableAssign::Edit(string LeftHS, string RightHS)
{
	setLHS(LeftHS);
	setRHS(RightHS);
}


void VariableAssign::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord, Twosides, RightHS;

	//get the line in the txt file 
	getline(Infile, statement_line);

	// extracting left corner x coordinates from the line
	leftcorner_x_coord = statement_line.substr(14, 3);

	if (leftcorner_x_coord[2] == '\t')
	{
		leftcorner_x_coord[2] = '.';
		leftcorner_x_coord[3] = '0';
	}

	LeftCorner.x = stoi(leftcorner_x_coord);

	// extracting left corner y coordinates from the line
	leftcorner_y_coord = statement_line.substr(18, 3);

	if (leftcorner_y_coord[2] == '\t')
	{
		leftcorner_y_coord[2] = '.';
		leftcorner_y_coord[3] = '0';
	}

	LeftCorner.y = stoi(leftcorner_y_coord);

	// extracting the two sides of the variable assign 
	// by extracting the two sides first then extracting the LHS and the RHS
	Twosides = statement_line.substr(22);

	//get the name of the variable in the statement 
	LHS = Twosides.substr(0, Twosides.find_first_of('\t'));

	//get the second variable name in the statement
	RHS = Twosides.substr(Twosides.find_first_of('\t') + 1);

	UpdateStatementText();
}


void VariableAssign::Save(ofstream& OutFile)
{
	OutFile << "VariaAssign\t";
	OutFile << ID << "\t";
	OutFile << LeftCorner.x << "\t" << LeftCorner.y << "\t";
	OutFile << LHS << "\t" << RHS << "\n";
}

bool VariableAssign::IsStatement(Point p)
{
	if ((p.x >= LeftCorner.x) && (p.x <= (LeftCorner.x + UI.ASSGN_WDTH)) && (p.y >= LeftCorner.y) && (p.y <= LeftCorner.y+UI.ASSGN_HI))
	{
		return true;
	}
	else
	{
		return false;
	}
}


Point VariableAssign::GetInlet()
{
	return Inlet;
}

Point VariableAssign::GetOutlet()
{
	return Outlet;
}

void VariableAssign::SetOutConnector(Connector*& outConn)
{
	pOutConn = outConn;
}

void VariableAssign::Simulate()
{

}

Connector* VariableAssign::StatementConnector()
{
	return pOutConn;
}

bool VariableAssign::IsValid()
{
	if (pOutConn == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}