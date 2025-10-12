#include<iostream>
using namespace std;
main(){
    double actualHardSize,bytes, manufacturerHardSize;
    cout<<"Enter the Hard drive size given from the manufacturer"<<endl;
    cin>>manufacturerHardSize;
    bytes=manufacturerHardSize*1000000000;
    actualHardSize=bytes/(1024*1024*1024);
    cout<<"Actual hard drive size in GB is: "<<actualHardSize;
}