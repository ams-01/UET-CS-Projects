#include <iostream>
#include <iomanip> 
using namespace std;
const double SERVICE_CHARGE_RATE = 0.015;
main() {
    int numShares;
    double purchasePrice, sellingPrice, amountInvested, purchaseServiceCharge, totalPurchaseCost, amountReceived, sellingServiceCharge, netAfterSell, gainOrLoss;
    cout << "Enter the number of shares sold: "<<endl;
    cin >> numShares;
    cout << "Enter the purchase price per share: "<<endl;
    cin >> purchasePrice;
    cout << "Enter the selling price per share: "<<endl;
    cin >> sellingPrice;

    amountInvested = numShares * purchasePrice;
    purchaseServiceCharge = amountInvested * SERVICE_CHARGE_RATE;
    totalPurchaseCost = amountInvested + purchaseServiceCharge;
    amountReceived = numShares * sellingPrice;
    sellingServiceCharge = amountReceived * SERVICE_CHARGE_RATE;
    netAfterSell = amountReceived - sellingServiceCharge;
    gainOrLoss = netAfterSell - totalPurchaseCost;

    cout<<fixed<<setprecision(2);
    cout<<"Amount invested: "<<amountInvested <<endl;
    cout<<"Service charge on purchase: "<<purchaseServiceCharge <<endl;
    cout<<"Total amount spent (including service charges): "<<totalPurchaseCost<<endl;
    cout<<"Amount received from sale:  " <<amountReceived<<endl;
    cout<<"Service charge on sale: " <<sellingServiceCharge<<endl;
    cout<<"Net amount after selling: " <<netAfterSell <<endl;
    if(gainOrLoss>=0){
        cout<<"Overall Gain "<< gainOrLoss << endl;
    }
    else{
        cout<<"Overall loss "<< gainOrLoss << endl;
    }
}
