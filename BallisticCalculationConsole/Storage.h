#pragma once
#include "Calculations.h"

//�������������� ������
struct Parametrs
{
	const double start_velocity_;		 //��������� �������� ������
	const double angle_;				 //���� ������
	const double start_x_pos_ = 0;		 //��������� ���������� �� ��� x
	const double start_y_pos_;			 //��������� ���������� �� ��� y
	const double acceleration_x_;        //� ������������ ���������� �������� �� x - �����������
	const double acceleration_y_;		 //� ������������ ���������� �������� �� y - ���������������

	const double start_velocity_x_ ;	 //��������� �������� �� ��� x
	const double start_velocity_y_;		 //��������� �������� �� ��� y
	const double lifting_time_;		     //����������(�� ������� t=0 �� ������� t = lifting_time) ��������� ���������� ������ ��� y (acceleration_y_ < 0)
									          //�� ����� (� t = lifting_time �� ����� ������ t=(lifting_time * 2) ��������� ������������ � ���� y (acceleration_y_ > 0)
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



////����� ��� ������ � �������������� ������� - ����������� ��������� � ����������� �� �������
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
//		if (time >= flight_time_) return 0; //���� ����� - �� ��������� �������� ����� ������
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


