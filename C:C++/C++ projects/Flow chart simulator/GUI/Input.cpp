
#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	double D = 0;
	string Label;
	int IndexPoint=0, MaxPower;
	bool PointAllocated = false , Initialize = false, IsNegative = false;


	while (!(Initialize))
	{
		Label = GetString(pO);
		Initialize = IsValue(Label);

		if (Initialize)
		{
			for (int i = 0; i < Label.size(); i++)
			{
				if (Label[i] == '.')
				{
					IndexPoint = i;
					PointAllocated = true;
				}
			}

			if (Label[0] == '-') // Checking for number negativity
				IsNegative = true;


			// To Calculate Number
			MaxPower = Label.size() - 1;

			if (PointAllocated)
				MaxPower -= (Label.size() - IndexPoint);
			

			for (int i = 0; i < Label.size(); i++)
			{
				if (Label[i] != '-' && Label[i] != '.')
				{
					int Num = Label[i] - 48;
					double Weight = pow(10, (MaxPower - i));
					if (Weight < 1)
						Weight *= 10;
					D += Num * Weight;
				}
			}

			if (IsNegative)
				D = (-1) * D;

		}

		//This function should make any needed validations on the entered text 
		// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 …etc.).

		pO->PrintMessage("Please enter a value");


		}

	//Read a double value from the user
	return D;
}


string Input::GetVariable(Output*pO) const
{
	string VariableName = GetString(pO);
	while (!(IsVariable(VariableName)))
	{
		pO->PrintMessage("Enter a valid variable name:");
		VariableName = GetString(pO);
	}
	return VariableName;
}

string Input::GetArithOperator(Output* pO) const
{
	string Label = GetString(pO);


	while (Label != "+" && Label != "-" && Label != "*" && Label != "/")
	{
		pO->PrintMessage("Enter a valid operation:");
		Label = GetString(pO);
	}
	pO->PrintMessage(Label);
	return Label;
}

string Input::GetCompOperator(Output* pO)const
{
	string CompOperator = GetString(pO);
	while (CompOperator != "==" && CompOperator != "!=" && CompOperator != "<" && CompOperator != "<=" && CompOperator != ">" && CompOperator != ">=")
	{
		pO->PrintMessage("Enter a valid CompOperator:");
		CompOperator = GetString(pO);
	}
	pO->PrintMessage(CompOperator);
	return CompOperator;
}

ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_START: return ADD_START;
			case ITM_END: return ADD_END;
			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;
			case ITM_VARIABLE_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_OPERATOR_ASSIGN: return ADD_OPER_ASSIGN;
			case ITM_COND: return ADD_CONDITION;
			case ITM_READ: return ADD_READ;
			case ITM_WRITE: return ADD_WRITE;
			case ITM_ARROW: return ADD_CONNECTOR;
			case ITM_REDO: return REDO;
			case ITM_UNDO: return UNDO;
			case ITM_SIM_MODE: return SWITCH_SIM_MODE;
			case ITM_OPEN_DESIGN: return LOAD;
			case ITM_SAVE_DESIGN: return SAVE;
			case ITM_SELECT: return SELECT;
			case ITM_EDIT: return EDIT_STAT;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_EXIT_DESIGN: return EXIT;
			default: return DSN_TOOL;
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;	
			else
				return OUTPUT_AREA;
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		int ClickedItem = (x / UI.MenuItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
		switch (ClickedItem)
		{
		case ITM_VALIDATE:return VALIDATE;
		case ITM_RUN: return RUN;
		case ITM_DEBUG: return DEBUG;
		case ITM_DESGIN_MODE: return SWITCH_DSN_MODE;
		case ITM_EXIT_SIM: return EXIT;
		default: return SIM_TOOL;
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}


Input::~Input()
{
}
