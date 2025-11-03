#include <iostream>
using namespace std;
main() {
    for (int i = 1; i <= 4; i++)
    {
        for (int space = i; space < 4; space++) {
            cout << " ";
        }

        for (int star = 1; star <= (2 * i - 1); star++) {
            cout << "*";
        }
        cout << endl;
    }
}
