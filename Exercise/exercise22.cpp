#include <iostream>
#include <iomanip>
using namespace std;
const double POUNDS_PER_METRIC_TON = 2205; 
main() {
    double weightPerBag, numberOfBags;
    cout<<"Enter the amount of rice (in pounds) a bag can hold: ";
    cin>>weightPerBag;
    numberOfBags = POUNDS_PER_METRIC_TON / weightPerBag;
    cout << fixed << setprecision(2);
    cout << "\nNumber of bags needed to store one metric ton of rice: "<< numberOfBags << endl;
}