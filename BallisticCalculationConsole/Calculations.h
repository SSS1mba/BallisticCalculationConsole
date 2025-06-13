#pragma once
#include <math.h>
#include <iostream>

constexpr double g = 9.8;

struct Parametrs
{
	const double start_velocity_;		 //��������� �������� ������
	const double angle_;				 //���� ������
	const double start_x_pos_;			 //��������� ���������� �� ��� x
	const double start_y_pos_;			 //��������� ���������� �� ��� y
	const double ac�eleration_x_;
	const double a�celereation_y_;

	const double start_velocity_x_;		 //��������� �������� �� ��� x
	const double start_velocity_y_;		 //��������� �������� �� ��� y

	Parametrs(double start_velocity, double angle, double start_x_pos, double start_y_pos, 
		double ac�eleration_x = 0, double a�celereation_y = g)

		:start_velocity_(start_velocity), angle_(angle) ,
		start_x_pos_(start_x_pos), start_y_pos_(start_y_pos), 
		ac�eleration_x_(ac�eleration_x),a�celereation_y_(a�celereation_y),
		start_velocity_x_(start_velocity_* cos(angle_)), start_velocity_y_(start_velocity_* sin(angle_)) {}

	Parametrs(const Parametrs& other) :start_velocity_(other.start_velocity_), angle_(other.angle_),
		start_x_pos_(other.start_x_pos_), start_y_pos_(other.start_y_pos_),
		ac�eleration_x_(other.ac�eleration_x_), a�celereation_y_(other.a�celereation_y_),
		start_velocity_x_(other.start_velocity_x_), start_velocity_y_(other.start_velocity_y_) { }
};


class Calculations
{
public:
	Calculations(const Parametrs& parametrs);
private:
	Parametrs parametrs;
};

