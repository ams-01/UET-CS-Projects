#include <iostream>
using namespace std;
int findGCD(int a, int b);
int findLCM(int a, int b);
main() {
    int num1, num2;
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;

    int gcd = findGCD(num1, num2);
    int lcm = findLCM(num1, num2);

    cout<<"GCD of "<<num1<<" and "<<num2<<" is: "<<gcd<<endl;
    cout<<"LCM of "<<num1<<" and "<<num2<<" is: "<<lcm<<endl;
}
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; 
}

int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}
