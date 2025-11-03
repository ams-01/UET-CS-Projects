#include <iostream>
using namespace std;
main() {
    int n;
    cout<<"Enter how many numbers you will input (n): ";
    cin>>n;
    int number;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> number;

        if (number < 200)
            c1++;
        else if (number < 400)
            c2++;
        else if (number < 600)
            c3++;
        else if (number < 800)
            c4++;
        else
            c5++;
    }
    double p1 = (c1 * 100.0) / n;
    double p2 = (c2 * 100.0) / n;
    double p3 = (c3 * 100.0) / n;
    double p4 = (c4 * 100.0) / n;
    double p5 = (c5 * 100.0) / n;

    cout<< "\nPercentage under 200: "<<p1 <<"%"<<endl;
    cout<< "Percentage 200-399: "<<p2 <<"%"<<endl;
    cout<< "Percentage 400-599: "<<p3 <<"%"<<endl;
    cout<< "Percentage 600-799: "<<p4 <<"%"<<endl;
    cout<< "Percentage 800 and above: "<<p5<<"%"<<endl;
    return 0;
}
