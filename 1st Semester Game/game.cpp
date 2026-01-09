#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

int mainMenu();
void signUp();
bool signIn();
void userMenu();
void startGame();
void selectLevel();
void runLevel(int lvl);
void saveProgress();
void runLevel1();
void runLevel2();
void runLevel3();
bool isValidnum(string s);

void maze();
void gotoxy(int x, int y);
void drawPlayer(int x, int y);
void drawEnemyLVL1(int x, int y);
void drawEnemyLVL2(int x, int y);
void moveCursorOutsideMaze();
void eraseEnemyTank(int x, int y);
void moveEnemyHorizontalLVL1(int &ex, int ey, int &dir);
void moveCursorOutsideMaze();
void drawBulletLVL1(int x, int y);
void drawBulletLVL2(int x, int y);
void eraseBullet(int x, int y);
void fireEnemy(int enemyIndex, int ex, int ey);
void updateBullet(int &bx, int &by, bool &active, int ex1, int ey1, int ex2, int ey2, int ex3, int ey3);
void updateBulletLVL3(int &bx, int &by, bool &active, int ex1, int ey1, int ex2, int ey2, int ex3, int ey3);
void drawPlayerBullet(int x, int y);
void erasePlayerBullet(int x, int y);
void updatePlayerBullet();
void handlePlayerInput();
void movePlayer();
void firePlayerBullet(int px, int py);
void updatePlayerBullets(int e1x, int e1y, int &e1Health,
                         int e2x, int e2y, int &e2Health,
                         int e3x, int e3y, int &e3Health);
void displayStats();
void eraseEnemyLVL2(int x, int y);
void eraseBulletLVL2(int x, int y);
void updateBulletLVL2(int &bx, int &by, bool &active, int e1x, int e1y);
void updatePlayerBulletsLVL2(int e1x, int e1y, int &e1Health);
void fireEnemyLVL2(int ex, int ey);
void fireEnemyLVL3(int enemyIndex, int ex, int ey);
void drawEnemyLVL3(int x, int y);
void moveEnemyHorizontalLVL3(int &ex, int ey, int &dir);
void drawBulletLVL3(int x, int y);
void eraseBulletLVL3(int x, int y);
void updatePlayerBulletsLVL3(int e1x, int e1y, int &e1Health,
                             int e2x, int e2y, int &e2Health,
                             int e3x, int e3y, int &e3Health);
void loadUsersFromFile();
void saveUsersToFile();
void runLevel4();
void runLevel5();
void drawBox(int x, int y, int width);
void eraseBox(int x, int y, int width);
void eraseEnemyLVL4(int x, int y);
void drawEnemyLVL4(int x, int y);

string currentUser;
int userLevel = 0; // highest unlocked level
int startLevel;    // for starting game

bool loggedIn = false; // user login

int px = 60, py = 32; // player position
int pdir = 0;         // player movement direction
int pBulX, pBulY;     // player bullet
bool pBulActive = false;

const int MAX_PBULLETS = 8; // player max bullet
int pBulletX[MAX_PBULLETS];
int pBulletY[MAX_PBULLETS];
bool pBulletActive[MAX_PBULLETS];
int pHealth = 10; // player max health
int score = 0;    // player score

// Level 1 enemy bullets
int b1x, b1y, b2x, b2y, b3x, b3y;
bool b1active = false, b2active = false, b3active = false;

const int MAX_USERS = 50;

string usernames[MAX_USERS];
string passwords[MAX_USERS];
int userLevels[MAX_USERS];

int totalUsers = 0;
int currentUserIndex = -1;

int main()
{
    loadUsersFromFile();
    int choice; // main menu option

    while (true)
    {
        mainMenu(); // print main menu
        cin >> choice;

        if (choice == 1)
            signUp(); // for new gamers
        else if (choice == 2)
        {
            if (signIn())
            {
                while (loggedIn)
                {
                    userMenu(); // display user menu

                    if (choice == 0)
                        startGame(); // start game from the latest unlock level
                    else if (choice == 1)
                        selectLevel(); // it will be availiable after gamer play the all levels
                    else if (choice == 2)
                        loggedIn = false; // back to main menu
                }
            }
            else
            {
                cout << "Invalid login!\n"; // if username and password not matches
                Sleep(1000);
            }
        }
        else if (choice == 3)
            break;
    }
    return 0;
}

// Main menu

int mainMenu()
{
    system("cls");
    cout << "\033[32m" << "========== WAR GAME ==========\n";
    cout << "1. Sign Up\n";
    cout << "2. Sign In\n";
    cout << "3. Exit\n";
    cout << "\nChoose Any Option:\n";
}

// sign up

