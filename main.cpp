#include <iostream>
#include "Budget.cpp"

std::string convertToLowercase(const std::string& string)
{
    std::string result;
    for (char character : string) {
        // Convert each character to lowercase using tolower
        result += std::tolower(character);
    }
    return result;
}
std::string Savings_Level(){
    std::string savings_level;
    std::cout << "How strict do you want to be with savings?" << std::endl
              << "Enter 'light' for light savings, 'regular' for average savings, or 'advanced' for extra savings: ";
    std::cin >> savings_level;
    savings_level = convertToLowercase(savings_level);
    
    if (savings_level != "light" && savings_level != "regular" && savings_level != "advanced"){
        std::cout << "invalid entry, options are light, regular, or advanced. Please try again. ";
        Savings_Level();
    } else {
        std::cout << "Savings level set to " << savings_level << "." << std::endl;
        return savings_level;
    }
}

void MakeBudget(){
    double income;
    double rent;
    int gas;
    std::string savings_level = Savings_Level();


    std::cout << "What is your monthly income?: ";
    std::cin >> income;
    std::cout << "What is your monthly rent?: ";
    std::cin >> rent;
    std::cout << "How many times per month do you get gas?: ";
    std::cin >> gas;
    Budget your_budget(income, rent, savings_level, gas);
    your_budget.CalculateTotalBudget();

}


int main() {

MakeBudget();



// Budget my_budget(6000, 2000, "regular", 5);
// my_budget.CalculateTotalBudget();

}