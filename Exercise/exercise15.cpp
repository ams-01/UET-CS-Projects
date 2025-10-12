#include <iostream>
using namespace std;
const double PI = 3.141593;  
main() {
    double radius, price;        
    double area, pricePerSquareInch;
    cout<<"Enter the radius of the pizza (in inches): ";
    cin>>radius;
    cout<<"Enter the price of the pizza: ";
    cin>>price;
    area = PI * radius * radius;
    pricePerSquareInch = price / area;
    cout<<"The price per square inch is: "<<pricePerSquareInch<<endl;
}