// SIGN UP FUNCTION (Updated)
// SIGN UP FUNCTION (Updated)
void signUp()
{
    bool exists;
    system("cls");
    cout << "\033[32m" << "========== WAR GAME ==========\n";
    string newUsername, newPassword;

    while (true)
    {
        exists = false;
        cout << "Enter Username:\n";
        cin >> newUsername;
        for (int i = 0; i < totalUsers; i++)
        {
            if (usernames[i] == newUsername)
            {
                exists = true;
                break;
            }
        }

        if (exists)
        {
            cout << "Username already exists!\n";
            Sleep(1500);
            continue;
        }
        break;
    }

    cout << "Enter Password:\n";
    cin >> newPassword;

    usernames[totalUsers] = newUsername;
    passwords[totalUsers] = newPassword;
    userLevels[totalUsers] = 0;
    totalUsers++;
    saveUsersToFile();

    cout << "Sign Up Successful! You can now log in.";
    Sleep(1500);
}

// SIGN IN FUNCTION
bool signIn()
{
    system("cls");
    cout << "\033[32m========== WAR GAME ==========\n";

    string Username, Password;
    cout << "Enter Username:\n";
    cin >> Username;
    cout << "Enter Password:\n";
    cin >> Password;

    for (int i = 0; i < totalUsers; i++)
    {
        if (usernames[i] == Username && passwords[i] == Password)
        {
            currentUser = Username;
            userLevel = userLevels[i];
            currentUserIndex = i;
            loggedIn = true;

            cout << "Login Successful!";
            Sleep(1000);
            return true;
        }
    }

    // agar loop complete ho gaya aur match nahi mila
    cout << "Invalid Credentials!";
    Sleep(1500);
    loggedIn = false;
    return false;
}

// USER MENU

void userMenu()
{
    maze(); // maze already drawn

    string options[3] =
        {
            "Start Game",
            "Select Level",
            "Logout"};

    int choice = 0;
    int menuX = 45;
    int menuY = 8;

    // Print static text
    gotoxy(menuX, menuY - 2);
    cout << "Welcome " << currentUser;

    // Print options
    for (int i = 0; i < 3; i++)
    {
        gotoxy(menuX, menuY + i * 3);
        cout << options[i];
    }

    // Initial selection box
    drawBox(menuX, menuY, options[0].length());

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();

            // UP ARROW
            if (key == 72)
            {
                eraseBox(menuX, menuY + choice * 3, options[choice].length());
                choice--;
                if (choice < 0)
                    choice = 2;
                drawBox(menuX, menuY + choice * 3, options[choice].length());
            }

            // DOWN ARROW
            else if (key == 80)
            {
                eraseBox(menuX, menuY + choice * 3, options[choice].length());
                choice++;
                if (choice > 2)
                    choice = 0;
                drawBox(menuX, menuY + choice * 3, options[choice].length());
            }

            // ENTER
            else if (key == 13)
            {
                eraseBox(menuX, menuY + choice * 3, options[choice].length());

                if (choice == 0)
                    startGame();
                else if (choice == 1)
                    selectLevel();
                else if (choice == 2)
                {
                    loggedIn = false;
                    return;
                }

                break;
            }
        }
        Sleep(80);
    }
}

// Start Game
void startGame()
{
    int startLevel;

    if (userLevel >= 5)
    {
        startLevel = 1; // restart from level 1
        userLevel = 0;  // reset progress
        saveProgress();
    }
    else
    {
        startLevel = userLevel + 1; // resume from next unlocked level
        saveProgress();
    }

    runLevel(startLevel);
}

// select level

void selectLevel()
{
    int lvl;
    string lvlSTR;
    while (true)
    {
        cout << "Level (1-5): ";
        cin >> lvlSTR;
        if (isValidnum(lvlSTR)) // VALIDATION FOR INT
        {
            lvl = stoi(lvlSTR);
        }
        else
        {
            cout << "Numbers only";
            Sleep(1500);
            continue;
        }
        if (lvl == 1)
        {
            runLevel1();
            return;
        }
        else if (lvl == 2)
        {
            runLevel2();
            return;
        }
        else if (lvl == 3)
        {
            runLevel3();
        }

        if (lvl > 10)
        { // invalid input
            cout << "Level must be less than 10.\n";
            Sleep(1000);
            continue;
        }
        if (lvl < 1)
        { // invalid input
            cout << "Level must be greater than 0.\n";
            Sleep(1000);
            continue;
        }
        break;
    }
    runLevel(lvl);
}

// run all levels

void runLevel(int lvl)
{
    if (lvl == 1)
    {
        runLevel1();
        return;
    }
    else if (lvl == 2)
    {
        runLevel2();
        return;
    }
    else if (lvl == 3)
    {
        runLevel3();
        return;
    }
    else if (lvl == 4)
    {
        runLevel4();
        return;
    }
    else if (lvl == 5)
    {
        runLevel5();
        return;
    }

    if (lvl > userLevel)
    {
        userLevel = lvl;
        saveProgress();
    }
    saveProgress();
}

// save progress

void saveProgress()
{
    if (currentUserIndex != -1)
    {
        userLevels[currentUserIndex] = userLevel;
        saveUsersToFile();
    }
}

