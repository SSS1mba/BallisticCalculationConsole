#include "ConsoleOutput.h"

void ConsoleOutput::calculate_and_print(const Calculations& calculation)
{
	double time_gaps,start_time,end_time;
	std::cout << "�������: ������ ����� ���������� � ������� ������ ������� � �������������� ������������� �������� �� ������� ����� ��������\n  ";
	std::cout << "������� ������������ ��������� \n";
	std::cin >> time_gaps;
	std::cout << "������� ������ �������\n";
	std::cin >> start_time;
	std::cout << "������� ����� �������\n";
	std::cin >> end_time;

	std::cout << "=============================================================\n";
	std::cout << "t\t|x\t|y\t|Vx\t|Vy\t|\n";
	for (int time = start_time; time += time_gaps; time <= end_time)
	{
		std::cout << time << "\t" << calculation.calculate_x_pos(time) << "\t" 
			<< calculation.calculate_y_pos(time) << "\t" << calculation.calculate_velocity_x(time) << 
			"\t" << calculation.calculate_velocity_y(time) << "\t\n";
		std::cout << "-------------------------------------------------------------\n";
	}
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "����� ������(L): \t" << calculation.calculate_flight_range() <<"\n";
	std::cout << "������������ ������ ������: \t" << calculation.calculate_max_height() << "\n";
	std::cout << "����� ������: \t" << calculation.calculate_flight_time() << "\n";
	std::cout << "����� �������: \t" << calculation.calculate_lifting_time() << "\n";
	std::cout << "����� ������: \t" << calculation.calculate_fall_time() << "\n";
	std::cout << "=============================================================\n";
}

void ConsoleOutput::add_new_Parametrs(std::vector<Calculations>& vector)  
{
	double start_velocity, angle, start_x_pos, start_y_pos;
	
	setlocale(LC_ALL, "russian");
	std::cout << "������� ��������� �������� \n";
	std::cin >> start_velocity;
	std::cout << "������� ���� ������\n";
	std::cin >> angle;
	std::cout << "������� ��������� ������� �� ��� x\n";
	std::cin >> start_x_pos;
	std::cout << "������� ��������� ������� �� ��� y \n";
	std::cin >> start_y_pos;

	vector.emplace_back(Parametrs(start_velocity, angle, start_x_pos, start_y_pos));
}