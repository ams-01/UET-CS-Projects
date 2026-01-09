#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <algorithm>
using namespace std;

void loginBlock(int &count);
void UI();
void adminUI();
void userUI();
void storeUI();
void passwordReset(int &totalUsers, int &totalStores, string usernameArr[], string passwordArr[], string storeUsernameArr[], string storePasswordArr[]);
void pause();
void userLogin(
    int &totalUsers,
    int &count,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[],

    // STORE DATA
    int totalStores,
    string storeNameStoreArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],
    int storeMedPrice[][50],

    // ORDER DATA
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders);

bool isValidnum(string s);

void userSignUp(
    string nameArr[], string usernameArr[], string passwordArr[],
    int blockArr[], long long CNICarr[],
    string addressArr[], string cityArr[], string townArr[],
    int &totalUsers);

void newStore(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[]);

void userPanel(
    int userIndex,
    string nameArr[], string usernameArr[], string passwordArr[],
    int blockArr[], long long CNICarr[],
    string addressArr[], string cityArr[], string townArr[],
    int &totalUsers,

    // STORE DATA
    int totalStores,
    string storeNameStoreArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],
    int storeMedPrice[][50],

    // ORDER DATA
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders);

void adminPanel(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[],
    int &totalUsers,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[]);

void storeLogin(
    string storeUsernameArr[],
    string storePasswordArr[],
    int &totalStores,
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    int storeMedPrice[][50],

    // MEDICINES
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],

    // ORDERS
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders,

    string addressArr[],
    string cityArr[],
    string townArr[],
    int blockArr[]);

void storePanel(
    int storeIndex,
    int &totalStores,
    string storePasswordArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    int storeMedPrice[][50],

    // MEDS
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],

    // ORDERS
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders,

    // USERS
    string addressArr[],
    string cityArr[],
    string townArr[],
    int blockArr[]);

void saveUsers(
    int &totalUsers,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[]);

void loadUsers(
    int &totalUsers,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[]);

void saveStores(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[]);

void loadStores(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[]);

int locationScore(
    int uBlock, string uTown, string uCity,
    int sBlock, string sTown, string sCity);

bool storeHasMedicine(
    int storeIndex,
    string medName,
    int qty,
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[]);

void saveStoreMedicines(
    int totalStores,
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedPrice[][50],
    int storeMedCount[]);

void loadStoreMedicines(
    int &totalStores,
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedPrice[][50],
    int storeMedCount[]);

void saveOrders(
    int totalOrders,
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[]);

void loadOrders(
    int &totalOrders,
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[]);

bool isUsernameTaken(string username, string arr[], int totalCount);

void showMedicinesByUserTown(
    string userTown,
    int totalStores,
    string storeNameStoreArr[],
    string storeTownArr[],
    string storeMedName[][50],
    string storeMedType[][50],
    int storeMedQty[][50],
    int storeMedPrice[][50],
    int storeMedCount[]);

bool isValidName(const string &name);

int main()
{

    // USER ARRAYS
    int count = 0;
    string nameArr[200];
    string usernameArr[200];
    string passwordArr[200];
    int blockArr[200];
    long long CNICarr[200];
    string addressArr[200];
    string cityArr[200];
    string townArr[200];
    int totalUsers = 0;

    // STORE ARRAYS
    string storeNameStoreArr[200];
    string storeUsernameArr[200];
    string storePasswordArr[200];
    int storeBlockArr[200];
    string storeAddressArr[200];
    string storeCityArr[200];
    string storeTownArr[200];
    int totalStores = 0;
    int storeMedPrice[200][50];

    // MEDICINE ARRAYS
    string storeMedType[200][50];
    string storeMedName[200][50];
    int storeMedQty[200][50];
    int storeMedCount[200];

    // ORDER ARRAYS
    int orderUserIndex[200];
    int orderStoreIndex[200];
    string orderMedType[200];
    string orderMedName[200];
    int orderQty[200];
    string orderStatus[200];
    int totalOrders = 0;

    loadUsers(
        totalUsers,
        nameArr,
        usernameArr,
        passwordArr,
        blockArr,
        CNICarr,
        addressArr,
        cityArr,
        townArr);

    loadStores(
        totalStores,
        storeNameStoreArr,
        storeUsernameArr,
        storePasswordArr,
        storeBlockArr,
        storeAddressArr,
        storeCityArr,
        storeTownArr);

    loadStoreMedicines(
        totalStores,
        storeMedType,
        storeMedName,
        storeMedQty,
        storeMedPrice,
        storeMedCount);

    loadOrders(
        totalOrders,
        orderUserIndex,
        orderStoreIndex,
        orderMedName,
        orderQty,
        orderStatus);

    while (true)
    {
        int mainPanelInput;
        string mainPanelInputSTR;
        UI();
        cout << "1. Login" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Admin Login" << endl;
        cout << "4. Store Login" << endl;
        cout << "5. Reset Password" << endl;
        cout << "6. Exit\n"
             << endl;
        cout << "Choose Any Option:" << endl;
        cin >> mainPanelInputSTR;
        if (isValidnum(mainPanelInputSTR)) // VALIDATION FOR INT
        {
            mainPanelInput = stoi(mainPanelInputSTR);
        }
        else
        {
            cout << "Invalid Input. Try Again";
            Sleep(1500);
            continue;
        }

        if (mainPanelInput < 1 || mainPanelInput > 6) // INPUT LIMIT 1 TO 6
        {
            cout << "Invalid choice. Try Again...";
            pause();
            continue;
        }

        if (mainPanelInput == 1)
        {
            userLogin(
                totalUsers,
                count,
                nameArr,
                usernameArr,
                passwordArr,
                blockArr,
                CNICarr,
                addressArr,
                cityArr,
                townArr,

                totalStores,
                storeNameStoreArr,
                storeCityArr,
                storeTownArr,
                storeBlockArr,
                storeMedType,
                storeMedName,
                storeMedQty,
                storeMedCount,
                storeMedPrice,

                orderUserIndex,
                orderStoreIndex,
                orderMedType,
                orderMedName,
                orderQty,
                orderStatus,
                totalOrders);
        }
        else if (mainPanelInput == 2)
        {
            userSignUp(
                nameArr, usernameArr, passwordArr,
                blockArr, CNICarr,
                addressArr, cityArr, townArr,
                totalUsers);
        }
        else if (mainPanelInput == 3)
        {
            string adminUsername, adminPassword;
            UI();
            adminUI();

            cout << "Enter username:" << endl;
            cin >> adminUsername;
            cout << "Enter Password:" << endl;
            cin >> adminPassword;

            if (adminUsername == "ams" && adminPassword == "123")
            {
                adminPanel(
                    totalStores,
                    storeNameStoreArr,
                    storeUsernameArr,
                    storePasswordArr,
                    storeBlockArr,
                    storeAddressArr,
                    storeCityArr,
                    storeTownArr,
                    totalUsers,
                    nameArr,
                    usernameArr,
                    passwordArr,
                    blockArr,
                    CNICarr,
                    addressArr,
                    cityArr,
                    townArr);
                continue;
            }
            else
            {
                cout << "Invalid Credentials...";
                Sleep(1500);
                continue;
            }
            break;
        }
        else if (mainPanelInput == 4)
        {
            storeLogin(
                storeUsernameArr,
                storePasswordArr,
                totalStores,
                storeAddressArr,
                storeCityArr,
                storeTownArr,
                storeBlockArr,
                storeMedPrice,

                storeMedType,
                storeMedName,
                storeMedQty,
                storeMedCount,

                orderUserIndex,
                orderStoreIndex,
                orderMedType,
                orderMedName,
                orderQty,
                orderStatus,
                totalOrders,

                addressArr,
                cityArr,
                townArr,
                blockArr);
        }
        else if (mainPanelInput == 5)
        {
            passwordReset(
                totalUsers,
                totalStores,
                usernameArr,
                passwordArr,
                storeUsernameArr,
                storePasswordArr);
        }
        else if (mainPanelInput == 6)
        {
            saveStoreMedicines(
                totalStores,
                storeMedType,
                storeMedName,
                storeMedQty,
                storeMedPrice,
                storeMedCount);

            saveUsers(
                totalUsers,
                nameArr,
                usernameArr,
                passwordArr,
                blockArr,
                CNICarr,
                addressArr,
                cityArr,
                townArr);

            saveStores(
                totalStores,
                storeNameStoreArr,
                storeUsernameArr,
                storePasswordArr,
                storeBlockArr,
                storeAddressArr,
                storeCityArr,
                storeTownArr);

            return 0;
        }
    }

    return 0;
}

