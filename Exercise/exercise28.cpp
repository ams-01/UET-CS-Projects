#include <iostream>
#include <iomanip>
using namespace std;
main() {
    int numStudents;
    double caloriesPerStudent, caloriesPerPoundNuts, caloriesPerPoundFruit, totalCalories, totalMixtureLbs, nutsLbs, fruitLbs;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout << "Enter the number of calories required per student: ";
    cin >> caloriesPerStudent;
    cout << "Enter the number of calories in each pound of nuts: ";
    cin >> caloriesPerPoundNuts;
    
    caloriesPerPoundFruit = caloriesPerPoundNuts / 0.70;
    totalCalories = numStudents * caloriesPerStudent;

    double caloriesPerPoundMixture = 0.5 * (caloriesPerPoundNuts + caloriesPerPoundFruit);
    totalMixtureLbs = totalCalories / caloriesPerPoundMixture;
    nutsLbs = totalMixtureLbs / 2;
    fruitLbs = totalMixtureLbs / 2;

    cout << fixed << setprecision(2);
    cout << "Total calories required: " << totalCalories << " cal" << endl;
    cout << "Calories per pound of dried fruit: " << caloriesPerPoundFruit << " cal" << endl;
    cout << "Total mixture needed: " << totalMixtureLbs << " lbs" << endl;
    cout << "Amount of nuts needed: " << nutsLbs << " lbs" << endl;
    cout << "Amount of dried fruit needed: " << fruitLbs << " lbs" << endl;
}
