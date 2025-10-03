#include<iostream>
using namespace std;
main()
{
    int curpopulation, birthrate, decade;
    cout<<"Enter the current population"<<endl;
    cin>>curpopulation;
    cout<<"Enter the birth rate"<<endl;
    cin>>birthrate;
    decade=curpopulation+birthrate*360;
    cout<<"The population in 3 decades will be:"<<decade<<endl;

}
