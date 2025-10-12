#include<iostream>
using namespace std;
main(){
    float capacity, pergallonmiles, miles;
    cout<<"Enter the capacity of fuel tank in gallons"<<endl;
    cin>>capacity;
    cout<<"Enter the miles per gallon automobile can be driven"<<endl;
    cin>>pergallonmiles;
    miles=pergallonmiles*capacity;
    cout<<""<<miles<<" number of miles the automobile can be driven without refueling.";
    
}