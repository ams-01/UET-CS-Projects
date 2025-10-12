#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const double PAINT_COVERAGE = 120.0; 
    double length, width, height, doorLength, doorWidth, windowLength, windowWidth,shelfLength, shelfWidth;
    double  wallArea ,doorArea ,paintableArea,paintNeeded, windowArea, shelfArea;

    cout<<"Enter the length, width, and height of the room (in feet): "<<endl;
    cin>>length>> width >> height;
    cout<<"Enter the length and width of the door (in feet): "<<endl;
    cin>>doorLength>> doorWidth;
    cout<<"Enter the length and width of one window (in feet): "<<endl;
    cin>>windowLength >> windowWidth;
    cout<<"Enter the length and width of the bookshelf (in feet): "<<endl;
    cin>> shelfLength >> shelfWidth;

    wallArea = 2 * height * (length + width);
    doorArea = doorLength * doorWidth;
    windowArea = windowLength * windowWidth;
    shelfArea = shelfLength * shelfWidth;

    paintableArea = wallArea - (doorArea + 2 * windowArea + shelfArea);
    paintNeeded = paintableArea / PAINT_COVERAGE;

    cout << fixed << setprecision(2);
    cout << "Total wall area: " << wallArea << " sq ft" << endl;
    cout << "Paintable area (after subtracting door, windows, bookshelf): "<< paintableArea << " sq ft" << endl;
    cout << "Amount of paint needed: " << paintNeeded << " gallons" << endl;
}
