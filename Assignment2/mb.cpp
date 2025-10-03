#include<iostream>
using namespace std;
main()
{
    int mb,bits,kb,bytes;
    cout<<"Enter the megabytes"<<endl;
    cin>> mb;
    kb=mb*1024;
    bytes=kb*1024;
    bits=bytes*8;
    cout<<"bits:"<<bits<<endl;
}