void UI()
{
    system("cls");

    cout << "\033[31m" << "*****************************" << endl;
    cout << "\033[31m" << "      MEDICINE PROVIDER      " << endl;
    cout << "\033[31m" << "*****************************" << endl;
    cout << "\033[0m";
}

void adminUI()
{
    cout << "\033[34m" << "-----------------------------" << endl;
    cout << "\033[34m" << "         Admin Panel         " << endl;
    cout << "\033[34m" << "-----------------------------" << endl;
    cout << "\033[0m";
}

void userUI()
{
    cout << "\033[35m" << "-----------------------------" << endl;
    cout << "\033[35m" << "         User Panel          " << endl;
    cout << "\033[35m" << "-----------------------------" << endl;
    cout << "\033[0m";
}

void storeUI()
{
    cout << "\033[95m" << "-----------------------------" << endl;
    cout << "\033[95m" << "         Store Panel         " << endl;
    cout << "\033[95m" << "-----------------------------" << endl;
    cout << "\033[0m";
}

// USER LOGIN
void userLogin(
    int &totalUsers,
    int &count,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[],

    // STORE DATA
    int totalStores,
    string storeNameStoreArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],
    int storeMedPrice[][50],

    // ORDER DATA
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders)
{
    while (true)
    {
        string loginUsername, loginPassword;
        UI();
        userUI();

        cout << "Enter Username:" << endl;
        cin >> loginUsername;
        cout << "Enter Password:" << endl;
        cin.ignore();
        getline(cin, loginPassword);

        for (int i = 0; i < totalUsers; i++)
        {
            if (usernameArr[i] == loginUsername &&
                passwordArr[i] == loginPassword)
            {
                cout << "Login Successful!";
                Sleep(1200);

                userPanel(
                    i,
                    nameArr, usernameArr, passwordArr,
                    blockArr, CNICarr,
                    addressArr, cityArr, townArr,
                    totalUsers,

                    totalStores,
                    storeNameStoreArr,
                    storeCityArr,
                    storeTownArr,
                    storeBlockArr,
                    storeMedType,
                    storeMedName,
                    storeMedQty,
                    storeMedCount,
                    storeMedPrice,

                    orderUserIndex,
                    orderStoreIndex,
                    orderMedType,
                    orderMedName,
                    orderQty,
                    orderStatus,
                    totalOrders);
                return;
            }
        }

        cout << "Invalid Credentials. Try again";
        count++;
        Sleep(1300);

        if (count == 5)
        {
            loginBlock(count);
        }
    }
}

// USER SIGN UP

void userSignUp(
    string nameArr[], string usernameArr[], string passwordArr[],
    int blockArr[], long long CNICarr[],
    string addressArr[], string cityArr[], string townArr[],
    int &totalUsers)
{
    string newUserName, newUserAddress, newUsername, newUserTown, cnicStr, newUserblockSTR;
    string newUserPassword, newUserCity;
    int newUserblock;
    long long newUserCNIC;
    bool hasSpace;

    UI();
    userUI();

    do
    {
        cout << "Enter Your Name: ";
        cin.ignore();
        getline(cin, newUserName);

        if (!isValidName(newUserName))
            cout << "Invalid name! Only single space allowed between words.\n";

    } while (!isValidName(newUserName));
    while (true)
    {
        cout << "Enter Username:" << endl;
        getline(cin, newUsername);

        hasSpace = false;

        for (char ch : newUsername)
        {
            if (ch == ' ')
            {
                hasSpace = true;
            }
        }

        if (hasSpace)
        {
            cout << "Space not allowed in username.\n";
            Sleep(2000);
            continue;
        }
        if (isUsernameTaken(newUserName, usernameArr, totalUsers))
        {
            cout << "Username Already Exists. Try Again..\n";
            Sleep(2500);
            continue;
        }
        else
        {
            break;
        }
    }

    cout << "Enter Password:" << endl;
    cin >> newUserPassword;
    while (true)
    {
        cout << "Enter CNIC:" << endl;
        cin >> cnicStr;

        if (isValidnum(cnicStr) && cnicStr.length() == 13)
        {
            newUserCNIC = stoll(cnicStr);
            break;
        }
        cout << "Invalid CNIC! Try again\n";
        Sleep(1500);
    }

    cout << "Enter Address:" << endl;
    cin.ignore();
    getline(cin, newUserAddress);

    cout << "Enter City:" << endl;
    cin >> newUserCity;

    cout << "Enter Town:" << endl;
    cin.ignore();
    getline(cin, newUserTown);

    while (true)
    {
        cout << "Block:" << endl;
        cin >> newUserblockSTR;
        if (isValidnum(newUserblockSTR)) // VALIDATION FOR INT
        {
            newUserblock = stoi(newUserblockSTR);
            break;
        }
        else
        {
            cout << "Invalid Input. Try Again";
            Sleep(1500);
        }
    }

    nameArr[totalUsers] = newUserName;
    usernameArr[totalUsers] = newUsername;
    passwordArr[totalUsers] = newUserPassword;
    addressArr[totalUsers] = newUserAddress;
    cityArr[totalUsers] = newUserCity;
    townArr[totalUsers] = newUserTown;
    blockArr[totalUsers] = newUserblock;
    CNICarr[totalUsers] = newUserCNIC;

    totalUsers++;

    cout << "Account Created Successfully!";
    saveUsers(
        totalUsers,
        nameArr,
        usernameArr,
        passwordArr,
        blockArr,
        CNICarr,
        addressArr,
        cityArr,
        townArr);

    Sleep(1200);
}

