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

double GasMoney(){
    return 50 * _gas;
}

double CalculateIndividualBudget(double percent){
    double income_after_rent_gas = _income - (_rent + GasMoney());
    return income_after_rent_gas * percent;
}

void PrintBudget(double savings, double investings, double spendings, double miscellaneous){
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Save: $" << savings << " Invest: $" << investings
              << " Spending Money: $" << spendings << " Money for miscellaneous / extra: $"
              << miscellaneous;
}

void CalculateTotalBudget(){
    if (_savings_level == "light"){
        double savings = CalculateIndividualBudget(.10);
        double investings = CalculateIndividualBudget(.05);
        double spendings = CalculateIndividualBudget(.75);
        double miscellaneous = CalculateIndividualBudget(.10);
        PrintBudget(savings, investings, spendings, miscellaneous);

    } else if (_savings_level == "regular"){
        

    } else {
        
    }

}

//   Light Tier
// Saving: 10%
// Investing: 5%
// Spending: 75%
// Miscellaneous: 10%

// Regular Tier
// Saving: 20%
// Investing: 10%
// Spending: 60%
// Miscellaneous: 10%

// Extreme Tier
// Saving: 30%
// Investing: 20%
// Spending: 40%
// Miscellaneous: 10%

private:
double _income;
double _rent;
std::string _savings_level;
int _gas;



};