// Maze

void maze()
{
    system("cls");
    cout << "\033[31m" << "####################################################################################################################################" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "#                                                                                                                                  #" << endl;
    cout << "####################################################################################################################################" << endl;
    cout << "\033[0m";
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Draw Player

void drawPlayer(int x, int y)
{
    gotoxy(x, y);
    cout << "\033[32m" << " ||" << endl;
    gotoxy(x, y + 1);
    cout << " ||" << endl;
    gotoxy(x, y + 2);
    cout << "[**]" << endl;
    gotoxy(x, y + 3);
    cout << "[__]" << endl;
    cout << "\033[0m";
}

// DRAW ENEMY Level 1
void drawEnemyLVL1(int x, int y)
{
    gotoxy(x, y);
    cout << "\033[34m" << "[========]" << endl;
    gotoxy(x, y + 1);
    cout << "[--------]" << endl;
    gotoxy(x, y + 2);
    cout << " [------]" << endl;
    gotoxy(x, y + 3);
    cout << "    ||" << endl;
    cout << "\033[0m";
}

// DRAW ENEMY Level 2
void drawEnemyLVL2(int x, int y)
{
    gotoxy(x, y);
    cout << "\033[34m" << "    [  ||  ||  ]" << endl; // 14
    gotoxy(x, y + 1);
    cout << "   [============]" << endl; // 14
    gotoxy(x, y + 2);
    cout << "<<<<<[--------]>>>>>" << endl;
    gotoxy(x, y + 3);
    cout << "      [------]" << endl;
    gotoxy(x, y + 4);
    cout << "         ||" << endl;
    cout << "\033[0m";
}

// DRAW ENEMY Level 3
void drawEnemyLVL3(int x, int y)
{
    gotoxy(x, y);
    cout << "\033[34m" << "    [ ||  || ]" << endl; // 14
    gotoxy(x, y + 1);
    cout << "   [==========]" << endl; // 14
    gotoxy(x, y + 2);
    cout << " <<<[--------]>>>" << endl;
    gotoxy(x, y + 3);
    cout << "      [----]" << endl;
    gotoxy(x, y + 4);
    cout << "        ||" << endl;
    cout << "\033[0m";
}

void drawEnemyLVL4(int x, int y)
{
    gotoxy(x, y);
    cout << "\033[34m" << "[========]" << endl;
    gotoxy(x, y + 1);
    cout << "[--------]" << endl;
    gotoxy(x, y + 2);
    cout << "[********]" << endl;
    gotoxy(x, y + 3);
    cout << "    ||" << endl;
    cout << "\033[0m";
}

void drawEnemyLVL5(int x, int y)
{
    gotoxy(x, y);
    cout << "\033[34m" << "    [ ||  || ]" << endl; // 14
    gotoxy(x, y + 1);
    cout << "   [=********=]" << endl; // 14
    gotoxy(x, y + 2);
    cout << "<<<<[==****==]>>>>" << endl;
    gotoxy(x, y + 3);
    cout << "      [----]" << endl;
    gotoxy(x, y + 4);
    cout << "        ||" << endl;
    cout << "\033[0m";
}

// move cursor outside maze

void moveCursorOutsideMaze()
{
    gotoxy(1, 40);
}

// erase enemy tank

void eraseEnemyTank(int x, int y)
{
    for (int i = 0; i < 4; i++) // height of the enemy
    {
        gotoxy(x - 1, y + i);
        cout << "           ";
    }
}

// move enemy horizontal lvl 1

void moveEnemyHorizontalLVL1(int &ex, int ey, int &dir)
{
    const int LEFT_LIMIT = 2;
    const int RIGHT_LIMIT = 130 - 8 - 1;

    eraseEnemyTank(ex, ey); // erase previous position
    ex += dir;              // move
    drawEnemyLVL1(ex, ey);  // redraw

    if (ex <= LEFT_LIMIT || ex >= RIGHT_LIMIT)
        dir = -dir;
}

void eraseEnemyLVL2(int x, int y)
{
    for (int i = 0; i < 5; i++) // height of the enemy
    {
        gotoxy(x - 1, y + i);
        cout << "                     "; // width of enemy lvl 2 is 20
    }
}

void eraseEnemyLVL3(int x, int y)
{
    for (int i = 0; i < 5; i++) // height of the enemy
    {
        gotoxy(x - 1, y + i);
        cout << "                   "; // width of enemy lvl 3 is 18
    }
}
void eraseEnemyLVL4(int x, int y)
{
    for (int i = 0; i < 5; i++) // height of the enemy
    {
        gotoxy(x - 1, y + i);
        cout << "           "; // width of enemy lvl 4
    }
}

void eraseEnemyLVL5(int x, int y)
{
    for (int i = 0; i < 5; i++) // height of the enemy
    {
        gotoxy(x - 1, y + i);
        cout << "                     "; // width of enemy lvl 2 is 20
    }
}

// move enemy horizontal lvl 2

void moveEnemyHorizontalLVL2(int &ex, int ey, int &dir)
{
    const int LEFT_LIMIT_lv2 = 2;
    const int RIGHT_LIMIT_lv2 = 130 - 20 - 1;

    eraseEnemyLVL2(ex, ey); // erase previous position
    ex += dir;              // move
    drawEnemyLVL2(ex, ey);  // redraw

    if (ex <= LEFT_LIMIT_lv2 || ex >= RIGHT_LIMIT_lv2)
        dir = -dir;
}

void moveEnemyHorizontalLVL3(int &ex, int ey, int &dir)
{
    const int LEFT_LIMIT = 2;
    const int RIGHT_LIMIT = 130 - 17 - 1;

    eraseEnemyLVL3(ex, ey); // erase previous position
    ex += dir;              // move
    drawEnemyLVL3(ex, ey);  // redraw

    if (ex <= LEFT_LIMIT || ex >= RIGHT_LIMIT)
        dir = -dir;
}

void moveEnemyHorizontalLVL4(int &ex, int ey, int &dir)
{
    const int LEFT_LIMIT = 2;
    const int RIGHT_LIMIT = 130 - 8 - 1;

    eraseEnemyLVL4(ex, ey); // erase previous position
    ex += dir;              // move
    drawEnemyLVL4(ex, ey);  // redraw
    if (ex <= LEFT_LIMIT || ex >= RIGHT_LIMIT)
        dir = -dir;
}

void moveEnemyHorizontalLVL5(int &ex, int ey, int &dir)
{
    const int LEFT_LIMIT_lv2 = 2;
    const int RIGHT_LIMIT_lv2 = 130 - 20 - 1;

    eraseEnemyLVL5(ex, ey); // erase previous position
    ex += dir;              // move
    drawEnemyLVL5(ex, ey);  // redraw

    if (ex <= LEFT_LIMIT_lv2 || ex >= RIGHT_LIMIT_lv2)
        dir = -dir;
}

// Draw bullet lvl 1 enemy
void drawBulletLVL1(int x, int y)
{
    gotoxy(x, y);
    cout << "*"; // bullet symbol
}
// Draw bullet lvl 2
void drawBulletLVL2(int x, int y)
{
    gotoxy(x, y);
    cout << "||"; // bullet symbol
}

// Draw bullet lvl 1 enemy
void drawBulletLVL3(int x, int y)
{
    gotoxy(x, y);
    cout << "*"; // bullet symbol
}

// Erase bullet
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " "; // erase
}

