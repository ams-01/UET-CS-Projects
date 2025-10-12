#include <iostream>
#include <iomanip>
using namespace std;
const double k = 0.0000000667;
main() {
    double mass1, mass2, distance, force;
    cout<<"Enter the mass of the first body (in grams): ";
    cin>>mass1;
    cout<<"Enter the mass of the second body (in grams): ";
    cin>>mass2;
    cout<<"Enter the distance between the bodies (in centimeters): ";
    cin >> distance;
    force = k * (mass1 * mass2) / (distance*distance);
    cout << fixed << setprecision(6);
    cout << "\nThe gravitational force between the bodies is: "<< force << " dynes." << endl;
}
