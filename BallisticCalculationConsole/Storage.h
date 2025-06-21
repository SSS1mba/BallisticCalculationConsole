#pragma once
#include "Calculations.h"

//математическая модель
struct Parametrs
{
	const double start_velocity_;		 //начальная скорость броска
	const double angle_;				 //угол броска
	const double start_x_pos_ = 0;		 //начальная координата по оси x
	const double start_y_pos_;			 //начальная координата по оси y
	const double acceleration_x_;        //в классической баллистике движение по x - равномерное
	const double acceleration_y_;		 //в классической баллистике движение по y - равноускоренное

	const double start_velocity_x_ ;	 //начальная скорость по оси x
	const double start_velocity_y_;		 //начальная скорость по оси y
	const double lifting_time_;		     //изначально(от момента t=0 до момента t = lifting_time) ускорение направлено против оси y (acceleration_y_ < 0)
									          //но после (с t = lifting_time до конца полета t=(lifting_time * 2) ускорение сонаправлено с осью y (acceleration_y_ > 0)
	const double max_height_;
	const double flight_range_;
	const double flight_time_;
	const double fall_time_;

	Parametrs(const InputArr& input_arr)
	{
		if (input_arr.GET_calculated() != input_arr.GET_NUMBER_OF_ELEMENTS()) throw std::invalid_argument("Parametrs -> Parametrs(const InputArr& input_arr)");
	}
};

class Storage
{
public:
	void emplace(const InputArr& input_arr)
private:

};



////класс для работы с математической моделью - высчитывает параметры в зависимости от времени
//class Calculations
//{
//private:
//	Parametrs parametrs_;
//	
//public:
//	explicit Calculations(const Parametrs& parametrs) : parametrs_(parametrs)
//	{
//		flight_time_ = parametrs_.lifting_time_ * 2;
//		max_height_ = calculate_y_pos(parametrs_.lifting_time_);
//		flight_range_ = calculate_x_pos(flight_time_);
//		fall_time_ = flight_time_;
//	}
//
//	inline double calculate_x_pos (double time)const
//	{
//		if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
//		if (time > flight_time_) return flight_range_;
//
//		//x = x0 + V0x * t 
//		return ( parametrs_.start_x_pos_ ) + ( parametrs_.start_velocity_x_ * time) ;
//	}
//	inline double calculate_velocity_x(double time)const
//	{
//		if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
//		if (time >= flight_time_) return 0; //тело упало - не учитываем скорость ПОСЛЕ полета
//
//		//Vx = V0x + ax * t
//		return parametrs_.start_velocity_x_ + parametrs_.acceleration_x_ * time;
//	}
//
//	double calculate_y_pos(double time)const;
//	double calculate_velocity_y(double time)const;
//
//	inline double get_start_velocity() const noexcept
//	{
//		return parametrs_.start_velocity_;
//	}
//	inline double get_angle() const noexcept
//	{
//		return parametrs_.angle_;
//	}
//	inline double calculate_max_height()const noexcept
//	{
//		return max_height_;
//	}
//	inline double calculate_flight_range()const noexcept
//	{
//		return flight_range_;
//	}
//
//	inline double calculate_lifting_time()const noexcept
//	{
//		return parametrs_.lifting_time_;
//	}
//	inline double calculate_flight_time()const noexcept
//	{
//		return flight_time_;
//	}
//	inline double calculate_fall_time()const noexcept
//	{
//		return fall_time_;
//	}
//	
//};


