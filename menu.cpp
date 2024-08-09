#include "menu.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// returned doubles so this function can validate both integer menu inputs and valid amounts
double Menu::ValidateInput(string inputParameter) 
{
  double userInput;
  cout << inputParameter;
  cin >> userInput;
  while (cin.fail()) 
	{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << inputParameter;
    cin >> userInput;
  }

  return userInput;
}

// returns an initial vector that will be passed directly into the finance calculator to set it's values
vector<double> Menu::IntakeData() 
{
  vector<double> financeCalculatorMembers;

  cout << "---------------------------Data Input---------------------------" << endl;
  cout << "Please input data as number values, e.g. XX.XX" << endl;
  cout << "Interest should be entered as a number," << endl;
  cout << "e.g. for 5% interest, enter 5 when prompted." << endl;
  financeCalculatorMembers.push_back(ValidateInput("Initital Investment Amount: $"));
  financeCalculatorMembers.push_back(ValidateInput("Monthly Deposit: $"));
  financeCalculatorMembers.push_back(ValidateInput("Annual Interest: "));
  financeCalculatorMembers.push_back(ValidateInput("Number Of Years: "));
	cout << "----------------------------------------------------------------" << endl;
	cout << endl << endl;

  return financeCalculatorMembers;
}

// checks for invalid menu options before returning the option into main scope
int Menu::GetMenuInput()
{
	int userOption;
	string inputParameter;
  inputParameter = "Please enter an option from the menu.\n[1] Change monthly deposit\n[2] Change interest rate\n[3] Change number of years\n[4] Exit program\nMenu Input: ";

	userOption = ValidateInput(inputParameter); 
	while (userOption < 1 && userOption > 4)
	{
		cout << "Please choose an option from the menu" << endl;
		userOption = ValidateInput(inputParameter);
	}

	return userOption;
}

// gets a double input based on the menu option, passed to the finance calculator to set the appropriate value
double Menu::ParseMenuOption(int userOption) 
{
	double financeMember = 0.0;
	string inputParameter;

	switch(userOption)
	{
		case 1:
			inputParameter = "Please enter a new monthly deposit in the form XX.XX\nMonthly Deposit: $";
			financeMember = ValidateInput(inputParameter);
			break;
		case 2:
			inputParameter = "Please enter a new interest rate.\nGive a single number for percentage e.g. enter 5 for 5%.\nInterest Rate: ";
			financeMember = ValidateInput(inputParameter);
			break;
		case 3:
			inputParameter = "Please enter a new amount of years.\nNumber of years: ";
			financeMember = ValidateInput(inputParameter);
			break;
		// 4 is the quit option, is checked for in the do/while loop in main
		case 4:
			cout << "Exiting Program" << endl;
			break;
		// default is here just in case, in theory, we should never reach the default option here, as it's handled in GetMenuInput()
		default:
			cout << "Please choose an option from the menu" << endl;
			break;
	}
	cout << endl << endl;

	return financeMember;
}

