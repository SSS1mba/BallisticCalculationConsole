#pragma once

#include <math.h>
#include <iostream>

struct Parametrs
{
	double velocity_x;
	double velocity_y;
	double x_pos;
	double y_pos;
	double ac�eleration_x;
	double a�celereation_y;
	int a;

	Parametrs(double velocity_x, double velocity_y, double x_pos, double y_pos, double ac�eleration_x, double ac�elereation_y)
		:velocity_x(velocity_x), velocity_y(velocity_y), x_pos(x_pos), y_pos(y_pos), 
		ac�eleration_x(ac�eleration_x), a�celereation_y(ac�elereation_y)
	{

	}
	Parametrs(const Parametrs& other) :velocity_x(other.velocity_x), velocity_y(other.velocity_y),
		x_pos(other.x_pos), y_pos(other.y_pos),
		ac�eleration_x(other.ac�eleration_x), a�celereation_y(other.a�celereation_y)
	{

	}
	Parametrs& operator= (const Parametrs& other)
	{
		this->velocity_x = other.velocity_x;
		this->velocity_y = other.velocity_y;
		this->x_pos = other.x_pos;
		this->y_pos = other.y_pos;
		this->ac�eleration_x = other.ac�eleration_x;
		this->a�celereation_y = other.a�celereation_y;
	}
};
class Calculations
{
	Calculations();
};

