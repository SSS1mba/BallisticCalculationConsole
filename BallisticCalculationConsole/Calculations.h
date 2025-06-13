#pragma once
#include <math.h>
#include <iostream>

constexpr double g = 9.8;

struct Parametrs
{
	const double start_velocity_;		 //начальная скорость броска
	const double angle_;				 //угол броска
	const double start_x_pos_;			 //начальная координата по оси x
	const double start_y_pos_;			 //начальная координата по оси y
	const double acceleration_x_;
	const double acceleration_y_;

	const double start_velocity_x_;		 //начальная скорость по оси x
	const double start_velocity_y_;		 //начальная скорость по оси y

	Parametrs(double start_velocity, double angle, double start_x_pos, double start_y_pos, 
		double acсeleration_x = 0, double aсcelereation_y = -1 * g)

		:start_velocity_(start_velocity), angle_(angle) ,
		start_x_pos_(start_x_pos), start_y_pos_(start_y_pos), 
		acceleration_x_(acсeleration_x),acceleration_y_(aсcelereation_y),
		start_velocity_x_(start_velocity_* cos(angle_)), start_velocity_y_(start_velocity_* sin(angle_)) {}

	Parametrs(const Parametrs& other) :start_velocity_(other.start_velocity_), angle_(other.angle_),
		start_x_pos_(other.start_x_pos_), start_y_pos_(other.start_y_pos_),
		acceleration_x_(other.acceleration_x_), acceleration_y_(other.acceleration_y_),
		start_velocity_x_(other.start_velocity_x_), start_velocity_y_(other.start_velocity_y_) { }
};

class Calculations
{
private:
	Parametrs parametrs_;

public:
	explicit Calculations(const Parametrs& parametrs) : parametrs_(parametrs){}

	inline double calculate_x_pos (double time)const
	{
		//x = x0 + V0x * t + 0.5*ax*t*t
		return ( parametrs_.start_x_pos_ ) + ( parametrs_.start_velocity_x_ * time) + (0.5 * parametrs_.acceleration_x_ * time * time);
	}
	inline double calculate_y_pos(double time)const
	{
		//y = y0 + V0y * t + 0.5*ay*t*t
		return (parametrs_.start_y_pos_) + (parametrs_.start_velocity_y_ * time) + (0.5 * parametrs_.acceleration_y_ * time * time);
	}
	inline double calculate_velocity_x(double time)const
	{
		//Vx = V0x + ax * t
		return parametrs_.start_velocity_x_ + parametrs_.acceleration_x_ * time;
	}
	inline double calculate_velocity_y(double time)const
	{
		//Vy = V0y + ay * t
		return parametrs_.start_velocity_y_ + parametrs_.acceleration_y_ * time;
	}

};

