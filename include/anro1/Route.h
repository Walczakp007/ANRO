
#ifndef ROUTE_H
#define ROUTE_H
#include "Point.h"

class Route
{
public:
	Route(double x, double y, bool in);
	virtual ~Route();
protected:
private:
	Point origin;
	bool in;
};

#endif // ROUTE_H#pragma once

