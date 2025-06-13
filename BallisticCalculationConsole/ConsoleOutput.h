#pragma once

#include <vector>
#include "Calculations.h"

static class ConsoleOutput
{
public:
	static void calculate_and_print(const Calculations& calculation) ;
	static void add_new_Parametrs (std::vector<Calculations>& vector);
};