// ADMIN PANEL
void adminPanel(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[],
    int &totalUsers,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[])
{
    while (true)
    {
        string adminPanelInputSTR;
        int adminPanelInput;
        UI();
        adminUI();

        cout << "1. Add New Store" << endl;
        cout << "2. View All Users" << endl;
        cout << "3. View All Stores" << endl;
        cout << "4. Remove User" << endl;
        cout << "5. Remove Store" << endl;
        cout << "6. Back" << endl
             << endl;
        cout << "Choose Option:" << endl;
        cin >> adminPanelInputSTR;

        if (isValidnum(adminPanelInputSTR)) // VALIDATION
        {
            adminPanelInput = stoi(adminPanelInputSTR);
        }
        else
        {
            cout << "Invalid Input. Try Again";
            Sleep(1500);
            continue;
        }

        if (adminPanelInput < 1 || adminPanelInput > 6) // LIMIT
        {
            cout << "Invalid choice. Try Again...";
            pause();
            continue;
        }

        if (adminPanelInput == 1)
        {
            newStore(
                totalStores,
                storeNameStoreArr,
                storeUsernameArr,
                storePasswordArr,
                storeBlockArr,
                storeAddressArr,
                storeCityArr,
                storeTownArr);

            saveStores(
                totalStores,
                storeNameStoreArr,
                storeUsernameArr,
                storePasswordArr,
                storeBlockArr,
                storeAddressArr,
                storeCityArr,
                storeTownArr);
        }

        // VIEW ALL USERS
        else if (adminPanelInput == 2)
        {
            UI();
            adminUI();
            cout << "All Users:\n";
            for (int i = 0; i < totalUsers; i++)
            {
                cout << i + 1 << ". " << nameArr[i] << " | Username: " << usernameArr[i]
                     << " | City: " << cityArr[i] << " | Town: " << townArr[i] << " | Block: " << blockArr[i] << endl;
            }
            pause();
        }

        // VIEW ALL STORES
        else if (adminPanelInput == 3)
        {
            UI();
            adminUI();
            cout << "All Stores:\n";
            for (int i = 0; i < totalStores; i++)
            {
                cout << i + 1 << ". " << storeNameStoreArr[i] << " | Username: " << storeUsernameArr[i]
                     << " | City: " << storeCityArr[i] << " | Town: " << storeTownArr[i] << " | Block: " << storeBlockArr[i] << endl;
            }
            pause();
        }

        // REMOVE USER
        else if (adminPanelInput == 4)
        {
            string delUsername;
            cout << "Enter username of user to delete: ";
            cin >> delUsername;

            bool found = false;
            for (int i = 0; i < totalUsers; i++)
            {
                if (usernameArr[i] == delUsername)
                {
                    found = true;
                    // Shift all users after i
                    for (int j = i; j < totalUsers - 1; j++)
                    {
                        nameArr[j] = nameArr[j + 1];
                        usernameArr[j] = usernameArr[j + 1];
                        passwordArr[j] = passwordArr[j + 1];
                        blockArr[j] = blockArr[j + 1];
                        CNICarr[j] = CNICarr[j + 1];
                        addressArr[j] = addressArr[j + 1];
                        cityArr[j] = cityArr[j + 1];
                        townArr[j] = townArr[j + 1];
                    }

                    totalUsers--;
                    saveUsers(totalUsers, nameArr, usernameArr, passwordArr, blockArr, CNICarr, addressArr, cityArr, townArr);
                    cout << "User deleted successfully!\n";
                    Sleep(1200);
                    break;
                }
            }
            if (!found)
            {
                cout << "User not found!\n";
                Sleep(1200);
            }
        }

        // REMOVE STORE
        else if (adminPanelInput == 5)
        {
            string delStoreUsername;
            cout << "Enter username of store to delete: ";
            cin >> delStoreUsername;

            bool found = false;
            for (int i = 0; i < totalStores; i++)
            {
                if (storeUsernameArr[i] == delStoreUsername)
                {
                    found = true;
                    // Shift all stores after i
                    for (int j = i; j < totalStores - 1; j++)
                    {
                        storeNameStoreArr[j] = storeNameStoreArr[j + 1];
                        storeUsernameArr[j] = storeUsernameArr[j + 1];
                        storePasswordArr[j] = storePasswordArr[j + 1];
                        storeBlockArr[j] = storeBlockArr[j + 1];
                        storeAddressArr[j] = storeAddressArr[j + 1];
                        storeCityArr[j] = storeCityArr[j + 1];
                        storeTownArr[j] = storeTownArr[j + 1];
                    }
                    totalStores--;
                    saveStores(totalStores, storeNameStoreArr, storeUsernameArr, storePasswordArr,
                               storeBlockArr, storeAddressArr, storeCityArr, storeTownArr);
                    cout << "Store deleted successfully!\n";
                    Sleep(1200);
                    break;
                }
            }
            if (!found)
            {
                cout << "Store not found!\n";
                Sleep(1200);
            }
        }

        // BACK
        else if (adminPanelInput == 6)
        {
            break;
        }
    }
}

// NEW STORE

