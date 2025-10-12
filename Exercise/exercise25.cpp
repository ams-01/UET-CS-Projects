#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.1416;
main() {
    double wireLength, radius, area;
    cout << "Enter the total length of the wire (in cm): ";
    cin >> wireLength;
    radius = wireLength / (2 * PI);
    area = PI * radius * radius;
    cout << fixed << setprecision(2);
    cout << "\nRadius of the circle: " << radius << " cm" << endl;
    cout << "Area of the circle: " << area << " square cm" << endl;
}
