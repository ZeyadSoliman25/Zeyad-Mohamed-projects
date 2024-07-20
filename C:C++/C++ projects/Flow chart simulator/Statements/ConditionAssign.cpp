#include "ConditionAssign.h"
#include <sstream>

using namespace std;

ConditionAssign::ConditionAssign(Point Lcorner, string LeftHS, string Comp_operation, string RightHS,int RightHs_type)
{
	// Note: The LeftHS and RightHS should be validated inside (AddConditionAssign) action
	//       before passing it to the constructor of ConditionAssign
	Edit(LeftHS, Comp_operation, RightHS, RightHs_type);

	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn_1 = NULL;	//No connectors yet
	pOutConn_2 = NULL; //No connectors yet

	Inlet.x = LeftCorner.x;
	Inlet.y = LeftCorner.y;

	Outlet_1.x = LeftCorner.x - UI.ASSGN_WDTH/2;
	Outlet_1.y = LeftCorner.y + UI.ASSGN_HI/2;

	Outlet_2.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Outlet_2.y = LeftCorner.y + UI.ASSGN_HI / 2;

}

void ConditionAssign::setLHS(const string& L)
{
	LHS = L;

}


void ConditionAssign::setRHS(const string& R, int rhs_type)
{
	if (rhs_type == VARIABLE_OP)
	{
		RHS_VAR = R;
	}
	else
	{
		RHS_VAL = stod(R);
	}

	RHS_type = rhs_type;

}

void ConditionAssign::setCompOp(const string& comp)
{
	CompOp = comp;

}

void ConditionAssign::SetLeftCorner(Point p)
{
	LeftCorner = p;
}


void ConditionAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawConditionalStat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void ConditionAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	if (RHS_type == VARIABLE_OP)
	{
		T << LHS << CompOp << RHS_VAR;
		Text = T.str();
	}
	else
	{
		T << LHS << CompOp << to_string(RHS_VAL);
		Text = T.str();
	}

}

ConditionAssign* ConditionAssign::Clone()
{
	return new ConditionAssign(*this);
}

void ConditionAssign::Edit(string LeftHS, string comp_operation, string rhs, int rhs_type)
{
	setLHS(LeftHS);
	setCompOp(comp_operation);
	setRHS(rhs, rhs_type);
}


void ConditionAssign::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord, Twosides, RightHS, compop;

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
	LHS = Twosides.substr(0, Twosides.find_first_of('\t'));

	compop = Twosides.substr(Twosides.find_first_of('\t') + 1, 2);

	if (compop[1] == '\t')
	{
		CompOp = compop;

		//get the value in the statement
		RightHS = Twosides.substr(Twosides.find_first_of('\t') + 3);

		if (ValueOrVariable(RightHS) == VARIABLE_OP)
		{
			RHS_VAR = RightHS;
			RHS_type = VARIABLE_OP;
		}
		else
		{
			RHS_VAL = stod(RightHS);
			RHS_type = VALUE_OP;
		}
	}
	else
	{
		CompOp = compop;
		//get the value in the statement
		RightHS = Twosides.substr(Twosides.find_first_of('\t') + 4);

		if (ValueOrVariable(RightHS) == VARIABLE_OP)
		{
			RHS_VAR = RightHS;
			RHS_type = VARIABLE_OP;
		}
		else
		{
			RHS_VAL = stod(RightHS);
			RHS_type = VALUE_OP;
		}

	}

	UpdateStatementText();
}


void ConditionAssign::Save(ofstream& OutFile)
{
	OutFile << "CondtAssign\t";
	OutFile << ID << "\t";
	OutFile << LeftCorner.x << "\t" << LeftCorner.y << "\t";
	OutFile << LHS << "\t";

	OutFile << CompOp << '\t';

	if (RHS_type == VARIABLE_OP)
	{
		OutFile << RHS_VAR << '\t';
	}
	else
	{
		OutFile << RHS_VAL << '\t';
	}

	OutFile << '\n';
}


bool ConditionAssign::IsStatement(Point p)
{
	if ((p.x >= (LeftCorner.x - UI.ASSGN_WDTH/2)) && (p.x <= (LeftCorner.x + UI.ASSGN_WDTH/2)) && (p.y >= LeftCorner.y) && (p.y <= (LeftCorner.y + UI.ASSGN_HI)) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

Point ConditionAssign::GetInlet()
{
	return Inlet;
}

Point ConditionAssign::GetOutlet()
{
	static int number_of_returns = 0;

	if (number_of_returns == 0)
	{
		number_of_returns++;
		return Outlet_1;

	}
	else if (number_of_returns == 1)
	{
		number_of_returns++;
		return Outlet_2;

	}
	else
	{
		return Outlet_1;
	}
}

void ConditionAssign::SetOutConnector(Connector*& outConn)
{
	static int number_of_returns = 0;

	if (number_of_returns == 0)
	{
		number_of_returns++;
		pOutConn_1 = outConn;

	}
	else if (number_of_returns == 1)
	{
		number_of_returns++;
		pOutConn_2 = outConn;

	}
}

void ConditionAssign::Simulate()
{

}

Connector* ConditionAssign::StatementConnector()
{
	return pOutConn_1;
}

bool ConditionAssign::IsValid()
{
	if ((pOutConn_1 == NULL) || (pOutConn_2 == NULL))
	{
		return false;
	}
	else
	{
		return true;
	}

}