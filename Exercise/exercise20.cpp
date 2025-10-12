#include <iostream>
#include <iomanip>
using namespace std;
main() {
    double fixedCommission, commissionPercent, cost, minAddedAmount, maxAddedAmount, minSellingPrice, maxSellingPrice, minCommission, maxCommission;
    cout<<"Enter the salesperson's fixed commission: "<<endl;
    cin>>fixedCommission;
    cout<<"Enter the commission percentage: ";
    cin>>commissionPercent;
    cout<<"Enter the purchasing cost of the car: "<<endl;
    cin>>cost;
    cout<<"Enter the minimum amount to add to the cost: ";
    cin>>minAddedAmount;
    cout<<"Enter the maximum amount to add to the cost: ";
    cin>>maxAddedAmount;

    minSellingPrice = cost + minAddedAmount;
    maxSellingPrice = cost + maxAddedAmount;

    minCommission = fixedCommission + (commissionPercent / 100) * (minSellingPrice - cost);
    maxCommission = fixedCommission + (commissionPercent / 100) * (maxSellingPrice - cost);
     cout << fixed << setprecision(2);
    cout << "Minimum selling price: " << minSellingPrice << endl;
    cout << "Maximum selling price: " << maxSellingPrice << endl;
    cout << "Commission at minimum price: " << minCommission << endl;
    cout << "Commission at maximum price: " << maxCommission << endl;
}
