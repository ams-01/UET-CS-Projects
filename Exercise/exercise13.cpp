#include <iostream>
using namespace std;
main() {
    double originalPrice, markUpPercent, taxRate, sellingPrice, salesTax, finalPrice;
    cout << "Enter the original price of the item: "<<endl;
    cin >> originalPrice;
    cout << "Enter the mark-up percentage: "<<endl;
    cin >> markUpPercent;
    cout << "Enter the sales tax rate: "<<endl;
    cin >> taxRate;    
    sellingPrice = originalPrice + (originalPrice * markUpPercent / 100);
    salesTax = sellingPrice * taxRate / 100;
    finalPrice = sellingPrice + salesTax;
     cout << "Original price: " << originalPrice << endl;
    cout << "Mark-up percentage: " << markUpPercent << "%" << endl;
    cout << "Selling price: " << sellingPrice << endl;
    cout << "Sales tax rate: " << taxRate << "%" << endl;
    cout << "Sales tax: " << salesTax << endl;
    cout << "Final price: " << finalPrice << endl;
}
