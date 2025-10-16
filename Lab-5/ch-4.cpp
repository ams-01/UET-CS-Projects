#include<iostream>
using namespace std;
main(){
    string day, month;
    int purchaseAmount, discount, totalPayable;
    cout<<"Enter Purchcase amount"<<endl;
    cin>>purchaseAmount;
    cout<<"Enter the day"<<endl;
    cin>>day;
    cout<<"Enter the month"<<endl;
    cin>>month;
    if(day=="sunday")
    {
        if(month=="october" || month=="august" || month=="march"){
            discount=purchaseAmount*10/100;
        }
    }
    if(day=="monday")
    {
        if(month=="november" || month=="december"){
            discount=purchaseAmount*5/100;
        }
    }
    totalPayable=purchaseAmount-discount;
    cout<<"Total amount after discount is: "<<totalPayable;
}