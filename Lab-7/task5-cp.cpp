#include <iostream>
using namespace std;
int digitSum(int number);
main() {
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"The sum of digits in " <<num<< " is: " <<digitSum(num)<<endl;
}

int digitSum(int number) {
    int sum = 0;
    if (number < 0)
        number = -number;

    while (number != 0) {
        int digit = number % 10; 
        sum += digit;   
        number = number / 10;    
    }
    return sum;
}