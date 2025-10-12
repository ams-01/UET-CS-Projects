#include<iostream>
#include<cmath>
using namespace std;
const float CartonCapacity=3.78;
const float MilkProfitpercarton=3.78;
const float MilkCostperliter=0.38;
main(){
    float milkProduced, cartons,cost , profit;
    int roundedCartons;
    cout<<"Enter the total amount of milk produced in morning"<<endl;
    cin>>milkProduced;
    cartons=milkProduced/CartonCapacity;
    roundedCartons=round(cartons);
    cost = milkProduced*MilkCostperliter;
    profit= MilkCostperliter*cartons;
    cout<<"Milk in liters: "<<milkProduced<<endl;
    cout<<"Cartons: "<<roundedCartons<<endl;
    cout<<"Cost: "<<cost<<endl;
    cout<<"Profit: "<<profit<<endl;
}