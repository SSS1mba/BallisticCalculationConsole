#include "Calculations.h"


//double Calculations::calculate_y_pos(double time) const
//{
//	if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
//	if (time >= flight_time_) return 0;
//
//	double y_pos; //y
//	if (time < flight_time_) //y = y0 + V0y * t - 0.5*ay*t*t
//		y_pos = (parametrs_.start_y_pos_) + (parametrs_.start_velocity_y_ * time) - (0.5 * parametrs_.acceleration_y_ * time * time);
//	else				     //y = max_height_ - 0.5*ay*(t - flight_time_ ) *(t - flight_time_ )
//		y_pos = max_height_ - (0.5 * parametrs_.acceleration_y_ * (time - flight_time_) * (time - flight_time_));
//
//	return y_pos;
//}
//	
//double Calculations::calculate_velocity_y(double time) const
//{
//	if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
//	if (time >= flight_time_) return 0; //тело упало - не учитываем скорость ПОСЛЕ полета
//
//	double velocity_y; //Vy
//	if (time < parametrs_.lifting_time_) //Vy = V0 - a*t
//		velocity_y = parametrs_.start_velocity_y_ - parametrs_.acceleration_y_ * time;
//	else					 //Vy = 0 + a*(t - flight_time_)
//		velocity_y = 0 + parametrs_.acceleration_y_ * (time - parametrs_.lifting_time_);
//
//	return velocity_y;
//}


bool Calculator::calculate(InputArr& input_arr) const noexcept
{
	size_t temp; // хранит в себе значение InputArr.calculated_ с предыдущей итерации
	//нужно для обнаружения невозможности решения системы (если за цикл не подсчтиали ни одной переменной -> мы в тупике -> нет решения)

	while (input_arr.GET_calculated() != input_arr.GET_NUMBER_OF_ELEMENTS())
	{

		if (input_arr.GET_calculated() == temp) return false; //если за цикл не подсчтиали ни одной переменной -> мы в тупике -> нет решения
		temp = input_arr.GET_calculated();
	}
	return true;
}


double Calculator::calculate_start_velocity(const double angle, const double start_velocity_x) const noexcept
{
	return start_velocity_x/ cos(angle);
}
double Calculator::calculate_start_velocity(const double angle, const double start_velocity_y) const noexcept
{
	return start_velocity_y / sin(angle);
}

double Calculator::calculate_angle(const double start_velocity_x, const double start_velocity_y) const noexcept
{
	return atan(start_velocity_y/ start_velocity_x);
}
double Calculator::calculate_angle(const double start_velocity, const double start_velocity_y) const noexcept
{
	return asin(start_velocity_y / start_velocity);
}
double Calculator::calculate_angle(const double start_velocity, const double start_velocity_x) const noexcept
{
	return acos(start_velocity_x / start_velocity);
}

double Calculator::calculate_acceleration_y(const double start_velocity_y, const double lifting_time) const noexcept
{
	return start_velocity_y/ lifting_time;
}
double Calculator::calculate_acceleration_x(const double start_velocity_x, const double flight_time, const double flight_range) const noexcept
{
	return 2 * ( (flight_range - start_velocity_x* flight_time ) / (flight_time* flight_time) );
}

