#include<iostream>
using namespace std;
const double TAX_RATE = 0.14;
const double CLOTHES_RATE = 0.10;
const double SUPPLIES_RATE = 0.01;
const double SAVINGS_RATE = 0.25;
const double PARENTS_CONTRIBUTION = 0.50;
const int WEEKS = 5;
main(){
    double payRate, hoursPerWeek,grossIncome, netIncome, clothes, supplies, remaining, savings, parentsbonds;
    cout << "Enter your hourly pay rate: "<<endl;
    cin >>payRate;
    cout << "Enter the number of hours you worked each week: "<<endl;
    cin >> hoursPerWeek;
    grossIncome = payRate * hoursPerWeek * WEEKS;
    netIncome = grossIncome * (1 - TAX_RATE);
    clothes = netIncome * CLOTHES_RATE;
    supplies = netIncome * SUPPLIES_RATE;
    remaining = netIncome - (clothes + supplies);
    savings = remaining * SAVINGS_RATE;
    parentsbonds = savings * PARENTS_CONTRIBUTION;
    cout << "Income before taxes: " << grossIncome<<endl;
    cout << "Income after taxes:  " << netIncome<<endl;
    cout << "Money spent on clothes and accessories: " << clothes<<endl;
    cout << "Money spent on school supplies: " << supplies<<endl;
    cout << "Money spent on savings bonds: " << savings<<endl;
    cout << "Money parents spent on additional savings bonds: " << parentsbonds << endl;
}