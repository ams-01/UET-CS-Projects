#include <iostream>
using namespace std;
int calculatePrice(int money, int year);

main(){
    int money, year;
    cout<<"Enter inherited money: "<<endl;
    cin>>money;
    cout<<"Enter the final year: "<<endl;
    cin>>year;

    int remainingMoney = calculatePrice(money, year);

    if (remainingMoney >= 0) {
        cout << "Yes! He will have "<<remainingMoney <<" dollars left."<<endl;
    } else {
        cout<<"He will need "<< -remainingMoney<<" more dollars."<<endl;
    }

    return 0;
}
int calculatePrice(int money, int year) {
    int age = 18;
    for (int currentYear = 1800; currentYear <= year; currentYear++) {
        if (currentYear % 2 == 0) {
            money -= 12000;
        } else {
            money -= (12000 + 50 * age);
        }
        age++;
    }

    return money;
}