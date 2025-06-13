#pragma once

#include <math.h>
#include <iostream>

struct Parametrs
{
	double velocity_x;
	double velocity_y;
	double x_pos;
	double y_pos;
	double acñeleration_x;
	double añcelereation_y;
	int a;

	Parametrs(double velocity_x, double velocity_y, double x_pos, double y_pos, double acñeleration_x, double acñelereation_y)
		:velocity_x(velocity_x), velocity_y(velocity_y), x_pos(x_pos), y_pos(y_pos), 
		acñeleration_x(acñeleration_x), añcelereation_y(acñelereation_y)
	{

	}
	Parametrs(const Parametrs& other) :velocity_x(other.velocity_x), velocity_y(other.velocity_y),
		x_pos(other.x_pos), y_pos(other.y_pos),
		acñeleration_x(other.acñeleration_x), añcelereation_y(other.añcelereation_y)
	{

	}
	Parametrs& operator= (const Parametrs& other)
	{
		this->velocity_x = other.velocity_x;
		this->velocity_y = other.velocity_y;
		this->x_pos = other.x_pos;
		this->y_pos = other.y_pos;
		this->acñeleration_x = other.acñeleration_x;
		this->añcelereation_y = other.añcelereation_y;
	}
};
class Calculations
{
	Calculations();
};

