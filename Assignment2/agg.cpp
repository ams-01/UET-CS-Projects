#include<iostream>
using namespace std;
main()
{
    string name;
    float matric, inter, ecat,agg,ecatper,matricper,interper;
    cout<<"Enter your name"<<endl;
    cin>> name;
    cout<<"Enter matric marks"<<endl;
    cin>> matric;
    cout<<"Enter inter marks"<<endl;
    cin>> inter;
    cout<<"Enter ecat marks"<<endl;
    cin>> ecat;
    ecatper=ecat/400;
    interper=inter/560;
    matricper=matric/1100;
    agg=ecatper*50 + interper*40 +matricper*10;
    cout<<"Aggregate is"<<agg<<endl;
}
