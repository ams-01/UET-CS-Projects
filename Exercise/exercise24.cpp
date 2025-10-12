#include <iostream>
#include <iomanip>
using namespace std;
main(){
    double wireLength, width, length;
    cout<<"Enter the total length of the wire (in cm): ";
    cin>>wireLength;
    width = wireLength / 5;
    length = 1.5 * width;
    cout<<fixed<<setprecision(2);
    cout<<"\nWidth of the picture frame: "<<width<<" cm"<<endl;
    cout<<"Length of the picture frame: "<<length<<" cm"<<endl;
}
