#include<iostream>
using namespace std;
main(){
    string day;
    int purchaseAmount, discount, totalPayable;
    cout<<"Enter Purchcase amount"<<endl;
    cin>>purchaseAmount;
    cout<<"Enter the day"<<endl;
    cin>>day;
    if(day=="sunday")
    {
        if(purchaseAmount>=5000){
            discount=purchaseAmount*10/100;
        }
    }
    if(day!="sunday")
    {
        if(purchaseAmount>0){
            discount=purchaseAmount*5/100;
        }
    }
    
    totalPayable=purchaseAmount-discount;
    cout<<"Total amount after discount is: "<<totalPayable;
}