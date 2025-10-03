#include<iostream>
using namespace std;
main()
{
    string team;
    int wins,draws,losses, totalpoints, winpoint, losspoint, drawpoint;
    cout << " enter the team name" <<endl;
    cin>> team;
    cout << " enter the wins" <<endl;
    cin>>wins;
    cout<<" enter the losses" <<endl;
    cin>>losses;
    cout<<" enter the draws" <<endl;
    cin>>draws;
    winpoint=wins*3;
    losspoint=losses*0;
    drawpoint=draws*1;
    totalpoints=winpoint+losspoint+drawpoint;
    cout<<"Points are:"<<totalpoints<<endl;
}
