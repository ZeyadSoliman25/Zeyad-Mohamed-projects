#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "GUI\UI_Info.h"
#include "GUI\output.h"
class Statement;

class Connector	//a connector that connects two statements (Source & Destination)
{
private:
	Statement *SrcStat;	//The source statement of the connector
	Statement *DstStat;	//The destination statement of the connector
	Point Start;	//Start point of the connector
	Point MidPoint; //Mid point of the connector if the connector isnot vertical or horizontal and rather a mixed form of horizontal and vertical line
	Point End;		//End point of the connector
public:
	Connector(Statement* Src, Statement* Dst);

	void		setSrcStat(Statement *Src);
	Statement*	getSrcStat();	
	void		setDstStat(Statement *Dst);
	Statement*	getDstStat();

	void setStartPoint(Point P);
	Point getStartPoint();

	void setEndPoint(Point P);
	Point getEndPoint();

	bool IsConnector(Point P);

	void Draw(Output* pOut) const;
	

};

#endif