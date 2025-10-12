#include<iostream>
#include<cmath>
using namespace std;
const float CartonCapacity=3.78;
main(){
    float milkProduced,MilkCostperliter,MilkProfitpercarton, cartons,cost , profit;
    int roundedCartons;
    cout<<"Enter the total amount of milk produced in morning"<<endl;
    cin>>milkProduced;
    cout<<"Enter the cost of milk production per liter"<<endl;
    cin>>MilkCostperliter;
    cout<<"Enter the profit of milk per carton"<<endl;
    cin>>MilkProfitpercarton;
    cartons=milkProduced/CartonCapacity;
    roundedCartons=round(cartons);
    cost = milkProduced*MilkCostperliter;
    profit= MilkCostperliter*cartons;
    cout<<"Milk in liters: "<<milkProduced<<endl;
    cout<<"Cartons: "<<roundedCartons<<endl;
    cout<<"Cost: "<<cost<<endl;
    cout<<"Profit: "<<profit<<endl;
}