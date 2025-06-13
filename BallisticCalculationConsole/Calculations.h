#pragma once
#include <math.h>
#include <iostream>

constexpr double g = 9.8;

struct Parametrs
{
	const double start_velocity_;		 //íà÷àëüíàÿ ñêîğîñòü áğîñêà
	const double angle_;				 //óãîë áğîñêà
	const double start_x_pos_;			 //íà÷àëüíàÿ êîîğäèíàòà ïî îñè x
	const double start_y_pos_;			 //íà÷àëüíàÿ êîîğäèíàòà ïî îñè y
	const double acñeleration_x_;
	const double añcelereation_y_;

	const double start_velocity_x_;		 //íà÷àëüíàÿ ñêîğîñòü ïî îñè x
	const double start_velocity_y_;		 //íà÷àëüíàÿ ñêîğîñòü ïî îñè y

	Parametrs(double start_velocity, double angle, double start_x_pos, double start_y_pos, 
		double acñeleration_x = 0, double añcelereation_y = g)

		:start_velocity_(start_velocity), angle_(angle) ,
		start_x_pos_(start_x_pos), start_y_pos_(start_y_pos), 
		acñeleration_x_(acñeleration_x),añcelereation_y_(añcelereation_y),
		start_velocity_x_(start_velocity_* cos(angle_)), start_velocity_y_(start_velocity_* sin(angle_)) {}

	Parametrs(const Parametrs& other) :start_velocity_(other.start_velocity_), angle_(other.angle_),
		start_x_pos_(other.start_x_pos_), start_y_pos_(other.start_y_pos_),
		acñeleration_x_(other.acñeleration_x_), añcelereation_y_(other.añcelereation_y_),
		start_velocity_x_(other.start_velocity_x_), start_velocity_y_(other.start_velocity_y_) { }
};


class Calculations
{
public:
	Calculations(const Parametrs& parametrs);
private:
	Parametrs parametrs;
};

