#include <iostream>
using namespace std;
void generateFib(int length);
int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;
    generateFib(n);
}

void generateFib(int length) {
    int first = 0, second = 1, next;
    for (int i = 1; i <= length; i++) {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}
