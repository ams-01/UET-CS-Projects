#include <iostream>
using namespace std;
main()
{
    int sum = 0, num;
    cin >>num;
    while (cin)
    {
        sum = sum +num; 
        cin >> num; 
    }
    cout << "Sum = "<<sum << endl;
}