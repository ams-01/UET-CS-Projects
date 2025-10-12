#include <iostream>
#include <iomanip>
using namespace std;
main(){
    double length, width, height;
    double doorLength, doorWidth, windowLength, windowWidth, shelfLength, shelfWidth, paintCoverage;
    cout << "Enter the length, width, and height of the room (in feet): "<< endl;
    cin >> length >> width >> height;
    cout << "Enter the length and width of the door (in feet): "<< endl;
    cin >> doorLength >> doorWidth;
    cout << "Enter the length and width of one window (in feet): "<< endl;
    cin >> windowLength >> windowWidth;
    cout << "Enter the length and width of the bookshelf (in feet): "<< endl;
    cin >> shelfLength >> shelfWidth;
    cout << "Enter the area (in square feet) that can be painted with one gallon of paint: "<< endl;
    cin >> paintCoverage;

    double wallArea = 2 * height * (length + width);
    double doorArea = doorLength * doorWidth;
    double windowArea = windowLength * windowWidth;
    double shelfArea = shelfLength * shelfWidth;
    double paintableArea = wallArea - (doorArea + 2 * windowArea + shelfArea);
    double paintNeeded = paintableArea / paintCoverage;

    cout << fixed << setprecision(2);
    cout << "Total wall area: " << wallArea << " sq ft" << endl;
    cout << "Paintable area (after subtracting door, windows, bookshelf): " << paintableArea << " sq ft" << endl;
    cout << "Amount of paint needed: " << paintNeeded << " gallons" << endl;
}
