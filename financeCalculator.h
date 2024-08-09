#ifndef FINANCECALCULATOR_H
#define FINANCECALCULATOR_H
#include <vector>

class FinanceCalculator 
{
	private:
		double m_initialDeposit;
		double m_accountBalance;
		double m_monthlyDeposit;
		double m_interest;
		int m_years;

		double CalculateInterest();
		void FormatAccountBalanceWithDeposit(int years);
		void FormatAccountBalanceWithoutDeposit(int years);
		void SetMonthlyDeposit(double monthlyDeposit);
		void SetInterest(double interest);
		void SetYears(double years);
	
	public:
		void PrintAccountBalanceWithDeposit();
		void PrintAccountBalanceWithoutDeposit();
		void SetInitialMemberValues(std::vector<double> financeMembers);
		void MenuAction(int menuOption, double financeMember);
};

#endif