// Erase bullet
void eraseBulletLVL2(int x, int y)
{
    gotoxy(x, y);
    cout << "  "; // erase
}

// Erase bullet
void eraseBulletLVL3(int x, int y)
{
    gotoxy(x, y);
    cout << " "; // erase
}

void fireEnemy(int enemyIndex, int ex, int ey)
{

    const int BOTTOM_LIMIT = 37;
    if (enemyIndex == 1 && !b1active)
    {
        b1x = ex + 3;
        b1y = ey + 4;
        b1active = true;
    }
    else if (enemyIndex == 2 && !b2active)
    {
        b2x = ex + 3;
        b2y = ey + 4;
        b2active = true;
    }
    else if (enemyIndex == 3 && !b3active)
    {
        b3x = ex + 3;
        b3y = ey + 4;
        b3active = true;
    }
}

// fire enemy lvl2
void fireEnemyLVL2(int ex, int ey)
{
    if (!b1active)
    {
        b1x = ex + 9; // center of aircraft
        b1y = ey + 5; // bottom of aircraft
        b1active = true;
    }
}

void fireEnemyLVL3(int enemyIndex, int ex, int ey)
{
    if (enemyIndex == 1 && !b1active)
    {
        b1x = ex + 3;
        b1y = ey + 4;
        b1active = true;
    }
    else if (enemyIndex == 2 && !b2active)
    {
        b2x = ex + 3;
        b2y = ey + 4;
        b2active = true;
    }
    else if (enemyIndex == 3 && !b3active)
    {
        b3x = ex + 3;
        b3y = ey + 4;
        b3active = true;
    }
}
// Update enemy bullet LVL1

void updateBullet(int &bx, int &by, bool &active, int e1x, int e1y, int e2x, int e2y, int e3x, int e3y)
{
    if (!active)
        return;

    eraseBullet(bx, by);
    by++;

    if (by > 37)
    {
        active = false;
        return;
    }

    // collision with enemies
    if ((bx >= e1x && bx <= e1x + 7 && by >= e1y && by <= e1y + 3) ||
        (bx >= e2x && bx <= e2x + 7 && by >= e2y && by <= e2y + 3) ||
        (bx >= e3x && bx <= e3x + 7 && by >= e3y && by <= e3y + 3))
    {
        active = false;
        return;
    }

    // collision with player
    if (bx >= px && bx <= px + 3 && by >= py && by <= py + 3)
    {
        pHealth--;
        active = false;
        return;
    }

    drawBulletLVL1(bx, by);
}

