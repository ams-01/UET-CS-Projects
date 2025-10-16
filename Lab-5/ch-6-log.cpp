#include<iostream>
using namespace std;
main(){
    string ticketType;
    int weight, cost;
    cout<<"Enter the type of ticket (b for business and e for economy)"<<endl;
    cin>>ticketType;
    cout<<"Enter the weight of luggage"<<endl;
    cin>>weight;
    if(ticketType=="b" && weight<=40){
            cost=15000;
    }

    if(ticketType=="b" && weight>40 ){
            cost=15000+((weight-40)*1000);
    }
    
    if(ticketType=="e" && weight<=25){
            cost=8000;
    }
    if(ticketType=="e" && weight>25){
            cost=15000+((weight-25)*1000);
    }

    cout<<"ticket type: " <<ticketType<<endl;
    cout<<"Weight of luggage: "<<weight<<endl;
    cout<<"Total cost: "<<cost<<endl;
}