#include "menu.h"
#include "financeCalculator.h"

using namespace std;

int main() 
{
	Menu MainMenu;
	FinanceCalculator DepositCalculator;
	int userOption;
	double financeMember;
	DepositCalculator.SetInitialMemberValues(MainMenu.IntakeData());

	do
	{
		DepositCalculator.PrintAccountBalanceWithoutDeposit();
		DepositCalculator.PrintAccountBalanceWithDeposit();
		userOption = MainMenu.GetMenuInput();
		financeMember = MainMenu.ParseMenuOption(userOption);
		DepositCalculator.MenuAction(userOption, financeMember);
	} while (userOption != 4);

	return 0;
}