// Update enemy bullet LVL2

void updateBulletLVL2(int &bx, int &by, bool &active, int e1x, int e1y)
{
    if (!active)
        return;

    eraseBulletLVL2(bx, by);
    by++;

    if (by > 37)
    {
        active = false;
        return;
    }

    // collision with enemies
    if ((bx >= e1x && bx <= e1x + 7 && by >= e1y && by <= e1y + 3))
    {
        active = false;
        return;
    }

    // collision with player
    if (bx >= px && bx <= px + 3 && by >= py && by <= py + 3)
    {
        pHealth--;
        active = false;
        return;
    }

    drawBulletLVL2(bx, by);
}

void updateBulletLVL3(int &bx, int &by, bool &active, int e1x, int e1y, int e2x, int e2y, int e3x, int e3y)
{
    if (!active)
        return;

    eraseBulletLVL3(bx, by);
    by++;

    if (by > 37)
    {
        active = false;
        return;
    }

    // collision with enemies
    if ((bx >= e1x && bx <= e1x + 7 && by >= e1y && by <= e1y + 3) ||
        (bx >= e2x && bx <= e2x + 7 && by >= e2y && by <= e2y + 3) ||
        (bx >= e3x && bx <= e3x + 7 && by >= e3y && by <= e3y + 3))
    {
        active = false;
        return;
    }

    // collision with player
    if (bx >= px && bx <= px + 3 && by >= py && by <= py + 3)
    {
        pHealth--;
        active = false;
        return;
    }

    drawBulletLVL2(bx, by);
}
// draw player bullet

void drawPlayerBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "^";
}

// Erase Player bullet

void erasePlayerBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

// Update player bullet

void updatePlayerBullet()
{
    if (!pBulActive)
        return;

    erasePlayerBullet(pBulX, pBulY);
    pBulY--;

    if (pBulY < 1)
    {
        pBulActive = false;
        return;
    }

    // collision with enemies
    if ((pBulX >= b1x && pBulX <= b1x + 7 && pBulY >= b1y && pBulY <= b1y + 3) ||
        (pBulX >= b2x && pBulX <= b2x + 7 && pBulY >= b2y && pBulY <= b2y + 3) ||
        (pBulX >= b3x && pBulX <= b3x + 7 && pBulY >= b3y && pBulY <= b3y + 3))
    {
        pBulActive = false;
        return;
    }

    drawPlayerBullet(pBulX, pBulY);
}

// player input using arrow keys and space
void handlePlayerInput()
{
    if (_kbhit())
    {
        char ch = _getch();
        if (ch == -32) // arrow keys prefix
        {
            ch = _getch();
            if (ch == 75)
                pdir = -1; // left arrow
            else if (ch == 77)
                pdir = 1; // right arrow
        }
        if (ch == ' ') // space bar for firing
        {
            firePlayerBullet(px, py);
        }
    }
}

void movePlayer()
{
    // erase current player
    for (int i = 0; i < 4; i++)
    {
        gotoxy(px, py + i);
        cout << "    ";
    }

    // update position
    px += pdir;

    // limits maze wall
    if (px < 2)
        px = 2;
    if (px > 130 - 4 - 1)
        px = 130 - 4 - 1;

    drawPlayer(px, py);

    // reset direction
    pdir = 0;
}

// fire player bullet

void firePlayerBullet(int px, int py)
{
    for (int i = 0; i < MAX_PBULLETS; i++)
    {
        if (!pBulletActive[i])
        {
            pBulletX[i] = px + 2; // tank center
            pBulletY[i] = py;     // player top row
            pBulletActive[i] = true;
            break;
        }
    }
}

// update player bullet

void updatePlayerBullets(int e1x, int e1y, int &e1Health,
                         int e2x, int e2y, int &e2Health,
                         int e3x, int e3y, int &e3Health)
{
    for (int i = 0; i < MAX_PBULLETS; i++)
    {
        if (!pBulletActive[i])
            continue;

        eraseBullet(pBulletX[i], pBulletY[i]);
        pBulletY[i]--; // move up

        if (pBulletY[i] < 1)
        {
            pBulletActive[i] = false;
            continue;
        }

        // ENEMY 1
        if (e1Health > 0 &&
            pBulletX[i] >= e1x && pBulletX[i] <= e1x + 7 &&
            pBulletY[i] >= e1y && pBulletY[i] <= e1y + 3)
        {
            e1Health--;
            score++;
            pBulletActive[i] = false;

            if (e1Health <= 0)
            {
                eraseEnemyTank(e1x, e1y);
            }
            continue;
        }

        // ENEMY 2
        if (e2Health > 0 &&
            pBulletX[i] >= e2x && pBulletX[i] <= e2x + 7 &&
            pBulletY[i] >= e2y && pBulletY[i] <= e2y + 3)
        {
            e2Health--;
            score++;
            pBulletActive[i] = false;

            if (e2Health <= 0)
            {
                eraseEnemyTank(e2x, e2y);
            }
            continue;
        }

        //  ENEMY 3
        if (e3Health > 0 &&
            pBulletX[i] >= e3x && pBulletX[i] <= e3x + 7 &&
            pBulletY[i] >= e3y && pBulletY[i] <= e3y + 3)
        {
            e3Health--;
            score++;
            pBulletActive[i] = false;

            if (e3Health <= 0)
            {
                eraseEnemyTank(e3x, e3y);
            }
            continue;
        }

        drawPlayerBullet(pBulletX[i], pBulletY[i]);
    }
}
// update player bullet

