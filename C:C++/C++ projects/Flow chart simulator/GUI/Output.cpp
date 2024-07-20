#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	ClearToolBar(); // to clear the tool bar before drawing the design tool bar

	string MenuItemImages[DSN_ITM_CNT];

	MenuItemImages[ITM_START] = "images\\Start.jpg";
	MenuItemImages[ITM_END] = "images\\End.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign_value.jpg";
	MenuItemImages[ITM_VARIABLE_ASSIGN] = "images\\Assign_variable.jpg";
	MenuItemImages[ITM_OPERATOR_ASSIGN] = "images\\Assign_oper.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	MenuItemImages[ITM_READ] = "images\\Read.jpg";
	MenuItemImages[ITM_WRITE] = "images\\Write.jpg";
	MenuItemImages[ITM_ARROW] = "images\\Arrow.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Redo.jpg";

	MenuItemImages[ITM_SIM_MODE] = "images\\Sim_mode.jpg";
	MenuItemImages[ITM_OPEN_DESIGN] = "images\\Open.jpg";
	MenuItemImages[ITM_SAVE_DESIGN] = "images\\Save.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Select.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Edit.jpg";
	MenuItemImages[ITM_COPY] = "images\\Copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Delete.jpg";
	MenuItemImages[ITM_EXIT_DESIGN] = "images\\Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	ClearToolBar(); // to clear the tool bar before drawing the simulation tool bar

	string MenuItemImages[SIM_ITM_CNT];

	MenuItemImages[ITM_VALIDATE] = "images\\Validate.jpg";
	MenuItemImages[ITM_RUN] = "images\\Run.jpg";
	MenuItemImages[ITM_DEBUG] = "images\\Debug.jpg";
	MenuItemImages[ITM_DESGIN_MODE] = "images\\Design_mode.jpg";
	MenuItemImages[ITM_EXIT_SIM] = "images\\Exit.jpg";

	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssignValue(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}

void Output::DrawAssignVariable(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}

void Output::DrawAssignOperation(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
void Output::DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected)
{
	//the two arrrays required for the DrawPolygon method which draws a Rhombus
	const int IPX[4] = { Left.x, Left.x + width/2, Left.x, Left.x - width / 2};
	const int IPY[4] = { Left.y, Left.y + height/2, Left.y + height, Left.y + height/2 };

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block Rhombus
	pWind->DrawPolygon(IPX, IPY, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - width/10 - 4, Left.y + height/3, Text);
}

void Output::DrawStart(Point Left, int width, int height, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block Ellipse 
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4 + 14, Left.y + height / 4, "Start");
}

void Output::DrawEnd(Point Left, int width, int height, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block Ellipse 
	pWind->DrawEllipse(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4 + 14, Left.y + height / 4, "End");
}

void Output::DrawRead(Point Left, int width, int height, string Text, bool Selected)
{
	//the two arrrays required for the DrawPolygon method which draws a parallelogram
	const int IPX[4] = { Left.x, Left.x + width, Left.x + 9 * width / 10, Left.x - width / 10 };
	const int IPY[4] = { Left.y, Left.y, Left.y + height, Left.y + height };

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block Parallelogram
	pWind->DrawPolygon(IPX, IPY, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}

void Output::DrawWrite(Point Left, int width, int height, string Text, bool Selected)
{
	//the two arrrays required for the DrawPolygon method which draws a parallelogram
	const int IPX[4] = { Left.x, Left.x + width, Left.x + 9 * width / 10, Left.x - width / 10 };
	const int IPY[4] = { Left.y, Left.y, Left.y + height, Left.y + height };

	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block Parallelogram
	pWind->DrawPolygon(IPX, IPY, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}
	
//TODO: Add DrawConnector function

void Output::DrawConnectors(Point start, Point end, bool Selected, bool Connected_Line)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	pWind->DrawLine(start.x, start.y, end.x, end.y);

	if (!Connected_Line) 
	{
		int X1 = end.x+5, Y1 = 0, X2 = end.x - 5, Y2 = 0, X3 = end.x+5, Y3 = 0;

		if ( (start.x == end.x) && (start.y < end.y) ) // vertical line pointing downward 
		{
			X1 = end.x;
			X2 = end.x - 5;
			X3 = end.x + 5;
			Y1 = end.y + 5;
			Y2 = end.y;
			Y3 = end.y;

		}
		else if (start.x > end.x) // horizontal line pointing backward
		{
			X1 = end.x - 5;
			X2 = end.x;
			X3 = end.x;
			Y1 = end.y;
			Y2 = end.y - 5;
			Y3 = end.y + 5;

		}
		else if (start.x < end.x) // horizontal line pointing forward
		{
			X2 = end.x;
			X3 = end.x;
			Y1 = end.y;
			Y2 = end.y - 5;
			Y3 = end.y + 5;
		}

		else if ( (start.x == end.x) && (start.y > end.y) ) // vertical line pointing upward
		{
			X1 = end.x;
			X2 = end.x - 5;
			X3 = end.x + 5;
			Y1 = end.y - 5;
			Y2 = end.y;
			Y3 = end.y;
		}
		pWind->DrawTriangle(X1, Y1, X2, Y2, X3, Y3);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
