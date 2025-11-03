#include <iostream> 
using namespace std; 
main(){ 
    char ch; 
    for (int i = 0; i <= 5; i++){ 
        cout<<"Enter charactar :"; 
        cin>>ch; 
        if (ch == 'n') 
            return 0;
    } 
} 