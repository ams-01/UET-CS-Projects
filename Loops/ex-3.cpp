#include <iostream> 
using namespace std; 
main(){ 
    int sum = 0; 
    for (int i = 5; i <= 50; i += 3) { 
        sum += i; 
    } 
    cout << "The sum is: " << sum << endl; 
}