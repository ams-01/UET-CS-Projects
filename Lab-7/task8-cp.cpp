#include <iostream>
using namespace std;
main() {
    int N;   
    double X, P;
    cout<<"Enter Lilly's age: ";
    cin>>N;
    cout<<"Enter price of washing machine: ";
    cin>>X;
    cout<<"Enter price per toy: ";
    cin>>P;

    int toyCount = 0;
    double savedMoney = 0;
    double moneyGift = 10.0;

    for (int age = 1; age <= N; age++) {
        if (age % 2 == 0) {
            savedMoney += moneyGift - 1;
            moneyGift += 10;            
        } else {
            toyCount++;
        }
    }

    savedMoney += toyCount * P;

    cout<<"Total money saved: "<<savedMoney<<endl;

    if (savedMoney >= X) {
        cout<<"Yes! Lilly can buy the washing machine."<<endl;
        cout<<"Money left after purchase: "<<savedMoney - X<<endl;
    } else {
        cout <<"No! Lilly needs "<<X - savedMoney<<" more."<<endl;
    }
    return 0;
}
