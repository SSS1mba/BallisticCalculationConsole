#pragma once
#include "Storage.h"
#include <math.h>
#include <iostream>


inline double degrees_in_radians(double angle_grad)  noexcept
{
	return angle_grad * PI / 180.0;
}
constexpr double g = 9.8;
constexpr double PI = 3.14159265358979323846;


/*		ТАБЛИЦА СОПОСТАВЛЕНИЯ	(для массивов		is_known_parametr_arr_	и	parametrs_arr_ )
* 0  - const double start_velocity_;		 //начальная скорость броска
  1  - const double angle_;				     //угол броска
     - const double start_x_pos_ = 0;		 //начальная координата по оси x - ВСЕГДА БУДЕТ 0 - поэтому вводить здесь нет смысла
  2  - const double start_y_pos_;			 //начальная координата по оси y
  3  - const double acceleration_x_  ;       //в классической баллистике движение по x - равномерное
  4  - const double acceleration_y_;		 //в классической баллистике движение по y - равноускоренное
  5  - const double start_velocity_x_ ;	     //начальная скорость по оси x
  6  - const double start_velocity_y_;		 //начальная скорость по оси y
  7  - double max_height_;
  8  - double flight_range_;
  9  - const double lifting_time_;		     //изначально(от момента t=0 до момента t = lifting_time) ускорение направлено против оси y (acceleration_y_ < 0)
											 //но после (с t = lifting_time до конца полета t=(flight_time) ускорение сонаправлено с осью y (acceleration_y_ > 0)
  10 - double fall_time_;
  11 - double flight_time_;
*/
class InputArr
{
public:
	InputArr() : calculated_(0)
	{
		parametrs_arr_ = new double[NUMBER_OF_ELEMENTS];
		is_known_parametr_arr_ = new bool[NUMBER_OF_ELEMENTS];
		for (size_t i = 0; i < NUMBER_OF_ELEMENTS; ++i)		{ is_known_parametr_arr_[i] = false; }
	}
	~InputArr() 
	{
		delete[] parametrs_arr_;
		delete[] is_known_parametr_arr_ ;
	}

	//Сеттеры - для ввода из Input и для установления при Calculations
	inline void SET_start_velocity(double data) noexcept
	{
		parametrs_arr_		  [0] = data;
		is_known_parametr_arr_[0] = true;
		++calculated_;
	}
	inline void SET_angle(double data) noexcept
	{
		parametrs_arr_		  [1] = data;
		is_known_parametr_arr_[1] = true;
		++calculated_;
	}
	inline void SET_start_y_pos(double data) noexcept
	{
		parametrs_arr_		  [2] = data;
		is_known_parametr_arr_[2] = true;
		++calculated_;
	}
	inline void SET_acceleration_x(double data) noexcept
	{
		parametrs_arr_		  [3] = data;
		is_known_parametr_arr_[3] = true;
		++calculated_;
	}
	inline void SET_acceleration_y(double data) noexcept
	{
		parametrs_arr_		  [4] = data;
		is_known_parametr_arr_[4] = true;
		++calculated_;
	}
	inline void SET_start_velocity_x(double data) noexcept
	{
		parametrs_arr_		  [5] = data;
		is_known_parametr_arr_[5] = true;
		++calculated_;
	}
	inline void SET_start_velocity_y(double data) noexcept
	{
		parametrs_arr_		  [6] = data;
		is_known_parametr_arr_[6] = true;
		++calculated_;
	}
	inline void SET_max_height(double data) noexcept
	{
		parametrs_arr_		  [7] = data;
		is_known_parametr_arr_[7] = true;
		++calculated_;
	}
	inline void SET_flight_range(double data) noexcept
	{
		parametrs_arr_		  [8] = data;
		is_known_parametr_arr_[8] = true;
		++calculated_;
	}
	inline void SET_lifting_time(double data) noexcept
	{
		parametrs_arr_		  [9] = data;
		is_known_parametr_arr_[9] = true;
		++calculated_;
	}
	inline void SET_fall_time_(double data) noexcept
	{
		parametrs_arr_		  [10] = data;
		is_known_parametr_arr_[10] = true;
		++calculated_;
	}
	inline void SET_flight_time(double data) noexcept
	{
		parametrs_arr_		  [11] = data;
		is_known_parametr_arr_[11] = true;
		++calculated_;
	}

