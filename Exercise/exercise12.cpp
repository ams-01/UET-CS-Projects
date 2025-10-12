#include<iostream>
using namespace std;
main(){
    int elap,hours, min,remsec, sec;
    cout<<"Enter the elapsed time"<<endl;
    cin>>elap;
    hours=elap/3600;
    remsec=elap%3600;
    min=remsec/60;
    sec=remsec%60;
    cout<<""<<hours<<":"<<min<<":"<<sec;
}