#pragma once
#include <math.h>
#include <iostream>

constexpr double g = 9.8;

//�������������� ������
struct Parametrs
{
	const double start_velocity_;		 //��������� �������� ������
	const double angle_;				 //���� ������
	const double start_x_pos_;			 //��������� ���������� �� ��� x
	const double start_y_pos_;			 //��������� ���������� �� ��� y
	const double acceleration_x_  = 0;   //� ������������ ���������� �������� �� x - �����������
	const double acceleration_y_;		 //� ������������ ���������� �������� �� y - ���������������

	const double start_velocity_x_ ;	 //��������� �������� �� ��� x
	const double start_velocity_y_;		 //��������� �������� �� ��� y
	const double lifting_time_;		     //����������(�� ������� t=0 �� ������� t = lifting_time) ��������� ���������� ������ ��� y (acceleration_y_ < 0)
									          //�� ����� (� t = lifting_time �� ����� ������ t=(lifting_time * 2) ��������� ������������ � ���� y (acceleration_y_ > 0)

	Parametrs(double start_velocity, double angle, double start_x_pos = 0, double start_y_pos = 0, double a�celereation_y = g)

		:start_velocity_(start_velocity), angle_(angle) ,
		start_x_pos_(start_x_pos), start_y_pos_(start_y_pos),acceleration_y_(a�celereation_y),
		start_velocity_x_(start_velocity_* cos(angle_)), start_velocity_y_(start_velocity_* sin(angle_)),
		lifting_time_ (start_velocity_y_ / acceleration_y_)    { }

	Parametrs(const Parametrs& other) :start_velocity_(other.start_velocity_), angle_(other.angle_),
		start_x_pos_(other.start_x_pos_), start_y_pos_(other.start_y_pos_),
		acceleration_x_(other.acceleration_x_), acceleration_y_(other.acceleration_y_),
		start_velocity_x_(other.start_velocity_x_), start_velocity_y_(other.start_velocity_y_), 
		lifting_time_ (other.lifting_time_) { }
};

//����� ��� ������ � �������������� �������
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
		if (time >= flight_time_) return 0; //���� ����� - �� �������� �������� ����� ������

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

