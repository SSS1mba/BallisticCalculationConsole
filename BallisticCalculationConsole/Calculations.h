#pragma once
#include <math.h>
#include <iostream>

constexpr double g = 9.8;

//математическая модель
struct Parametrs
{
	const double start_velocity_;		 //начальная скорость броска
	const double angle_;				 //угол броска
	const double start_x_pos_;			 //начальная координата по оси x
	const double start_y_pos_;			 //начальная координата по оси y
	const double acceleration_x_  = 0;   //в классической баллистике движение по x - равномерное
	const double acceleration_y_;		 //в классической баллистике движение по y - равноускоренное

	const double start_velocity_x_ ;	 //начальная скорость по оси x
	const double start_velocity_y_;		 //начальная скорость по оси y
	const double lifting_time_;		     //изначально(от момента t=0 до момента t = lifting_time) ускорение направлено против оси y (acceleration_y_ < 0)
									          //но после (с t = lifting_time до конца полета t=(lifting_time * 2) ускорение сонаправлено с осью y (acceleration_y_ > 0)

	Parametrs(double start_velocity, double angle, double start_x_pos = 0, double start_y_pos = 0, double aсcelereation_y = g)

		:start_velocity_(start_velocity), angle_(angle) ,
		start_x_pos_(start_x_pos), start_y_pos_(start_y_pos),acceleration_y_(aсcelereation_y),
		start_velocity_x_(start_velocity_* cos(angle_)), start_velocity_y_(start_velocity_* sin(angle_)),
		lifting_time_ (start_velocity_y_ / acceleration_y_)    { }

	Parametrs(const Parametrs& other) :start_velocity_(other.start_velocity_), angle_(other.angle_),
		start_x_pos_(other.start_x_pos_), start_y_pos_(other.start_y_pos_),
		acceleration_x_(other.acceleration_x_), acceleration_y_(other.acceleration_y_),
		start_velocity_x_(other.start_velocity_x_), start_velocity_y_(other.start_velocity_y_), 
		lifting_time_ (other.lifting_time_) { }
};

//класс для работы с математической моделью
class Calculations
{
private:
	Parametrs parametrs_;
	double max_height_;		
	double flight_range_;
	double flight_time_;
	double fall_time_;
public:
	explicit Calculations(const Parametrs& parametrs) : parametrs_(parametrs)
	{
		flight_time_ = parametrs_.lifting_time_ * 2;
		max_height_ = calculate_y_pos(parametrs_.lifting_time_);
		flight_range_ = calculate_x_pos(flight_time_);
		fall_time_ = flight_time_;
	}

	inline double calculate_x_pos (double time)const
	{
		if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
		if (time >= flight_time_) return flight_range_;

		//x = x0 + V0x * t 
		return ( parametrs_.start_x_pos_ ) + ( parametrs_.start_velocity_x_ * time) ;
	}
	inline double calculate_velocity_x(double time)const
	{
		if (time < 0) throw std::invalid_argument("Calculations -> calculate_x_pos() -> (time < 0)");
		if (time >= flight_time_) return 0; //тело упало - не учитваем скорость ПОСЛЕ полета

		//Vx = V0x + ax * t
		return parametrs_.start_velocity_x_ + parametrs_.acceleration_x_ * time;
	}

	double calculate_y_pos(double time)const;
	double calculate_velocity_y(double time)const;

	inline int get_start_velocity() const noexcept
	{
		return parametrs_.start_velocity_;
	}
	inline int get_angle() const noexcept
	{
		return parametrs_.angle_;
	}
	inline double calculate_max_height()const noexcept
	{
		return max_height_;
	}
	inline double calculate_flight_range()const noexcept
	{
		return flight_range_;
	}

	inline double calculate_lifting_time()const noexcept
	{
		return parametrs_.lifting_time_;
	}
	inline double calculate_flight_time()const noexcept
	{
		return flight_time_;
	}
	inline double calculate_fall_time()const noexcept
	{
		return fall_time_;
	}
	
};

