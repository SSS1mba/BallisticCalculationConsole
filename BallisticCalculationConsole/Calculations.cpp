#include "Calculations.h"

double Calculations::calculate_y_pos(double time) const
{
	if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
	if (time >= flight_time_) return 0;

	double y_pos; //y
	if (time < flight_time_) //y = y0 + V0y * t - 0.5*ay*t*t
		y_pos = (parametrs_.start_y_pos_) + (parametrs_.start_velocity_y_ * time) - (0.5 * parametrs_.acceleration_y_ * time * time);
	else				     //y = max_height_ - 0.5*ay*(t - flight_time_ ) *(t - flight_time_ )
		y_pos = max_height_ - (0.5 * parametrs_.acceleration_y_ * (time - flight_time_) * (time - flight_time_));

	return y_pos;
}
	
double Calculations::calculate_velocity_y(double time) const
{
	if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
	if (time >= flight_time_) return 0; //тело упало - не учитываем скорость ПОСЛЕ полета

	double velocity_y; //Vy
	if (time < parametrs_.lifting_time_) //Vy = V0 - a*t
		velocity_y = parametrs_.start_velocity_y_ - parametrs_.acceleration_y_ * time;
	else					 //Vy = 0 + a*(t - flight_time_)
		velocity_y = 0 + parametrs_.acceleration_y_ * (time - parametrs_.lifting_time_);

	return velocity_y;
}
