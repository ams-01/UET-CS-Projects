#include <iostream>
using namespace std;
main(){
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j < 5; j++) {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 4; i >= 1; i--) {
        for (int j = 5; j > i; j--) {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
