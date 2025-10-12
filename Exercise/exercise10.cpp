#include <iostream>
#include <cmath>
using namespace std;
main(){
    double num1, num2, num3, num4, num5,sum;
    int roundedSum;
    cout << "Enter five decimal numbers: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    sum = num1 + num2 + num3 + num4 + num5;
    roundedSum = round(sum);
    cout << "The sum rounded to the nearest integer is: " << roundedSum << endl;
}