void newStore(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[])
{
    string name, username, password, address, city, town, blockSTR;
    int block;
    bool hasSpace;
    UI();
    storeUI();

    do
    {
        cout << "Enter Store Name: ";
        cin.ignore();
        getline(cin, name);

        if (!isValidName(name))
            cout << "Invalid name! Only single space allowed between words.\n";

    } while (!isValidName(name));

    while (true)
    {
        cout << "Enter Username:" << endl;
        getline(cin, username);

        hasSpace = false;

        for (char ch : username)
        {
            if (ch == ' ')
            {
                hasSpace = true;
            }
        }

        if (hasSpace)
        {
            cout << "Space not allowed in username.\n";
            Sleep(2000);
            continue;
        }
        if (isUsernameTaken(username, storeUsernameArr, totalStores))
        {
            cout << "Username Already Exists. Try Again..\n";
            Sleep(2500);
            continue;
        }
        else
        {
            break;
        }
    }

    cout << "Password:" << endl;

    getline(cin, password);

    cout << "Address:" << endl;
    cin.ignore();
    getline(cin, address);

    cout << "City:" << endl;
    cin >> city;
    transform(city.begin(), city.end(), city.begin(), ::tolower);

    cout << "Town:" << endl;
    cin.ignore();
    getline(cin, town);
    transform(town.begin(), town.end(), town.begin(), ::tolower);
    while (true)
    {
        cout << "Block:" << endl;
        cin >> blockSTR;
        if (isValidnum(blockSTR)) // VALIDATION FOR INT
        {
            block = stoi(blockSTR);
            break;
        }
        else
        {
            cout << "Invalid Input. Try Again\n";
            Sleep(1500);
        }
    }

    storeNameStoreArr[totalStores] = name;
    storeUsernameArr[totalStores] = username;
    storePasswordArr[totalStores] = password;
    storeAddressArr[totalStores] = address;
    storeCityArr[totalStores] = city;
    storeTownArr[totalStores] = town;
    storeBlockArr[totalStores] = block;

    totalStores++;

    cout << "Store Added Successfully!";
    Sleep(1200);
}

// STORE LOGIN
void storeLogin(
    string storeUsernameArr[],
    string storePasswordArr[],
    int &totalStores,
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    int storeMedPrice[][50],

    // MEDICINES
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],

    // ORDERS
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders,

    string addressArr[],
    string cityArr[],
    string townArr[],
    int blockArr[])

{
    while (true)
    {
        UI();
        storeUI();

        string u, p;
        cout << "Username:\n";
        cin >> u;
        cout << "Password:\n";
        cin.ignore();
        getline(cin, p);

        for (int i = 0; i < totalStores; i++)
        {
            if (storeUsernameArr[i] == u &&
                storePasswordArr[i] == p)
            {
                cout << "Login Successful!";
                Sleep(1200);

                storePanel(
                    i,
                    totalStores,
                    storePasswordArr,
                    storeAddressArr,
                    storeCityArr,
                    storeTownArr,
                    storeBlockArr,
                    storeMedPrice,
                    storeMedType,
                    storeMedName,
                    storeMedQty,
                    storeMedCount,
                    orderUserIndex,
                    orderStoreIndex,
                    orderMedType,
                    orderMedName,
                    orderQty,
                    orderStatus,
                    totalOrders,
                    addressArr,
                    cityArr,
                    townArr,
                    blockArr);

                return;
            }
        }

        cout << "Incorrect Credentials!\n";
        Sleep(1500);
    }
}

// USER PANEL
void userPanel(
    int userIndex,
    string nameArr[], string usernameArr[], string passwordArr[],
    int blockArr[], long long CNICarr[],
    string addressArr[], string cityArr[], string townArr[],
    int &totalUsers,

    // STORE DATA
    int totalStores,
    string storeNameStoreArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],
    int storeMedPrice[][50],

    // ORDER DATA
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders)