	//Чеккеры - для проверки в Calculations
	inline bool CHECK_start_velocity(double data) const noexcept
	{
		return is_known_parametr_arr_[0];
	}
	inline bool CHECK_angle(double data) const noexcept
	{
		return is_known_parametr_arr_[1];
	}
	inline bool CHECK_start_y_pos(double data) const
	{
		return is_known_parametr_arr_[2];
	}
	inline bool CHECK_acceleration_x(double data) const noexcept
	{
		return is_known_parametr_arr_[3];
	}
	inline bool CHECK_acceleration_y(double data) const noexcept
	{
		return is_known_parametr_arr_[4];
	}
	inline bool CHECK_start_velocity_x(double data) const noexcept
	{
		return is_known_parametr_arr_[5];
	}
	inline bool CHECK_start_velocity_y(double data) const noexcept
	{
		return is_known_parametr_arr_[6];
	}
	inline bool CHECK_max_height(double data) const noexcept
	{
		return is_known_parametr_arr_[7];
	}
	inline bool CHECK_flight_range(double data) const noexcept
	{
		return is_known_parametr_arr_[8];
	}
	inline bool CHECK_lifting_time(double data) const noexcept
	{
		return is_known_parametr_arr_[9];
	}
	inline bool CHECK_fall_time_(double data) const noexcept
	{
		return is_known_parametr_arr_[10];
	}
	inline bool CHECK_flight_time(double data) const noexcept
	{
		return is_known_parametr_arr_[11];
	}

	//Геттеры - для Parametrs
	inline double GET_start_velocity() const noexcept
	{
		return parametrs_arr_[0];
	}
	inline double GET_angle() const noexcept
	{
		return parametrs_arr_[1];
	}
	inline double GET_start_y_pos() const
	{
		return parametrs_arr_[2];
	}
	inline double GET_acceleration_x() const noexcept
	{
		return parametrs_arr_[3];
	}
	inline double GET_acceleration_y() const noexcept
	{
		return parametrs_arr_[4];
	}
	inline double GET_start_velocity_x() const noexcept
	{
		return parametrs_arr_[5];
	}
	inline double GET_start_velocity_y() const noexcept
	{
		return parametrs_arr_[6];
	}
	inline double GET_max_height() const noexcept
	{
		return parametrs_arr_[7];
	}
	inline double GET_flight_range() const noexcept
	{
		return parametrs_arr_[8];
	}
	inline double GET_lifting_time() const noexcept
	{
		return parametrs_arr_[9];
	}
	inline double GET_fall_time_() const noexcept
	{
		return parametrs_arr_[10];
	}
	inline double GET_flight_time() const noexcept
	{
		return parametrs_arr_[11];
	}

	inline size_t GET_NUMBER_OF_ELEMENTS() const noexcept
	{
		return NUMBER_OF_ELEMENTS;
	}
	inline size_t GET_calculated() const noexcept
	{
		return calculated_;
	}

private:
	double* parametrs_arr_;
	bool*   is_known_parametr_arr_;
	size_t  calculated_;
	static constexpr size_t NUMBER_OF_ELEMENTS = 12;
};


//кастомное исключение
class ImposibleCalculation : public std::runtime_error
{
public:
	ImposibleCalculation()							: std::runtime_error("This system cant be calculated :( ")				{}
	ImposibleCalculation(const std::string message) : std::runtime_error("This system cant be calculated :( \n" + message )	{}
};
static class Calculator
{
public:
	void calculate_and_add(InputArr& input_arr,  Storage& storage ) const
	{
		if (!calculate(input_arr)) throw ImposibleCalculation("Calculations -> Calculator -> calculate_and_add()");
		storage.emplace(input_arr);
	}
private:
	bool calculate(InputArr& input_arr) const noexcept;

	Calculator() = delete;
	~Calculator() = delete;
};























