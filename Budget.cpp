#include <iostream>
#include <iomanip>

class Budget{

public:

// constructor
Budget(double income, double rent, std::string savings_level, int gas) : 
_income(income), _rent(rent), _savings_level(savings_level), _gas(gas) {}

// modifiers
void SetIncome(double income){ _income = income; }
void SetRent(double rent){ _rent = rent; }
void SetSavingsLevel(std::string savings_level){ _savings_level = savings_level; }
void SetGas(int gas){ _gas = gas; }

// accessors
double GetIncome(){ return _income; }
double GetRent(){ return _rent; }
std::string GetSavingsLevel(){ return _savings_level; }
int GetGas(){ return _gas; }

// multiply $50 times how many times user gets gas per month
double GasMoney(){
    return 50 * _gas;
}

// calculate each individual budget (savings, investings, etc.)
double CalculateIndividualBudget(double percent){
    double income_after_rent_gas = _income - (_rent + GasMoney());
    return income_after_rent_gas * percent;
}

// print the users calculated budget
void PrintBudget(double savings, double investings, double spendings, double miscellaneous){
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Pay Rent: $" << _rent << std::endl << "Gas Money: $" << GasMoney() 
                << std::endl << "Save: $" << savings << std::endl << "Invest: $" 
                << investings << std::endl << "Spending Money (For things you NEED or WANT): $" 
                << spendings << std::endl << "Money for miscellaneous / extra: $"
                << miscellaneous << std::endl;
}

// calculate total budget, for light, regular, or advanced
void CalculateTotalBudget(){
    if (_savings_level == "light"){
        double savings = CalculateIndividualBudget(.10);
        double investings = CalculateIndividualBudget(.05);
        double spendings = CalculateIndividualBudget(.75);
        double miscellaneous = CalculateIndividualBudget(.10);
        PrintBudget(savings, investings, spendings, miscellaneous);

    } else if (_savings_level == "regular"){
        double savings = CalculateIndividualBudget(.20);
        double investings = CalculateIndividualBudget(.10);
        double spendings = CalculateIndividualBudget(.60);
        double miscellaneous = CalculateIndividualBudget(.10);
        PrintBudget(savings, investings, spendings, miscellaneous);

    } else {
        double savings = CalculateIndividualBudget(.30);
        double investings = CalculateIndividualBudget(.20);
        double spendings = CalculateIndividualBudget(.40);
        double miscellaneous = CalculateIndividualBudget(.10);
        PrintBudget(savings, investings, spendings, miscellaneous);
    }

}

private:
double _income;
double _rent;
std::string _savings_level;
int _gas;

};