void updatePlayerBulletsLVL2(int e1x, int e1y, int &e1Health)
{
    for (int i = 0; i < MAX_PBULLETS; i++)
    {
        if (!pBulletActive[i])
            continue;

        eraseBullet(pBulletX[i], pBulletY[i]);
        pBulletY[i]--; // move up

        if (pBulletY[i] < 1)
        {
            pBulletActive[i] = false;
            continue;
        }

        if (e1Health > 0 &&
            pBulletX[i] >= e1x && pBulletX[i] <= e1x + 20 &&
            pBulletY[i] >= e1y && pBulletY[i] <= e1y + 5)
        {
            e1Health--;
            score++;
            pBulletActive[i] = false;

            if (e1Health <= 0)
            {
                eraseEnemyLVL2(e1x, e1y);
            }
            continue;
        }

        drawPlayerBullet(pBulletX[i], pBulletY[i]);
    }
}

// update player bullet

void updatePlayerBulletsLVL3(int e1x, int e1y, int &e1Health,
                             int e2x, int e2y, int &e2Health,
                             int e3x, int e3y, int &e3Health)
{
    for (int i = 0; i < MAX_PBULLETS; i++)
    {
        if (!pBulletActive[i])
            continue;

        eraseBullet(pBulletX[i], pBulletY[i]);
        pBulletY[i]--; // move up

        if (pBulletY[i] < 1)
        {
            pBulletActive[i] = false;
            continue;
        }

        // ENEMY 1
        if (e1Health > 0 &&
            pBulletX[i] >= e1x && pBulletX[i] <= e1x + 7 &&
            pBulletY[i] >= e1y && pBulletY[i] <= e1y + 3)
        {
            e1Health--;
            score++;
            pBulletActive[i] = false;

            if (e1Health <= 0)
            {
                eraseEnemyLVL3(e1x, e1y);
            }
            continue;
        }

        // ENEMY 2
        if (e2Health > 0 &&
            pBulletX[i] >= e2x && pBulletX[i] <= e2x + 7 &&
            pBulletY[i] >= e2y && pBulletY[i] <= e2y + 3)
        {
            e2Health--;
            score++;
            pBulletActive[i] = false;

            if (e2Health <= 0)
            {
                eraseEnemyLVL3(e2x, e2y);
            }
            continue;
        }

        //  ENEMY 3
        if (e3Health > 0 &&
            pBulletX[i] >= e3x && pBulletX[i] <= e3x + 7 &&
            pBulletY[i] >= e3y && pBulletY[i] <= e3y + 3)
        {
            e3Health--;
            score++;
            pBulletActive[i] = false;

            if (e3Health <= 0)
            {
                eraseEnemyLVL3(e3x, e3y);
            }
            continue;
        }

        drawPlayerBullet(pBulletX[i], pBulletY[i]);
    }
}

// display score + health

void displayStats()
{
    gotoxy(100, 0);
    cout << "                    "; // for clearing the maze
    gotoxy(100, 0);
    cout << "Score: " << score << "  Health: " << pHealth; // now prints score + health
}

// RUN LEVEL 1

