#include "OperatorAssign.h"
#include <sstream>

using namespace std;

OperatorAssign::OperatorAssign(Point Lcorner, string LeftHS, string Arith_operation, string first_op, string second_op, int first_op_type, int second_op_type)
{
	// Note: The LeftHS and RightHS should be validated inside (AddOperatorAssign) action
	//       before passing it to the constructor of OperatorAssign
	Edit(LeftHS, Arith_operation, first_op, second_op, first_op_type, second_op_type);
	
	UpdateStatementText();

	LeftCorner = Lcorner;

	pOutConn = NULL;	//No connectors yet

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void OperatorAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void OperatorAssign::SetLeftCorner(Point p)
{
	LeftCorner = p;
}

void OperatorAssign::setFirstOp(const string& f, int first_op_type)
{
	if (first_op_type == VARIABLE_OP)
	{
		FirstOp_VAR = f;
	}
	else
	{
		FirstOp_VAL = stod(f);
	}

	FirstOp_type = first_op_type;
}


void OperatorAssign::setSecondOp(const string& s, int second_op_type)
{
	if (second_op_type == VARIABLE_OP)
	{
		SecondOp_VAR = s;
	}
	else
	{
		SecondOp_VAL = stod(s);
	}

	SecondOp_type = second_op_type;
}

OperatorAssign* OperatorAssign::Clone()
{
	return new OperatorAssign(*this);
}

void OperatorAssign::setArithOp(const string& arth)
{
	ArithOp = arth;
}


void OperatorAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssignOperation(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void OperatorAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	if (FirstOp_type == VARIABLE_OP)
	{
		if (SecondOp_type == VARIABLE_OP)
		{
			T << LHS << " = " << FirstOp_VAR << ArithOp << SecondOp_VAR;
			Text = T.str();
		}
		else
		{
			T << LHS << " = " << FirstOp_VAR << ArithOp << to_string(SecondOp_VAL);
			Text = T.str();
		}
	}
	else
	{
		if (SecondOp_type == VARIABLE_OP)
		{
			T << LHS << " = " << to_string(FirstOp_VAL) << ArithOp << SecondOp_VAR;
			Text = T.str();
		}
		else
		{
			T << LHS << " = " << to_string(FirstOp_VAL) << ArithOp << to_string(SecondOp_VAL);
			Text = T.str();
		}
	}

}


void OperatorAssign::Edit(string LeftHS, string Arith_operation, string first_op, string second_op, int first_op_type, int second_op_type)
{
	setLHS(LeftHS);
	setArithOp(Arith_operation);
	setFirstOp(first_op, first_op_type);
	setSecondOp(second_op, second_op_type);
}


void OperatorAssign::Load(ifstream& Infile)
{
	string statement_line, leftcorner_x_coord, leftcorner_y_coord, Twosides, RightHS, Firstop, Arithop, Secondop;

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

	//get the value in the statement
	RightHS = Twosides.substr(Twosides.find_first_of('\t') + 1);

	Firstop = RightHS.substr(0, RightHS.find_first_of('\t'));
	
	if (ValueOrVariable(Firstop) == VARIABLE_OP)
	{
		FirstOp_VAR = Firstop;
		FirstOp_type = VARIABLE_OP;
	}
	else
	{
		FirstOp_VAL = stod(Firstop);
		FirstOp_type = VALUE_OP;
	}

	ArithOp = RightHS.substr(RightHS.find_first_of('\t') + 1 , 1);

	Secondop = RightHS.substr(RightHS.find_first_of('\t') + 3);

	if (ValueOrVariable(Secondop) == VARIABLE_OP)
	{
		SecondOp_VAR = Firstop;
		SecondOp_type = VARIABLE_OP;
	}
	else
	{
		SecondOp_VAL = stod(Secondop);
		SecondOp_type = VALUE_OP;
	}

	UpdateStatementText();
}


void OperatorAssign::Save(ofstream& OutFile)
{
	OutFile << "OperaAssign\t";
	OutFile << ID << "\t";
	OutFile << LeftCorner.x << "\t" << LeftCorner.y << "\t";
	OutFile << LHS << "\t";

	if (FirstOp_type == VARIABLE_OP)
	{
		OutFile << FirstOp_VAR << '\t'; 
	}
	else 
	{
		OutFile << FirstOp_VAL << '\t';
	}

	OutFile << ArithOp << '\t';
	
	if (SecondOp_type == VARIABLE_OP)
	{
		OutFile << SecondOp_VAR << '\t';
	}
	else
	{
		OutFile << to_string(SecondOp_VAL) << '\t';
	}

	OutFile << '\n';
}


bool OperatorAssign::IsStatement(Point p)
{
	if ( (p.x >= LeftCorner.x) && (p.x <= (LeftCorner.x + UI.ASSGN_WDTH)) && (p.y >= LeftCorner.y) && (p.y <= (LeftCorner.y+UI.ASSGN_HI)) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

Point OperatorAssign::GetInlet()
{
	return Inlet;
}

Point OperatorAssign::GetOutlet()
{
	return Outlet;
}

void OperatorAssign::SetOutConnector(Connector*& outConn)
{
	pOutConn = outConn;
}

void OperatorAssign::Simulate()
{

}

Connector* OperatorAssign ::StatementConnector()
{
	return pOutConn;
}


bool OperatorAssign::IsValid()
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