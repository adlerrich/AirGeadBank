#include "financeCalculator.h"
#include <ios>
#include <iostream>
#include <iomanip>

using namespace std;

// specific set functions kept private, as to only expose the MenuAction function
void FinanceCalculator::SetMonthlyDeposit(double monthlyDeposit)
{
	this->m_monthlyDeposit = monthlyDeposit;
}

void FinanceCalculator::SetInterest(double interest)
{
	this->m_interest = interest;
}

void FinanceCalculator::SetYears(double years)
{
	this->m_years = years;
}

// takes the input from menu's GetMenuInput() and ParseMenuInput() to set the appropriate member variable to the user's input
void FinanceCalculator::MenuAction(int menuOption, double financeMember)
{
	switch (menuOption)
	{
		case 1: 
			SetMonthlyDeposit(financeMember);
			break;
		case 2:
			SetInterest(financeMember / 100);
			break;
		case 3:
			SetYears(financeMember);
			break;
		// 4 is the quit option, no action needs to be taken if the user chooses to exit the program
		case 4:
			break;
		// default is here just in case, it should not be possible to reach this point in the switch statement
		default:
			cout << "Error: Should not be possible to pass invalid option into this function.";
			break;
	}
}

// this is only used once to intake the initial data as a vector, so as to keep most data modifying functions private
void FinanceCalculator::SetInitialMemberValues(vector<double> financeMembers) 
{
	this->m_initialDeposit = financeMembers.at(0);
	this->m_monthlyDeposit = financeMembers.at(1);
	this->m_interest = financeMembers.at(2) / 100;
	this->m_years = financeMembers.at(3);

}

double FinanceCalculator::CalculateInterest() 
{
	return this->m_accountBalance * (this->m_interest / 12);
}

// helper function to format account balance for printing with deposit
void FinanceCalculator::FormatAccountBalanceWithDeposit(int years)
{
	this->m_accountBalance += this->m_monthlyDeposit * 12;
	double accruedInterest = CalculateInterest(); 
	this->m_accountBalance += accruedInterest; 
	cout << fixed;
	cout << setprecision(2);
	cout << years << "\t\t   $" << this-> m_accountBalance << "\t\t\t$" << accruedInterest << endl;
}

// helper function to format account balance for printing without deposit
void FinanceCalculator::FormatAccountBalanceWithoutDeposit(int years)
{
	double accruedInterest = CalculateInterest(); 
	this->m_accountBalance += accruedInterest; 
	cout << fixed;
	cout << setprecision(2);
	cout << years << "\t\t   $" << this-> m_accountBalance << "\t\t\t$" << accruedInterest << endl;
}

void FinanceCalculator::PrintAccountBalanceWithDeposit()
{
	// reset the account balance every time the print function is called to avoid printing incorrect information
	this->m_accountBalance = this->m_initialDeposit;
	cout << "-----------------Monthly Balance Without Deposit----------------" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;

	for (int i = 0; i < this->m_years; ++i)
	{
		// passing i + 1 correctly displays the year 
		FormatAccountBalanceWithDeposit(i + 1);
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << endl << endl;
}

void FinanceCalculator::PrintAccountBalanceWithoutDeposit()
{
	// reset the account balance every time the print function is called to avoid printing incorrect information
	this->m_accountBalance = this->m_initialDeposit;
	cout << "------------------Monthly Balance With Deposit------------------" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;

	for (int i = 0; i < this->m_years; ++i)
	{
		// passing i + 1 correctly displays the year 
		FormatAccountBalanceWithoutDeposit(i + 1);
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << endl << endl;
}
