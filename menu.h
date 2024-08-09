#ifndef MENU_H 
#define MENU_H 
#include <iostream>
#include <string>
#include <vector>

class Menu 
{
	public:
		std::vector<double> IntakeData();
		double ParseMenuOption(int userOption);
		double ValidateInput(std::string inputParameter); 
		int GetMenuInput();
};

#endif
