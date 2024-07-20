#include "Read.h"
#include <sstream>

using namespace std;

Read::Read(Point Lcorner, string LeftHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddRead) action
	//       before passing it to the constructor of Read
	Edit(LeftHS);

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}


void Read::SetLeftCorner(Point p)
{
	LeftCorner = p;
}


void Read::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawRead(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Read::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "Read " << Variable;
	Text = T.str();
}


void Read::Edit(const string& LeftHS)
{
	Variable = LeftHS;
}

Read* Read::Clone()
{
	return new Read(*this);
}


void Read::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord;

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
	Variable = statement_line.substr(22, statement_line.find_last_of('\t'));
	UpdateStatementText();
}


void Read::Save(ofstream& OutFile)
{
	OutFile << "Read_Assign\t";
	OutFile << ID << "\t";
	OutFile << LeftCorner.x << "\t" << LeftCorner.y << "\t";
	OutFile << Variable;
	OutFile << '\n';
}

Point Read::GetInlet()
{
	return Inlet;
}

Point Read::GetOutlet()
{
	return Outlet;
}

bool Read::IsStatement(Point p)
{
	if ((p.x >= LeftCorner.x) && (p.x <= (LeftCorner.x + UI.ASSGN_WDTH)) && (p.y >= LeftCorner.y) && (p.y <= (LeftCorner.y+UI.ASSGN_HI)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Read::SetOutConnector(Connector*& outConn)
{
	pOutConn = outConn;
}

void Read::Simulate()
{

}

Connector* Read::StatementConnector()
{
	return pOutConn;
}

bool Read::IsValid()
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