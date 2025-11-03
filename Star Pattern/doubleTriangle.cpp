#include <iostream>
using namespace std;
main(){
    for (int i = 5; i >= 1; i -= 2) {
        for (int j = 5; j > i; j -= 2) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }

    cout<<"  *" << endl;

    for (int i = 3; i <= 5; i += 2) {
        for (int j = 5; j > i; j -= 2) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout<<endl;
    }
}
