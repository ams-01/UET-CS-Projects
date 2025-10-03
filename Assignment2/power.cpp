#include<iostream>
using namespace std;
main()
{
    float current, volt, power;
    cout<<"Enter the voltage in volts"<<endl;
    cin>> volt;
    cout<<"Enter the current in ampere"<<endl;
    cin>> current;
    power=volt*current;
    cout<<"Power is :"<<power<<endl;
}
