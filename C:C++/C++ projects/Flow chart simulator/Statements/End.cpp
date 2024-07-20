#include "End.h"

#include <sstream>

using namespace std;

End::End(Point Lcorner)
{
	Center = Lcorner;

	Inlet.x = Center.x + UI.ASSGN_WDTH/2;
	Inlet.y = Center.y;
}


void End::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawEnd(Center, UI.ASSGN_WDTH, UI.ASSGN_HI, Selected);

}

void End::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord, Twosides, RightHS;

	//get the line in the txt file 
	getline(Infile, statement_line);

	// extracting left corner x coordinates from the line
	leftcorner_x_coord = statement_line.substr(6, 3);

	if (leftcorner_x_coord[2] == '\t')
	{
		leftcorner_x_coord[2] = '.';
		leftcorner_x_coord[3] = '0';
	}

	Center.x = stoi(leftcorner_x_coord);
	Center.x += UI.ASSGN_WDTH / 2;

	// extracting left corner y coordinates from the line
	leftcorner_y_coord = statement_line.substr(10, 3);

	if (leftcorner_y_coord[2] == '\t')
	{
		leftcorner_y_coord[2] = '.';
		leftcorner_y_coord[3] = '0';
	}

	Center.y = stoi(leftcorner_y_coord);
	Center.y += UI.ASSGN_HI / 2;
}

void End::SetLeftCorner(Point p)
{
	Center = p;
}


void End::Save(ofstream& OutFile)
{
	OutFile << "End\t";
	OutFile << ID << "\t";
	OutFile << Center.x << "\t" << Center.y << "\t";
	OutFile << "\n";
}

bool End::IsStatement(Point p)
{
	if ((p.x >= Center.x) && (p.x <= (Center.x + UI.ASSGN_WDTH)) && (p.y >= Center.y) && (p.y <= (Center.y + UI.ASSGN_HI)) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

End* End::Clone()
{
	return new End(*this);
}

Point End::GetInlet()
{
	return Inlet;
}

void End::Simulate()
{

}

Connector* End:: StatementConnector()
{
	Connector* S=nullptr;
	return S;
}

bool End::IsValid()
{
	static int number_statements;	//number of statements
	number_statements++;

	if (number_statements > 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
