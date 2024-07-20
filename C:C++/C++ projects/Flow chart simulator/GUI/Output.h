#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();	

	window* CreateWind(int, int, int , int);
	Input* CreateInput(); //Creates a pointer to the Input object	

	void CreateStatusBar(); //Creates status bar

	//TODO: Complete the following 2 functions
	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar(); //Tool bar of the simulation mode

	void ClearToolBar();	//Clears the tool bar so the design tool bar and simulation tool bar doesn't overlap

	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearOutputBar(); //Clears the Output bar
	void PrintMessage(string msg);	//Prints a message on Status bar
	void DrawString(const int, const int, const string);  //Writes a string in the specified location

	// -- Statements Drawing Functions
	void DrawAssignValue(Point Left, int width, int height, string Text, bool Selected=false);

	//TODO: Add similar functions for drawing all other statements.
	//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
	//		Decide the parameters that should be passed to each of them
	void DrawAssignVariable(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawAssignOperation(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawConditionalStat(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawStart(Point Left, int width, int height, bool Selected=false);
	void DrawEnd(Point Left, int width, int height, bool Selected = false);
	void DrawRead(Point Left, int width, int height, string Text, bool Selected=false);
	void DrawWrite(Point Left, int width, int height, string Text, bool Selected = false);
	
	//TODO: Add DrawConnector function
	void Output::DrawConnectors(Point start, Point end, bool Selected = false, bool Connected_Line = false);

	~Output();
};

#endif