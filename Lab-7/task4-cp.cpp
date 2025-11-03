#include <iostream>
using namespace std;
main() {
    int number, digit;
    int count = 0;
    cout<<"Enter a number: ";
    cin>>number;
    cout<<"Enter the digit whose frequency you want to find: ";
    cin>>digit;

    int temp = number;

    while (temp != 0) {
        int rem = temp % 10;
        if (rem == digit) {
            count++;
        }
        temp = temp / 10;
    }
    cout << "The frequency of " << digit << " in " << number << " is: " << count << endl;

}
