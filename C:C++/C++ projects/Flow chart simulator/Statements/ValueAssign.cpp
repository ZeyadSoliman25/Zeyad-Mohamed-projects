#include "ValueAssign.h"
#include <sstream>

using namespace std;

ValueAssign::ValueAssign(Point Lcorner, string LeftHS, double RightHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddValueAssign) action
	//       before passing it to the constructor of ValueAssign
	Edit(LeftHS, RightHS);

	UpdateStatementText();

	LeftCorner = Lcorner;
	
	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH /2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;	
}

void ValueAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void ValueAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

void ValueAssign::SetLeftCorner(Point p)
{
	LeftCorner = p;
}

void ValueAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssignValue(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void ValueAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T<<LHS<<" = "<<RHS;	
	Text = T.str();	 
}

ValueAssign* ValueAssign::Clone()
{
	return new ValueAssign(*this);
}


void ValueAssign::Edit(string LeftHS, double RightHS)
{
	setLHS(LeftHS);
	setRHS(RightHS);
}


void ValueAssign::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord,Twosides, RightHS;

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

	// extracting the two sides of the value assign 
	// by extracting the two sides first then extracting the LHS and the RHS
	Twosides = statement_line.substr(22);

	//get the name of the variable in the statement 
	LHS = Twosides.substr(0, Twosides.find_first_of('\t') );

	//get the value in the statement
	RightHS = Twosides.substr(Twosides.find_first_of('\t') + 1);

	RHS = stod(RightHS);

	UpdateStatementText();
}


void ValueAssign::Save(ofstream& OutFile)
{
	OutFile << "ValueAssign\t";
	OutFile << ID << "\t";
	OutFile << LeftCorner.x << "\t" << LeftCorner.y << "\t";
	OutFile << LHS << "\t" << to_string(RHS) << "\n";
}

bool ValueAssign::IsStatement(Point p)
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

Point ValueAssign::GetInlet()
{
	return Inlet;
}

Point ValueAssign::GetOutlet()
{
	return Outlet;
}

void ValueAssign::SetOutConnector(Connector*& outConn)
{
	pOutConn = outConn;
}

void ValueAssign::Simulate()
{

}

Connector* ValueAssign :: StatementConnector ()
{
	return pOutConn;
}

bool ValueAssign::IsValid()
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