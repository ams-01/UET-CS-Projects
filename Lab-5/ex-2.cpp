#include<iostream>
using namespace std;
main(){
    char going;
    char lec;
    cout<<"Do you have a class (Enter y for yes)"<<endl;
    cin>>lec;
    cout<<"Are your friends going? (Enter y for yes)"<<endl;
    cin>>going;
    if(lec=='y'){
        if(going=='y'){
            cout<<"You are also going";
        }
    }
}