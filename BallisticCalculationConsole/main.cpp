#include "ConsoleOutput.h"


void console_menu()
{
    std::cout << "Выберите действие:\n";
    std::cout << "1 - Создать математическую модель\n";
    std::cout << "2 - Просчитать математическую модель\n";
    std::cout << "0 - выход из программмы\n";
}
int chose_menu(const std::vector<Calculations>& storage)
{
    if (storage.empty())
    {
        std::cout << "У вас не создано НИ ОДНОЙ математической модели\n";
        return -1;
    }
    else
    {
        int index = 0;
        for (;index < storage.size();index++)
        {
            std::cout << "индекс " << index << "\n";
            std::cout << "начальная скорость : " << storage[index].get_start_velocity() << "\n";
            std::cout << "угол броска : " << storage[index].get_angle()<<"\n";
            std::cout << "---------------------------------------------------------\n";
        }
        std::cout << "Выберите индекс\n";
        std::cin >> index;
        if (index >= storage.size() || index < 0) return -1;

        return index;
    }
}

int main()
{
    std::vector<Calculations> storage;
    int chose ;
    setlocale(LC_ALL, "Russian");

    do
    {
      console_menu();
      std::cin >> chose;
      switch (chose)
      {
      case 0:
      {
          std::cout << "Конец программы\n";
          break;
      }
      case 1:
      {
          ConsoleOutput::add_new_parametrs(storage);
          break;
      }
      case 2:
      {
          chose = chose_menu(storage);
          if (chose != -1 ) ConsoleOutput::calculate_and_print(storage[chose]);
          break;
      }
      }
    } while (chose != 0);

    return 0;
}