{
    string medType, syrupName, tabletsName;
    int SyrupQT, TabletsQT;
    while (true)
    {
        int userPanelInput;
        string userPanelInputSTR;
        UI();
        userUI();
        cout << "1. Order a medicine" << endl;
        cout << "2. View order status" << endl;
        cout << "3. Update location" << endl;
        cout << "4. Change Password" << endl;
        cout << "5. View All Medicines" << endl;
        cout << "6. Exit\n"
             << endl;
        cout << "Choose Any Option:" << endl;
        cin >> userPanelInputSTR;
        if (isValidnum(userPanelInputSTR)) // VALIDATION FOR INT
        {
            userPanelInput = stoi(userPanelInputSTR);
        }
        else
        {
            cout << "Invalid Input. Try Again\n";
            Sleep(1500);
            continue;
        }

        if (userPanelInput < 1 || userPanelInput > 6) // INPUT LIMIT 1 TO 6
        {
            cout << "Invalid choice. Try Again...\n";
            pause();
            continue;
        }
        if (userPanelInput == 1)
        {
            UI();
            userUI();

            string medName;
            int medQty;

            // USER INPUT
            cout << "Enter medicine name: ";
            cin.ignore();
            getline(cin, medName);
            transform(medName.begin(), medName.end(), medName.begin(), ::tolower);

            cout << "Enter quantity: ";
            cin >> medQty;

            int bestStore = -1;
            int bestScore = -1;
            int medPrice = 0; // price per piece from store

            //  FIND BEST STORE
            for (int s = 0; s < totalStores; s++)
            {
                int score = locationScore(
                    blockArr[userIndex],
                    townArr[userIndex],
                    cityArr[userIndex],
                    storeBlockArr[s],
                    storeTownArr[s],
                    storeCityArr[s]);

                // check if store has the medicine in required qty
                for (int m = 0; m < storeMedCount[s]; m++)
                {
                    if (storeMedName[s][m] == medName && storeMedQty[s][m] >= medQty)
                    {
                        if (score > bestScore)
                        {
                            bestScore = score;
                            bestStore = s;
                            medPrice = storeMedPrice[s][m]; // save price per piece
                        }
                    }
                }
            }

            if (bestStore != -1)
            {
                orderUserIndex[totalOrders] = userIndex;
                orderStoreIndex[totalOrders] = bestStore;
                orderMedName[totalOrders] = medName;
                orderQty[totalOrders] = medQty;
                orderStatus[totalOrders] = "Pending";
                totalOrders++;
                saveOrders(
                    totalOrders,
                    orderUserIndex,
                    orderStoreIndex,
                    orderMedName,
                    orderQty,
                    orderStatus);

                int medicinePrice = medPrice * medQty;
                int deliveryCharges = 200;
                int totalBill = medicinePrice + deliveryCharges;

                cout << "Medicine Price: " << medicinePrice << " Rs\n";
                cout << "Delivery Charges: " << deliveryCharges << " Rs\n";
                cout << "Total Bill: " << totalBill << " Rs\n";

                // Reduce store inventory
                for (int m = 0; m < storeMedCount[bestStore]; m++)
                {
                    if (storeMedName[bestStore][m] == medName)
                    {
                        storeMedQty[bestStore][m] -= medQty;
                        saveStoreMedicines(
                            totalStores,
                            storeMedType,
                            storeMedName,
                            storeMedQty,
                            storeMedPrice,
                            storeMedCount);
                        break;
                    }
                }
            }
            else
            {
                cout << "Sorry! Medicine not available in nearby stores or insufficient quantity.\n";
            }

            pause();
        }

        // VIEW ORDER STATUS

        else if (userPanelInput == 2)
        {
            for (int i = 0; i < totalOrders; i++)
            {
                if (orderUserIndex[i] == userIndex)
                {
                    cout << "Medicine: " << orderMedName[i]
                         << " | Status: " << orderStatus[i] << endl;
                }
            }
            pause();
        }
        else if (userPanelInput == 3)
        {
            string newAddress, newCity, newTown, blockSTR;
            int newBlock;
            string confirmation;
            while (true)
            {
                cout << "Are you sure you want to change your location? (yes or no)" << endl;
                cin >> confirmation;
                transform(confirmation.begin(), confirmation.end(), confirmation.begin(), ::tolower);
                if (confirmation == "yes")
                {
                    cout << "Enter your new address:" << endl;
                    cin.ignore();
                    getline(cin, newAddress);

                    cout << "Enter your new city:" << endl;
                    cin >> newCity;
                    transform(newCity.begin(), newCity.end(), newCity.begin(), ::tolower);

                    cout << "Enter your new town:" << endl;
                    cin.ignore();
                    getline(cin, newTown);
                    transform(newTown.begin(), newTown.end(), newTown.begin(), ::tolower);

                    while (true)
                    {
                        cout << "Enter your new block:" << endl;
                        cin >> blockSTR;
                        if (isValidnum(blockSTR))
                        {
                            newBlock = stoi(blockSTR);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Block! Try again.";
                            Sleep(1200);
                            continue;
                        }
                    }
                    addressArr[userIndex] = newAddress;
                    cityArr[userIndex] = newCity;
                    townArr[userIndex] = newTown;
                    blockArr[userIndex] = newBlock;

                    cout << "Location updated successfully!";
                    Sleep(1200);
                    saveUsers(
                        totalUsers,
                        nameArr,
                        usernameArr,
                        passwordArr,
                        blockArr,
                        CNICarr,
                        addressArr,
                        cityArr,
                        townArr);
                    break;
                }
                else if (confirmation == "no")
                {
                    cout << "Moving Back...";
                    Sleep(2000);
                    break;
                }
                else
                {
                    cout << "Invalid Input. Try again";
                    Sleep(2000);
                    continue;
                }
            }
        }

        else if (userPanelInput == 4)
        {
            string newPass, confirmPass;
            while (true)
            {
                cout << "Enter new password:" << endl;
                cin >> newPass;

                cout << "Confirm new password:" << endl;
                cin >> confirmPass;

                if (newPass != confirmPass)
                {
                    cout << "Password mismatch!";
                    Sleep(1500);
                    continue;
                }

                break;
            }

            passwordArr[userIndex] = newPass;
            cout << "Password changed successfully!";
            saveUsers(
                totalUsers,
                nameArr,
                usernameArr,
                passwordArr,
                blockArr,
                CNICarr,
                addressArr,
                cityArr,
                townArr);
            Sleep(1500);
        }
        else if (userPanelInput == 5)
        {
            showMedicinesByUserTown(
                townArr[userIndex],
                totalStores,
                storeNameStoreArr,
                storeTownArr,
                storeMedName,
                storeMedType,
                storeMedQty,
                storeMedPrice,
                storeMedCount);
            pause();
        }
        else if (userPanelInput == 6)
        {
            return;
        }
    }
}

// STORE PANEL

