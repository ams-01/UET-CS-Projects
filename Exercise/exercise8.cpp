#include<iostream>
using namespace std;
const int SECRET =11;
const double RATE=12.50;
main(){
    int num1, num2,newNum,hoursworked;
    double wages;
    string name;
    cout<<"Enter the number 1"<<endl;
    cin>>num1;
    cout<<"Enter the number 2"<<endl;
    cin>>num2;
    cout<<"The value of num1 = "<<num1<<" and the value of num2 = "<<num2<<endl;
    newNum=num1*2+num2;
    cout<<"New Number is: "<<newNum<<endl;
    newNum=newNum+SECRET;
    cout<<"New Number after adding the SECRET value is: "<<newNum<<endl;
    cout<<"Enter the last name"<<endl;
    cin>>name;
    cout<<"Enter the decimal number between 0 and 70"<<endl;
    cin>>hoursworked;
    wages=RATE*hoursworked;
    cout<<"Name:"<<name<<endl;
    cout<<"Pay Rate:"<<RATE<<endl;
    cout<<"Hours Worked:"<<hoursworked<<endl;
    cout<<"Salary:"<<wages<<endl;

    
}