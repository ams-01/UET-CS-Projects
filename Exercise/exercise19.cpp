#include <iostream>
using namespace std;
main() {
    int quarters, dimes, nickels, totalPennies;
    cout << "Enter the number of quarters: ";
    cin >> quarters;
    cout << "Enter the number of dimes: ";
    cin >> dimes;
    cout << "Enter the number of nickels: ";
    cin >> nickels;
    totalPennies = (quarters * 25) + (dimes * 10) + (nickels * 5);
    cout << "The total value of the coins is " << totalPennies << " pennies." << endl;
}