void runLevel1()
{
    // RESET LEVEL DATA
    score = 0;
    pHealth = 10;

    int e1x = 10, e1y = 3, e1dir = 1, e1Health = 5;
    int e2x = 40, e2y = 7, e2dir = 1, e2Health = 5;
    int e3x = 70, e3y = 12, e3dir = 1, e3Health = 5;

    maze();
    drawPlayer(px, py);

    while (true)
    {
        handlePlayerInput();
        movePlayer();

        // move enemy horizontal

        if (e1Health > 0)
            moveEnemyHorizontalLVL1(e1x, e1y, e1dir);

        if (e2Health > 0)
            moveEnemyHorizontalLVL1(e2x, e2y, e2dir);

        if (e3Health > 0)
            moveEnemyHorizontalLVL1(e3x, e3y, e3dir);

        // ENEMY FIRE
        if (e1Health > 0 && !b1active)
            fireEnemy(1, e1x, e1y);

        if (e2Health > 0 && !b2active)
            fireEnemy(2, e2x, e2y);

        if (e3Health > 0 && !b3active)
            fireEnemy(3, e3x, e3y);

        updatePlayerBullets(e1x, e1y, e1Health,
                            e2x, e2y, e2Health,
                            e3x, e3y, e3Health);

        updateBullet(b1x, b1y, b1active, e1x, e1y, e2x, e2y, e3x, e3y);
        updateBullet(b2x, b2y, b2active, e1x, e1y, e2x, e2y, e3x, e3y);
        updateBullet(b3x, b3y, b3active, e1x, e1y, e2x, e2y, e3x, e3y);

        displayStats();

        // WIN
        if (e1Health <= 0 && e2Health <= 0 && e3Health <= 0)
        {
            gotoxy(50, 18);
            cout << "YOU WIN!";
            Sleep(2000);
            userLevel++;
            saveProgress();
            runLevel2();
        }

        // GAME OVER
        if (pHealth <= 0)
        {
            gotoxy(50, 18);
            cout << "GAME OVER!";
            Sleep(2000);
            break;
        }

        Sleep(70);
    }
    Sleep(70);
}

// RUN LEVEL 2

