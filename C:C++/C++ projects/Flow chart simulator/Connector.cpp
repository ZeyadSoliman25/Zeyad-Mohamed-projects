#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst)	
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	
	SrcStat = Src;
	DstStat = Dst;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}


bool Connector::IsConnector(Point P)
{
	//Vertical line
	if (Start.x == End.x)
	{
		//Pointing upwards
		if (Start.y > End.y)
		{
			if ((P.y <= Start.y) && (P.y >= End.y))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//pointing downwards
		else
		{
			if ((P.y >= Start.y) && (P.y <= End.y))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	//Horizontal line
	else if (Start.y == End.y)
	{
		//pointing left
		if ((Start.x > End.x))
		{
			if ((P.x <= Start.x) && (P.x >= End.y))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//pointing right
		else 
		{
			if ((P.x >= Start.x) && (P.x <= End.x))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return true;
	}
}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnectors(Start, End);
}

