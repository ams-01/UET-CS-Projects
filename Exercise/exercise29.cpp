#include <iostream>
#include <cmath> 
#include <iomanip> 
using namespace std;
main() {
    double cubicYards, thicknessInches, ratio;
    double cubicFeet, thicknessFeet, width, length;
    cout << "Enter the amount of premixed concrete (in cubic yards): ";
    cin >> cubicYards;
    cout << "Enter the thickness of the patio (in inches): ";
    cin >> thicknessInches;
    cout << "Enter the ratio of length to width: ";
    cin >> ratio;

    cubicFeet = cubicYards * 27;
    thicknessFeet = thicknessInches / 12.0;
    width = sqrt(cubicFeet / (ratio * thicknessFeet));
    length = ratio * width;

    cout << fixed << setprecision(2);
    cout << "The width of the patio is: " << width << " feet" << endl;
    cout << "The length of the patio is: " << length << " feet" << endl;
}
