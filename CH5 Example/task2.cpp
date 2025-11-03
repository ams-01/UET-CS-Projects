#include <iostream>                                                                                                        
using namespace std;                                  
main()                                          
{                                               
    string name;                                
    int Volunteers, BoxesSold, totalBoxesSold, counter;                                       
    double costOfOneBox;                                 
    cout<<"Enter the number of volunteers:"<<endl;                            
    cin>>Volunteers;                                      
 
    totalBoxesSold = 0;                           
    counter = 0;                                      
 
    while (counter < Volunteers)                
    {                                                
        cout<<"Enter the volunteer's name and the number of boxes sold: ";  
        cin >> name >>BoxesSold;              
        cout << endl;                             
        totalBoxesSold = totalBoxesSold +BoxesSold;     
        counter++;                               
    }                                          
 
    cout << "The total number of boxes sold: "<< totalBoxesSold << endl;             
    cout << "Enter the cost of one box: ";   
    cin >> costOfOneBox;                              
    cout << endl;                                     
    cout <<"The total money made by selling cookies: "<< totalBoxesSold * costOfOneBox << endl;
 
    if (counter != 0)                                 
        cout<<"The average number of boxes sold by each volunteer: "<< totalBoxesSold / counter << endl;
    else                                                
        cout<<"No input." << endl;                                           
}   