void runLevel2()
{
    // RESET LEVEL DATA
    score = 0;
    pHealth = 10;

    int e1x = 10, e1y = 3, e1dir = 1, e1Health = 20;

    maze();
    drawPlayer(px, py);

    while (true)
    {
        handlePlayerInput();
        movePlayer();

        // move enemy horizontal

        if (e1Health > 0)
            moveEnemyHorizontalLVL2(e1x, e1y, e1dir);

        // ENEMY FIRE
        if (e1Health > 0 && !b1active)
            fireEnemyLVL2(e1x, e1y);

        updatePlayerBulletsLVL2(e1x, e1y, e1Health);

        updateBulletLVL2(b1x, b1y, b1active, e1x, e1y);

        displayStats();

        // WIN
        if (e1Health <= 0)
        {
            gotoxy(50, 18);
            cout << "YOU WIN!";
            userLevel++;
            saveProgress();
            Sleep(2000);
            runLevel3();
        }

        // GAME OVER
        if (pHealth <= 0)
        {
            gotoxy(50, 18);
            cout << "GAME OVER!";
            Sleep(2000);
            break;
        }

        Sleep(70);
    }
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

// RUN LEVEL 3

void runLevel3()
{
    // RESET LEVEL DATA
    score = 0;
    pHealth = 10;

    int e1x = 10, e1y = 2, e1dir = 1, e1Health = 5;
    int e2x = 40, e2y = 8, e2dir = 1, e2Health = 5;
    int e3x = 70, e3y = 14, e3dir = 1, e3Health = 5;

    maze();
    drawPlayer(px, py);

    while (true)
    {
        handlePlayerInput();
        movePlayer();

        // move enemy horizontal

        if (e1Health > 0)
            moveEnemyHorizontalLVL3(e1x, e1y, e1dir);

        if (e2Health > 0)
            moveEnemyHorizontalLVL3(e2x, e2y, e2dir);

        if (e3Health > 0)
            moveEnemyHorizontalLVL3(e3x, e3y, e3dir);

        // ENEMY FIRE
        if (e1Health > 0 && !b1active)
            fireEnemyLVL3(1, e1x, e1y);

        if (e2Health > 0 && !b2active)
            fireEnemyLVL3(2, e2x, e2y);

        if (e3Health > 0 && !b3active)
            fireEnemyLVL3(3, e3x, e3y);

        updatePlayerBulletsLVL3(e1x, e1y, e1Health,
                                e2x, e2y, e2Health,
                                e3x, e3y, e3Health);

        updateBullet(b1x, b1y, b1active, e1x, e1y, e2x, e2y, e3x, e3y);
        updateBullet(b2x, b2y, b2active, e1x, e1y, e2x, e2y, e3x, e3y);
        updateBullet(b3x, b3y, b3active, e1x, e1y, e2x, e2y, e3x, e3y);

        displayStats();

        // WIN
        if (e1Health <= 0 && e2Health <= 0 && e3Health <= 0)
        {
            gotoxy(50, 18);
            cout << "YOU WIN!";
            userLevel++;
            saveProgress();
            Sleep(2000);
            runLevel4();
        }

        // GAME OVER
        if (pHealth <= 0)
        {
            gotoxy(50, 18);
            cout << "GAME OVER!";
            Sleep(2000);
            break;
        }

        Sleep(100);
    }
    Sleep(80);
}

// Load users from file

void loadUsersFromFile()
{
    ifstream file("users.txt");
    if (!file)
        return;

    totalUsers = 0;
    while (file >> usernames[totalUsers] >> passwords[totalUsers] >> userLevels[totalUsers])
    {
        totalUsers++;
    }
    file.close();
}

// Save users to file

void saveUsersToFile()
{
    ofstream file("users.txt");
    for (int i = 0; i < totalUsers; i++)
    {
        file << usernames[i] << " "
             << passwords[i] << " "
             << userLevels[i] << endl;
    }
    file.close();
}

// LEVEL 4

void runLevel4()
{
    // RESET LEVEL DATA
    score = 0;
    pHealth = 10;

    int e1x = 15, e1y = 3, e1dir = 1, e1Health = 8;
    int e2x = 50, e2y = 8, e2dir = 1, e2Health = 8;
    int e3x = 85, e3y = 13, e3dir = 1, e3Health = 8;

    maze();
    drawPlayer(px, py);

    while (true)
    {
        handlePlayerInput();
        movePlayer();

        // MOVE ENEMIES (TANKS)
        if (e1Health > 0)
            moveEnemyHorizontalLVL4(e1x, e1y, e1dir);
        if (e2Health > 0)
            moveEnemyHorizontalLVL4(e2x, e2y, e2dir);
        if (e3Health > 0)
            moveEnemyHorizontalLVL4(e3x, e3y, e3dir);

        // ENEMY FIRE
        if (e1Health > 0 && !b1active)
            fireEnemy(1, e1x, e1y);
        if (e2Health > 0 && !b2active)
            fireEnemy(2, e2x, e2y);
        if (e3Health > 0 && !b3active)
            fireEnemy(3, e3x, e3y);

        updatePlayerBullets(e1x, e1y, e1Health,
                            e2x, e2y, e2Health,
                            e3x, e3y, e3Health);

        updateBullet(b1x, b1y, b1active, e1x, e1y, e2x, e2y, e3x, e3y);
        updateBullet(b2x, b2y, b2active, e1x, e1y, e2x, e2y, e3x, e3y);
        updateBullet(b3x, b3y, b3active, e1x, e1y, e2x, e2y, e3x, e3y);

        displayStats();

        // WIN CONDITION
        if (e1Health <= 0 && e2Health <= 0 && e3Health <= 0)
        {
            gotoxy(50, 18);
            cout << "YOU WIN!";
            userLevel++;
            saveProgress();
            Sleep(2000);
            runLevel5();
        }

        // GAME OVER
        if (pHealth <= 0)
        {
            gotoxy(50, 18);
            cout << "GAME OVER!";
            Sleep(2000);
            break;
        }

        Sleep(60);
    }
}

// LEVEL 5 FUNCTION

void runLevel5()
{
    // RESET LEVEL DATA
    score = 0;
    pHealth = 10;

    int e1x = 25, e1y = 3, e1dir = 1, e1Health = 25;
    int e2x = 70, e2y = 9, e2dir = 1, e2Health = 25;

    maze();
    drawPlayer(px, py);

    while (true)
    {
        handlePlayerInput();
        movePlayer();

        // MOVE AIRCRAFT
        if (e1Health > 0)
            moveEnemyHorizontalLVL5(e1x, e1y, e1dir);
        if (e2Health > 0)
            moveEnemyHorizontalLVL5(e2x, e2y, e2dir);

        // ENEMY FIRE
        if (e1Health > 0 && !b1active)
            fireEnemyLVL2(e1x, e1y);
        if (e2Health > 0 && !b2active)
            fireEnemyLVL2(e2x, e2y);

        updatePlayerBulletsLVL2(e1x, e1y, e1Health);
        updatePlayerBulletsLVL2(e2x, e2y, e2Health);

        updateBulletLVL2(b1x, b1y, b1active, e1x, e1y);
        updateBulletLVL2(b2x, b2y, b2active, e2x, e2y);

        displayStats();

        // WIN
        if (e1Health <= 0 && e2Health <= 0)
        {
            gotoxy(50, 18);
            cout << "YOU WIN!";
            Sleep(2000);
            break;
        }

        // GAME OVER
        if (pHealth <= 0)
        {
            gotoxy(50, 18);
            cout << "GAME OVER!";
            Sleep(2000);
            break;
        }

        Sleep(80);
    }
}

void drawBox(int x, int y, int width)
{
    gotoxy(x - 2, y - 1);
    cout << char(218);
    for (int i = 0; i < width + 2; i++)
        cout << char(196);
    cout << char(191);

    gotoxy(x - 2, y);
    cout << char(179);
    gotoxy(x + width + 1, y);
    cout << char(179);

    gotoxy(x - 2, y + 1);
    cout << char(192);
    for (int i = 0; i < width + 2; i++)
        cout << char(196);
    cout << char(217);
}

void eraseBox(int x, int y, int width)
{
    // Top
    gotoxy(x - 2, y - 1);
    cout << " " << string(width + 2, ' ') << " ";

    // Sides
    gotoxy(x - 2, y);
    cout << " ";
    gotoxy(x + width + 1, y);
    cout << " ";

    // Bottom
    gotoxy(x - 2, y + 1);
    cout << " " << string(width + 2, ' ') << " ";
}