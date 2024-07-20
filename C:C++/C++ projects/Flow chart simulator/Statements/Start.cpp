#include "Start.h"


#include <sstream>

using namespace std;

Start::Start(Point Lcorner)
{
	Center = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Outlet.x = Center.x + UI.ASSGN_WDTH/2;
	Outlet.y = Center.y + UI.ASSGN_HI;
}

void Start::SetLeftCorner(Point p)
{
	Center = p;
}

void Start::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawStart(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);

}

Start* Start::Clone()
{
	return new Start(*this);
}


void Start::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord;

	//get the line in the txt file 
	getline(Infile, statement_line);

	// extracting left corner x coordinates from the line
	leftcorner_x_coord = statement_line.substr(8, 3);

	if (leftcorner_x_coord[2] == '\t')
	{
		leftcorner_x_coord[2] = '.';
		leftcorner_x_coord[3] = '0';
	}

	Center.x = stoi(leftcorner_x_coord);
	Center.x += UI.ASSGN_WDTH / 2;

	// extracting left corner y coordinates from the line
	leftcorner_y_coord = statement_line.substr(12, 3);

	if (leftcorner_y_coord[2] == '\t')
	{
		leftcorner_y_coord[2] = '.';
		leftcorner_y_coord[3] = '0';
	}

	Center.y = stoi(leftcorner_y_coord);
	Center.y += UI.ASSGN_HI / 2;
}


void Start::Save(ofstream& OutFile)
{
	OutFile << "Start\t";
	OutFile << ID << "\t";
	OutFile << Center.x << "\t" << Center.y << "\t";
	OutFile << '\n';
}

bool Start::IsStatement(Point p)
{
	if ( (p.x >= Center.x ) && (p.x <= (Center.x + UI.ASSGN_WDTH)) && (p.y >= Center.y ) && (p.y <= (Center.y + UI.ASSGN_HI)) )
	{
		return true;
	}
	else
	{
		return false;
	}
}


Point Start::GetOutlet()
{
	return Outlet;
}

void Start::SetOutConnector(Connector*& outConn)
{
	pOutConn = outConn;
}

void Start::Simulate()
{

}

Connector* Start::StatementConnector()
{
	return pOutConn;
}

bool Start::IsValid()
{
	static int number_statements;
	number_statements++;

	if (number_statements > 1)
	{
		return false;
	}
	if (pOutConn == NULL)
	{
		return false;
	}
	return true;
}
