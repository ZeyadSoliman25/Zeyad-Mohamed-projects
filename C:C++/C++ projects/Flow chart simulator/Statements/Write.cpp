#include "Write.h"
#include <sstream>

using namespace std;

Write::Write(Point Lcorner, string LeftHS)
{
	// Note: The LeftHS and RightHS should be validated inside (AddWrite) action
	//       before passing it to the constructor of Write
	Edit(LeftHS);

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet
	pInConn = NULL;		//No connectors

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void Write::SetLeftCorner(Point p)
{
	LeftCorner = p;
}

void Write::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void Write::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "Write " << Variable;
	Text = T.str();
}


void Write::Edit(const string& LeftHS)
{
	Variable = LeftHS;
}

Write* Write::Clone()
{
	return new Write(*this);
}

void Write::Load(ifstream& Infile)
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


void Write::Save(ofstream& OutFile)
{
	OutFile << "WriteAssign\t";
	OutFile << ID << "\t";
	OutFile << LeftCorner.x << "\t" << LeftCorner.y << "\t";
	OutFile << Variable;
	OutFile << '\n';
}


bool Write::IsStatement(Point p)
{
	if ((p.x >= LeftCorner.x) && (p.x <= (LeftCorner.x + UI.ASSGN_WDTH)) && (p.y >= LeftCorner.y) && (p.y <= (LeftCorner.y+UI.ASSGN_HI)) )
	{
		return true;
	}
	else
	{
		return false;
	}
}


Point Write::GetInlet()
{
	return Inlet;
}

Point Write::GetOutlet()
{
	return Outlet;
}

void Write::SetOutConnector(Connector*& outConn)
{
	pOutConn = outConn;
}

void Write::Simulate()
{

}

Connector* Write::StatementConnector()
{
	return pOutConn;
}

bool Write::IsValid()
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
