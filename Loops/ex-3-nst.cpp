#include <iostream> 
using namespace std; 
main(){  
    for (int row = 4; row >= 0; row--){
        for (int space = row; space < 4; space++) 
            cout<<"  "; 
        for (int i = row; i > 0; i--) 
            cout<<" "<<"*"; 
    cout<<endl; 
    } 
} 