void storePanel(
    int storeIndex,
    int &totalStores,
    string storePasswordArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[],
    int storeBlockArr[],
    int storeMedPrice[][50],

    // MEDS
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[],

    // ORDERS
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedType[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[],
    int &totalOrders,

    // USERS
    string addressArr[],
    string cityArr[],
    string townArr[],
    int blockArr[])

{
    while (true)
    {
        int choice, qt, price;
        string choiceSTR, qtSTR, priceSTR;
        UI();
        storeUI();

        cout << "1. Add Medicine (Single / Bulk / Both)" << endl;
        cout << "2. View All Medicines" << endl;
        cout << "3. View Orders" << endl;
        cout << "4. Update Address" << endl;
        cout << "5. Change Password" << endl;
        cout << "6. Update Status" << endl;
        cout << "7. Exit" << endl
             << endl;
        cout << "Enter your Choice:" << endl;

        cin >> choiceSTR;
        if (isValidnum(choiceSTR)) // VALIDATION FOR INT
        {
            choice = stoi(choiceSTR);
        }
        else
        {
            cout << "Invalid Input. Try Again\n";
            Sleep(1500);
            continue;
        }

        if (choice < 1 || choice > 7) // INPUT LIMIT 1 TO 6
        {
            cout << "Invalid choice. Try Again...\n";
            pause();
            continue;
        }

        if (choice == 1)
        {
            string type, qtySTR;
            int qty;

            cout << "Enter medicine type (syrup / tablets / both): ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);

            if (type == "syrup" || type == "tablets")
            {
                cout << "How many medicines to add: ";
                cin >> qtySTR;
                if (isValidnum(qtySTR)) // VALIDATION FOR INT
                {
                    qty = stoi(qtySTR);
                }
                else
                {
                    cout << "Invalid Input. Try Again\n";
                    Sleep(1500);
                    continue;
                }

                if (qty < 1 || qty > 50) // INPUT LIMIT 1 TO 50
                {
                    cout << "Invalid choice. Try Again...\n";
                    pause();
                    continue;
                }

                for (int i = 0; i < qty; i++)
                {
                    cout << "Enter medicine name: ";
                    cin.ignore();
                    getline(cin, storeMedName[storeIndex][storeMedCount[storeIndex]]);
                    transform(storeMedName[storeIndex][storeMedCount[storeIndex]].begin(), storeMedName[storeIndex][storeMedCount[storeIndex]].end(), storeMedName[storeIndex][storeMedCount[storeIndex]].begin(), ::tolower);
                    while (true)
                    {
                        cout << "Enter quantity: ";
                        cin >> qtSTR;
                        if (isValidnum(qtSTR)) // VALIDATION FOR INT
                        {
                            storeMedQty[storeIndex][storeMedCount[storeIndex]] = stoi(qtSTR);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input. Try Again\n";
                            Sleep(1500);
                            continue;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter price per piece: ";
                        cin >> priceSTR;
                        if (isValidnum(priceSTR)) // VALIDATION FOR INT
                        {
                            storeMedPrice[storeIndex][storeMedCount[storeIndex]] = stoi(priceSTR);

                            break;
                        }
                        else
                        {
                            cout << "Invalid Input. Try Again\n";
                            Sleep(1500);
                            continue;
                        }
                    }

                    storeMedType[storeIndex][storeMedCount[storeIndex]] = type;
                    storeMedCount[storeIndex]++;
                }
            }
            else if (type == "both")
            {
                while (true)
                {
                    // SYRUP
                    cout << "How many syrups: ";
                    cin >> qtySTR;
                    if (isValidnum(qtySTR)) // VALIDATION FOR INT
                    {
                        qty = stoi(qtySTR);
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input. Try Again\n";
                        Sleep(1500);
                        continue;
                    }

                    if (qty < 1 || qty > 50) // INPUT LIMIT 1 TO 50
                    {
                        cout << "Invalid choice. Try Again...\n";
                        pause();
                        continue;
                    }
                }

                for (int i = 0; i < qty; i++)
                {
                    cout << "Enter syrup name: ";
                    cin.ignore();
                    getline(cin, storeMedName[storeIndex][storeMedCount[storeIndex]]);
                    transform(storeMedName[storeIndex][storeMedCount[storeIndex]].begin(), storeMedName[storeIndex][storeMedCount[storeIndex]].end(), storeMedName[storeIndex][storeMedCount[storeIndex]].begin(), ::tolower);
                    while (true)
                    {
                        cout << "Enter quantity: ";
                        cin >> qtSTR;
                        if (isValidnum(qtSTR)) // VALIDATION FOR INT
                        {
                            storeMedQty[storeIndex][storeMedCount[storeIndex]] = stoi(qtSTR);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input. Try Again\n";
                            Sleep(1500);
                            continue;
                        }
                        if (qty < 1 || qty > 50) // INPUT LIMIT 1 TO 50
                        {
                            cout << "Invalid choice. Try Again...\n";
                            pause();
                            continue;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter price per piece: ";
                        cin >> priceSTR;
                        if (isValidnum(priceSTR)) // VALIDATION FOR INT
                        {
                            storeMedPrice[storeIndex][storeMedCount[storeIndex]] = stoi(priceSTR);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input. Try Again\n";
                            Sleep(1500);
                            continue;
                        }
                    }

                    storeMedType[storeIndex][storeMedCount[storeIndex]] = "syrup";
                    storeMedCount[storeIndex]++;
                }

                // TABLETS
                cout << "How many tablets: ";
                cin >> qtySTR;
                if (isValidnum(qtySTR)) // VALIDATION FOR INT
                {
                    qty = stoi(qtySTR);
                }
                else
                {
                    cout << "Invalid Input. Try Again\n";
                    Sleep(1500);
                    continue;
                }

                if (qty < 1 || qty > 50) // INPUT LIMIT 1 TO 50
                {
                    cout << "Invalid choice. Try Again...\n";
                    pause();
                    continue;
                }

                for (int i = 0; i < qty; i++)
                {
                    cout << "Enter tablet name: ";
                    cin.ignore();
                    getline(cin, storeMedName[storeIndex][storeMedCount[storeIndex]]);
                    transform(storeMedName[storeIndex][storeMedCount[storeIndex]].begin(), storeMedName[storeIndex][storeMedCount[storeIndex]].end(), storeMedName[storeIndex][storeMedCount[storeIndex]].begin(), ::tolower);

                    while (true)
                    {
                        cout << "Enter quantity: ";
                        cin >> qtSTR;
                        if (isValidnum(qtSTR)) // VALIDATION FOR INT
                        {
                            storeMedQty[storeIndex][storeMedCount[storeIndex]] = stoi(qtSTR);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input. Try Again\n";
                            Sleep(1500);
                            continue;
                        }
                    }
                    while (true)
                    {
                        cout << "Enter price per piece: ";
                        cin >> priceSTR;
                        if (isValidnum(priceSTR)) // VALIDATION FOR INT
                        {
                            storeMedPrice[storeIndex][storeMedCount[storeIndex]] = stoi(priceSTR);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input. Try Again\n";
                            Sleep(1500);
                            continue;
                        }
                    }

                    storeMedType[storeIndex][storeMedCount[storeIndex]] = "tablets";
                    storeMedCount[storeIndex]++;
                }
            }
            else
            {
                cout << "Invalid type!\n";
            }
            cout << "Medicine Added Successfuly!";
            Sleep(1200);
        }

        // VIEW MEDICINES
        else if (choice == 2)
        {
            UI();
            storeUI();
            cout << "Your Medicines:\n";

            for (int i = 0; i < storeMedCount[storeIndex]; i++)
            {
                cout << i + 1 << ". "
                     << storeMedName[storeIndex][i]
                     << " | Type: " << storeMedType[storeIndex][i]
                     << " | Qty: " << storeMedQty[storeIndex][i] << endl;
            }
            pause();
        }

        else if (choice == 3)
        {
            cout << "Orders Received:\n";

            for (int i = 0; i < totalOrders; i++)
            {
                if (orderStoreIndex[i] == storeIndex)
                {
                    int userIdx = orderUserIndex[i]; // get user index
                    cout << "Order ID: " << i + 1 << endl;
                    cout << "Medicine: " << orderMedName[i] << endl;
                    cout << "Qty: " << orderQty[i] << endl;
                    cout << "Status: " << orderStatus[i] << endl;

                    // Display user delivery info
                    cout << "Delivery To:\n";
                    cout << "Address: " << addressArr[userIdx] << endl;
                    cout << "City: " << cityArr[userIdx] << endl;
                    cout << "Town: " << townArr[userIdx] << endl;
                    cout << "Block: " << blockArr[userIdx] << endl;

                    cout << "--------------------\n";
                }
            }
            pause();
        }
        // UPDATE ADDRESS
        else if (choice == 4)
        {
            string address, city, town, blockSTR;
            int block;

            cin.ignore();
            cout << "New Address: ";
            getline(cin, address);

            cout << "City: ";
            cin >> city;
            transform(city.begin(), city.end(), city.begin(), ::tolower);

            cin.ignore();
            cout << "Town: ";
            getline(cin, town);
            transform(town.begin(), town.end(), town.begin(), ::tolower);
            while (true)
            {
                cout << "Block: ";
                cin >> blockSTR;
                if (isValidnum(blockSTR)) // VALIDATION FOR INT
                {
                    block = stoi(blockSTR);
                    break;
                }
                else
                {
                    cout << "Invalid Input. Try Again\n";
                    Sleep(1500);
                    continue;
                }
            }

            storeAddressArr[storeIndex] = address;
            storeCityArr[storeIndex] = city;
            storeTownArr[storeIndex] = town;
            storeBlockArr[storeIndex] = block;

            cout << "Address updated successfully!";
            Sleep(1200);
        }

        //  CHANGE PASSWORD
        else if (choice == 5)
        {
            string newPass, confirmPass;
            cout << "Enter new password: ";
            cin >> newPass;
            cout << "Confirm password: ";
            cin >> confirmPass;

            if (newPass != confirmPass)
            {
                cout << "Password mismatch!";
                Sleep(1200);
                continue;
            }

            storePasswordArr[storeIndex] = newPass;
            cout << "Password updated successfully!";
            Sleep(1200);
        }

        else if (choice == 6)
        {
            int id;
            string idSTR;

            while (true)
            {
                cout << "Enter Order ID to update status: ";
                cin >> idSTR;

                if (isValidnum(idSTR)) // VALIDATION FOR INT
                {
                    id = stoi(idSTR);
                    id--;
                    if (id < 0 || id >= totalOrders)
                    {
                        cout << "Invalid Order ID!";
                        Sleep(1200);
                        break;
                    }
                    break;
                }

                else
                {
                    cout << "Invalid Input. Try Again\n";
                    Sleep(1500);
                    continue;
                }
            }
            id--;

            cout << "1. Dispatched\n2. Delivered\n";
            int ch;
            cin >> ch;

            if (ch == 1){
                orderStatus[id] = "Dispatched";
                saveOrders(
                totalOrders,
                orderUserIndex,
                orderStoreIndex,
                orderMedName,
                orderQty,
                orderStatus);
            }
            else if (ch == 2){
                orderStatus[id] = "Delivered";
                saveOrders(
                totalOrders,
                orderUserIndex,
                orderStoreIndex,
                orderMedName,
                orderQty,
                orderStatus);
            }

            saveOrders(
                totalOrders,
                orderUserIndex,
                orderStoreIndex,
                orderMedName,
                orderQty,
                orderStatus);
        }
        else if (choice == 7)
        {
            return;
        }
        saveStoreMedicines(
            totalStores,
            storeMedType,
            storeMedName,
            storeMedQty,
            storeMedPrice,
            storeMedCount);
    }
}

// PASSWORD RESET

void passwordReset(int &totalUsers, int &totalStores, string usernameArr[], string passwordArr[], string storeUsernameArr[], string storePasswordArr[])
{
    string accountType, enterUsername;
    UI();
    cout << "Enter Account Type: (User OR Store)" << endl;
    cin >> accountType;
    transform(accountType.begin(), accountType.end(), accountType.begin(), ::tolower);

    if (accountType == "user")
    {
        cout << "Enter your username:" << endl;
        cin >> enterUsername;
        for (int i = 0; i < totalUsers; i++)
        {
            if (enterUsername == usernameArr[i])
            {
                cout << "Your Password is: " << passwordArr[i] << endl;
                Sleep(2000);
                pause();
                break;
            }
        }
    }
    else if (accountType == "store")
    {
        cout << "Enter your username:" << endl;
        cin >> enterUsername;
        for (int i = 0; i < totalStores; i++)
        {
            if (enterUsername == storeUsernameArr[i])
            {
                cout << "Your Password is: " << storePasswordArr[i] << endl;
                Sleep(2000);
                pause();
            }
        }
    }
}

// PAUSE

void pause()
{
    cout << "Press any key to continue!" << endl;
    getch();
}

// INT VALIDATION

bool isValidnum(string s)
{
    if (s.length() == 0)
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 48 || s[i] > 57) // ASCII check
            return false;
    }
    return true;
}

// LOGIN BLOCK FOR 10 SEC

void loginBlock(int &count)
{
    for (int i = 10; i >= 1; i--)
    {
        system("cls");
        UI();
        userUI();
        cout << "Wait for " << i << " seconds.";
        Sleep(1000);
    }
    count = 0;
}

// User Save Data
void saveUsers(
    int &totalUsers,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[])
{
    ofstream file("users.txt");
    file << totalUsers << endl;

    for (int i = 0; i < totalUsers; i++)
    {
        file << nameArr[i] << endl;
        file << usernameArr[i] << endl;
        file << passwordArr[i] << endl;
        file << blockArr[i] << endl;
        file << CNICarr[i] << endl;
        file << addressArr[i] << endl;
        file << cityArr[i] << endl;
        file << townArr[i] << endl;
    }
    file.close();
}

// LOAD USERS

void loadUsers(
    int &totalUsers,
    string nameArr[],
    string usernameArr[],
    string passwordArr[],
    int blockArr[],
    long long CNICarr[],
    string addressArr[],
    string cityArr[],
    string townArr[])
{
    ifstream file("users.txt");
    if (!file)
        return;

    file >> totalUsers;
    file.ignore();

    for (int i = 0; i < totalUsers; i++)
    {
        getline(file, nameArr[i]);
        getline(file, usernameArr[i]);
        getline(file, passwordArr[i]);
        file >> blockArr[i];
        file >> CNICarr[i];
        file.ignore();
        getline(file, addressArr[i]);
        getline(file, cityArr[i]);
        getline(file, townArr[i]);
    }
    file.close();
}

// SAVE STORES

void saveStores(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[])
{
    ofstream file("stores.txt");
    file << totalStores << endl;

    for (int i = 0; i < totalStores; i++)
    {
        file << storeNameStoreArr[i] << endl;
        file << storeUsernameArr[i] << endl;
        file << storePasswordArr[i] << endl;
        file << storeBlockArr[i] << endl;
        file << storeAddressArr[i] << endl;
        file << storeCityArr[i] << endl;
        file << storeTownArr[i] << endl;
    }
    file.close();
}

// LOAD STORES

void loadStores(
    int &totalStores,
    string storeNameStoreArr[],
    string storeUsernameArr[],
    string storePasswordArr[],
    int storeBlockArr[],
    string storeAddressArr[],
    string storeCityArr[],
    string storeTownArr[])
{
    ifstream file("stores.txt");
    if (!file)
        return;

    file >> totalStores;
    file.ignore();

    for (int i = 0; i < totalStores; i++)
    {
        getline(file, storeNameStoreArr[i]);
        getline(file, storeUsernameArr[i]);
        getline(file, storePasswordArr[i]);
        file >> storeBlockArr[i];
        file.ignore();
        getline(file, storeAddressArr[i]);
        getline(file, storeCityArr[i]);
        getline(file, storeTownArr[i]);
    }
    file.close();
}

// MATCH STORE LOCATION WITH USER LOCATION
int locationScore(
    int uBlock, string uTown, string uCity,
    int sBlock, string sTown, string sCity)
{
    if (uCity != sCity)
        return 0;
    if (uTown != sTown)
        return 1;
    if (uBlock != sBlock)
        return 2;
    return 3;
}

// CHECK IF STORE HAS MEDICINE

bool storeHasMedicine(
    int storeIndex,
    string medName,
    int qty,
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedCount[])
{
    for (int i = 0; i < storeMedCount[storeIndex]; i++)
    {
        if (storeMedName[storeIndex][i] == medName &&
            storeMedQty[storeIndex][i] >= qty)
            return true;
    }
    return false;
}

// SAVE STORE MEDICINES
void saveStoreMedicines(
    int totalStores,
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedPrice[][50],
    int storeMedCount[])
{
    ofstream file("storeMedicines.txt");
    file << totalStores << endl;

    for (int s = 0; s < totalStores; s++)
    {
        file << storeMedCount[s] << endl;
        for (int m = 0; m < storeMedCount[s]; m++)
        {
            file << storeMedName[s][m] << endl;
            file << storeMedType[s][m] << endl;
            file << storeMedQty[s][m] << endl;
            file << storeMedPrice[s][m] << endl;
        }
    }
    file.close();
}

// LOAD STORE MEDICINES
void loadStoreMedicines(
    int &totalStores,
    string storeMedType[][50],
    string storeMedName[][50],
    int storeMedQty[][50],
    int storeMedPrice[][50],
    int storeMedCount[])
{
    ifstream file("storeMedicines.txt");
    if (!file)
        return;

    file >> totalStores;
    file.ignore();

    for (int s = 0; s < totalStores; s++)
    {
        file >> storeMedCount[s];
        file.ignore();
        for (int m = 0; m < storeMedCount[s]; m++)
        {
            getline(file, storeMedName[s][m]);
            getline(file, storeMedType[s][m]);
            file >> storeMedQty[s][m];
            file >> storeMedPrice[s][m];
            file.ignore();
        }
    }
    file.close();
}

// SAVE ORDERS
void saveOrders(
    int totalOrders,
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[])
{
    ofstream file("orders.txt");
    file << totalOrders << endl;
    for (int i = 0; i < totalOrders; i++)
    {
        file << orderUserIndex[i] << " " << orderStoreIndex[i] << " " << orderQty[i] << endl;
        file << orderMedName[i] << endl;
        file << orderStatus[i] << endl;
    }
    file.close();
}

//  LOAD ORDERS
void loadOrders(
    int &totalOrders,
    int orderUserIndex[],
    int orderStoreIndex[],
    string orderMedName[],
    int orderQty[],
    string orderStatus[])
{
    ifstream file("orders.txt");
    if (!file)
        return;

    file >> totalOrders;
    file.ignore();
    for (int i = 0; i < totalOrders; i++)
    {
        file >> orderUserIndex[i] >> orderStoreIndex[i] >> orderQty[i];
        file.ignore();
        getline(file, orderMedName[i]);
        getline(file, orderStatus[i]);
    }
    file.close();
}

// Check if username already exists
bool isUsernameTaken(string username, string arr[], int totalCount)
{
    transform(username.begin(), username.end(), username.begin(), ::tolower);

    for (int i = 0; i < totalCount; i++)
    {
        string temp = arr[i];
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if (temp == username)
        {
            return true;
        }
        break;
    }
    return false;
}

// SHOW MEDICINES BY USER'S TOWN

void showMedicinesByUserTown(
    string userTown,
    int totalStores,
    string storeNameStoreArr[],
    string storeTownArr[],
    string storeMedName[][50],
    string storeMedType[][50],
    int storeMedQty[][50],
    int storeMedPrice[][50],
    int storeMedCount[])
{
    bool foundStore = false;

    cout << "Medicines Available In Your Town\n";

    for (int i = 0; i < totalStores; i++)
    {
        if (storeTownArr[i] == userTown)
        {
            foundStore = true;

            cout << "\nStore Name: " << storeNameStoreArr[i] << endl;
            cout << "----------------------------------\n";

            if (storeMedCount[i] == 0)
            {
                cout << "No medicines available in this store.\n";
                continue;
            }

            cout << "No  Name\tType\tQty\tPrice\n";

            for (int j = 0; j < storeMedCount[i]; j++)
            {
                cout << j + 1 << ". "
                     << storeMedName[i][j] << "\t"
                     << storeMedType[i][j] << "\t"
                     << storeMedQty[i][j] << "\t"
                     << storeMedPrice[i][j] << endl;
            }
        }
    }

    if (!foundStore)
    {
        cout << "\nNo stores found in your town.\n";
    }
}

// NAME VALIDATION

bool isValidName(const string &name)
{
    if (name.empty())
        return false;

    if (name[0] == ' ' || name[name.length() - 1] == ' ')
        return false;

    for (int i = 0; i < name.length(); i++)
    {
        // Only alphabets or space allowed
        if (!isalpha(name[i]) && name[i] != ' ')
            return false;

        // More than one consecutive space
        if (name[i] == ' ' && name[i + 1] == ' ')
            return false;
    }

    return true;
}
