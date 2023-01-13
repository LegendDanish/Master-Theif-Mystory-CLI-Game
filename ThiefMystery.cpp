// Library Files................
#include <conio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;
//******************************************* Function Prototypes *********************************************
void DrawGameWindow();  // FOR GAME WINDOW
void DrawWindowSpace(); // Draw GAME Window Spaces
void DrawTileSace();
void diamnond(int A_x, int B_x, int A_y, int B_y);
void DrawGameStyles();                             // GAME Window Style for info
void Gameinfo();                                   // GAME Info for display energy,lives,timer
void Timer();                                      // To Manage Timer
void gotoxy(int x, int y);                         // To Manage Controls in Game
void policeGuard();                                // Security Police to give protection to Diamond
void DrawRoom(int A_x, int B_x, int A_y, int B_y); // Draw Security Room
void Drawthief();                                  // Draw thief design
void thiefmovement();                              // Thief Movement
void ThiefLeft();                                  // Move Thief Left
void ThiefRight();                                 // Move Thief Right
void ThiefUP();                                    // Move Thief Up
void ThiefDown();                                  // Move Thief Down
void Alarm();                                      // Alarm Vibrate
void PoliceMove();                                 // Police Movement While protect the Diamond
void PoliceFire();                                 // Police Fire When Thief
void PoliceFirecontinues();
void fire();
void Draw2Theif(); // Draw 2nd Thief with different Mission
void Erase();      // When Bullet Hit Erase Thief
void TimerShape(); // Timer Shape Design
void ThiefFire();  // Thief Fire When Alarm is Off
void diamnondopen();
void CloseRoom(); // When Theif Enter in Room Then Room Door is Close
void DrawAlarmAndDiamond();
void DrawChip();                         // Draw Computer Security Chip
void DrawTiles();                        // Draw Comuputerize Attacker Tiles
void GameStartWindow();                  // Draw Game Window
void StartWindow();                      // Game starting window
void thiefLeft();                        // Thief Left Movement
void thiefDown();                        // Thief Down Movement
void thiefUP();                          // Thief Up Movement
void thiefRight();                       // Thief Down Movement
void Thief2Movement();                   // Thief Movement Function
void TilesAttack();                      // Security Tiles
void DrawRightPath();                    // Correct Path
void CONTROLS();                         // Controls of game
void Instructions();                     // Instruction of game
void DisplayBox();                       // Background Box
void DrawCode();                         // Security Code
void DrawSecurity();                     // Computerize Secrity
void SecurityMove();                     // Security Movement
void SecurityFire();                     // Security Fire
void Thief3Left();                       // Thief 3 Left Move
void Thief3Right();                      // Thief 3 Right Move
void Thief3Down();                       // Thief 3 Down Move
void Thief3UP();                         // Thief 3 Up Move
void Theif3Movement();                   // Thief 3 Movement Function
void Thief3Fire();                       // Thief 3 Fire
int BestTime();                          // Best Time
void LoadTime();                         // Load Best Time
void StoreTime();                        // Store Best Timae
void addtimetoarray(int mint, int sece); // Add Time To array
void BestTIME();                         // Best Time Calculate
void Messages();                         // For Display Message
void Health();                           // For Security Health
void Bomb();                             // Randomly Bomb
bool RandomBomb();                       // Randomly Bomb Movement
void Level3Messages();
void Health_3();
void WinnerMessages();
//****************************************** Data Structures **********************************************

int x1_thief = 38,
    x2_thief = 39, y1_thief = 69, y2_thief = 70, y3_thief = 71;                     // Thief Movement Positions
int score = 0, count = 0, mint = 0, count1 = 0;                                     // To Manage/Control Timer
int x1_police = 12, x2_police = 13, y1_police = 71, y2_police = 72, y3_police = 73; // Police Movement Positions
int x1_security1 = 12, x2_security1 = 13, y1_security1 = 62, security1count = 0;
int x1_security2 = 12, x2_security2 = 13, y1_security2 = 88, security2count = 0;
int x1_Security1Fire = x2_security1 + 1, y1_Security1Fire = y1_security1;
int x1_Security2Fire = x2_security2 + 1, y1_Security2Fire = y1_security2;
int x_Fire = x2_police + 1, y_Fire = y2_police, x2_Fire = x2_police, y2_Fire = y2_police; // Police fire Position
int x_TFire, y_TFire;                                                                     // Thief Fire
int lives = 5, energy = 5;                                                                // I give up to 9 lives to my thief / T give up to 8 energy to each live
int Alarm_count = 0, police = 0, Thief = 0, Thief2 = 0;                                   //
int Level = 1;
int x1_bomb = 14, y1_bomb = 14;
int x1_Tiles = 15, x2_Tiles = 32, y1_Tiles = 38, y2_Tiles = 115, option;
int x1_Alarm = 18, y1_Alarm = 73, Alarm_count1 = 0, police_count = 5, police_count1 = 5, Pcount = 0, FireCount = 0;
int minte[2000], sec[2000];
int bestS, timecount = 0, result;

main()
{
    LoadTime();
    system("cls");
    StartWindow();
    getch();
    system("cls");
    while (true)
    {
        system("cls");
        GameStartWindow();
        gotoxy(1, 1);
        cin >> option;
        gotoxy(1, 1);
        cout << " ";
        if (option == 4)
        {
            system("Cls");
            Instructions();
            getch();
            continue;
        }
        if (option == 3)
        {
            system("Cls");
            CONTROLS();
            getch();
            continue;
        }

        if (option == 2)
        {
            system("cls");
            BestTIME();
            getch();
            continue;
        }
        if (option == 1)
        {
            if (Level == 1)
            {
                system("cls");
                Messages();
                x1_thief = 38,
                x2_thief = 39, y1_thief = 69, y2_thief = 70, y3_thief = 71;

                Level = 2;
                DrawGameWindow();
                DrawGameStyles();
                Gameinfo();
                DrawRoom(6, 113, 37, 35);
                Drawthief();
                TimerShape();
                diamnond(7, 79, 69, 11);
                DrawAlarmAndDiamond();
                policeGuard();
                while (true)
                {
                    PoliceMove();
                    score++;
                    Timer();
                    thiefmovement();
                    score++;
                    Timer();
                    Alarm();
                    if (Thief == 1)
                    {
                        Thief++;
                        diamnondopen();
                    }
                    if (x1_thief == 32)
                    {
                        CloseRoom();
                    }
                    if (mint == 4)
                    {
                        getch();
                        break;
                        system("cls");
                        Level = 1;
                    }
                    if (lives == 0)
                    {
                        getch();
                        break;
                        system("cls");
                        Level = 1;
                    }
                    if (x1_thief == 8 && y2_thief == 74)
                    {
                        WinnerMessages();
                        getch();
                        break;
                        system("cls");
                    }
                }
            }
            if (Level == 2)
            {
                system("cls");
                Level = 3;
                x1_thief = 38, x2_thief = 39, y2_thief = 70, lives = 9;
                energy = 8;
                DrawGameWindow();
                DrawGameStyles();
                Gameinfo();
                DrawRoom(6, 113, 37, 35);
                Draw2Theif();
                TimerShape();
                diamnond(7, 79, 69, 10);
                DrawChip();
                while (true)
                {
                    Thief2Movement();
                    if (x1_thief == 35)
                    {
                        DrawTiles();
                    }
                    if (x1_thief == 33)
                    {
                        CloseRoom();
                        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(n, 12);
                        gotoxy(23, 74);
                        char j = 254;
                        cout << j;
                    }
                    if (Thief2 == 1)
                    {
                        Thief2++;
                        diamnondopen();
                    }
                    if (mint == 4)
                    {
                        getch();
                        break;
                        Level = 2;
                    }
                    if (lives == 0)
                    {
                        getch();
                        break;
                        Level = 2;
                    }
                    if (x1_thief == 8 && y2_thief == 74)
                    {
                        WinnerMessages();
                        getch();
                        break;
                        system("cls");
                    }
                }
            }
            if (Level == 3)
            {
                system("cls");
                Level3Messages();
                Level = 4;
                x1_thief = 38, x2_thief = 39, y2_thief = 70, lives = 2;
                DrawGameWindow();
                DrawGameStyles();
                Gameinfo();
                DrawRoom(6, 113, 37, 35);
                Draw2Theif();
                DrawSecurity();
                TimerShape();
                diamnond(7, 79, 69, 11);
                DrawCode();
                while (true)
                {

                    SecurityMove();
                    Theif3Movement();
                    if (((x1_thief - 1 == x1_Alarm && y2_thief == y1_Alarm)) || ((x2_thief + 1 == x1_Alarm && y2_thief == y1_Alarm)) || ((x1_thief == x1_Alarm && y2_thief == y1_Alarm + 1)))
                    {
                        char c = 254;
                        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(n, 15);
                        gotoxy(18, 73);
                        cout << c;
                        FireCount = 1;
                        Alarm_count1++;
                    }
                    if (Alarm_count1 == 2)
                    {
                        Alarm_count1--;
                    }
                    if (x1_thief == 33)
                    {
                        CloseRoom();
                        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(n, 12);
                        gotoxy(18, 73);
                        char j = 254;
                        cout << j;
                    }
                    if (Pcount == 2)
                    {
                        Pcount--;
                        diamnondopen();
                    }
                    if (Pcount == 1 && x1_thief == 37)
                    {

                        int mintutes = mint;
                        int second = count;
                        addtimetoarray(mintutes, second);
                        StoreTime();
                        LoadTime();
                        WinnerMessages();
                        getch();
                        system("cls");
                        break;
                    }
                    if (lives == 0)
                    {
                        getch();
                        system("cls");
                        Level = 3;
                        break;
                    }
                    if (mint == 4)
                    {
                        getch();
                        system("cls");
                        Level = 3;
                        break;
                    }
                }
            }
            if (Level == 4)
            {
                Level = 1;
                x1_police = 12, x2_police = 13, y1_police = 71, y2_police = 72, y3_police = 73;
                x1_security1 = 12, x2_security1 = 13, y1_security1 = 62, security1count = 0;
                x1_security2 = 12, x2_security2 = 13, y1_security2 = 88, security2count = 0;
                x1_Security1Fire = x2_security1 + 1, y1_Security1Fire = y1_security1;
                x1_Security2Fire = x2_security2 + 1, y1_Security2Fire = y1_security2;
                x_Fire = x2_police + 1, y_Fire = y2_police, x2_Fire = x2_police, y2_Fire = y2_police;
                x_TFire, y_TFire;
                lives = 5, energy = 5;
                Alarm_count = 0, police = 0, Thief = 0, Thief2 = 0;
                x1_Tiles = 15, x2_Tiles = 32, y1_Tiles = 38, y2_Tiles = 115, option;
                x1_Alarm = 18, y1_Alarm = 73, Alarm_count1 = 0, police_count = 5, police_count1 = 5, Pcount = 0, FireCount = 0;
                getch();
                system("cls");

                mint = 0;
                score = 0;
                count = 0;
                continue;
            }
        }
        if (option == 5)
        {
            break;
        }
    }
}

void WinnerMessages()
{
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 15);
    DrawRoom(3, 145, 117, 40);

    gotoxy(18, 123);
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 15);
    cout << "Congratulations!";
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    if (Level == 2)
    {
        gotoxy(19, 120);
        cout << "You Complete 1st Level";
        gotoxy(20, 120);
        cout << "Now Going to 2nd Level";
        count = 10;
        mint = 1;
    }
    if (Level == 3)
    {
        gotoxy(19, 120);
        cout << "You Complete 2nd Level";
        gotoxy(20, 120);
        cout << "Now Going to 3rd Level";
    }
    if (Level == 4)
    {
        gotoxy(19, 123);
        cout << "YOU WON THE GAME";
        gotoxy(20, 124);
        cout << " MISSION END";
    }
    Sleep(5000);
}
bool RandomBomb()
{
    srand(time(0));
    result = 1 + (rand() % 2);
    return result;
}
void Health()
{
    if (police == 50)
    {
        gotoxy(16, 136);
        cout << "    ";
    }
    if (police == 100)
    {
        gotoxy(16, 132);
        cout << "     ";
    }
    if (police == 150)
    {
        gotoxy(16, 128);
        cout << "    ";
    }
    if (police == 200)
    {
        gotoxy(16, 124);
        cout << "    ";
    }
}

void Health_3()
{
    if (police_count == 4)
    {
        gotoxy(16, 136);
        cout << "    ";
    }
    if (police_count == 3)
    {
        gotoxy(16, 132);
        cout << "     ";
    }
    if (police_count == 2)
    {
        gotoxy(16, 128);
        cout << "    ";
    }
    if (police_count == 0)
    {
        gotoxy(16, 124);
        cout << "    ";
    }
    if (police_count1 == 4)
    {
        gotoxy(19, 136);
        cout << "    ";
    }
    if (police_count1 == 3)
    {
        gotoxy(19, 132);
        cout << "     ";
    }
    if (police_count1 == 2)
    {
        gotoxy(19, 128);
        cout << "    ";
    }
    if (police_count1 == 0)
    {
        gotoxy(19, 124);
        cout << "    ";
    }
}
void Messages()
{
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 15);
    DrawRoom(3, 145, 117, 40);
    gotoxy(15, 124);
    cout << "Security Health";
    char j = 254;
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 12);
    gotoxy(16, 124);
    cout << j << j << j << j << j << j << j << j << j << j << j << j << j << j << j << j;
}
void Level3Messages()
{
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(o, 15);
    DrawRoom(3, 145, 117, 40);
    gotoxy(15, 124);

    cout << "Security_1 Health";
    char j = 254;
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 12);
    gotoxy(16, 124);
    cout << j << j << j << j << j << j << j << j << j << j << j << j << j << j << j << j;
    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(k, 15);
    gotoxy(18, 124);
    cout << "Security_2 Health";
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    gotoxy(19, 124);
    cout << j << j << j << j << j << j << j << j << j << j << j << j << j << j << j << j;
}
void DrawWindowSpace(int A_x, int B_y, int A_y, int B_x)
{
    for (int i = A_x; i < B_x; i++)
    {
        for (int j = A_y; j < B_y; j++)
        {
            gotoxy(i + 1, j);
            cout << " ";
        }
    }
}

void addtimetoarray(int mint, int sece)
{
    minte[timecount] = mint;
    sec[timecount] = sece;
    timecount++;
}
void DrawTileSace(int A_x, int B_y, int A_y, int B_x)
{
    char a = 178;
    for (int i = A_x; i < B_x; i++)
    {
        for (int j = A_y; j < B_y; j++)
        {
            gotoxy(i + 1, j);
            cout << a;
        }
    }
}

void DrawChip()
{
    char h = 177;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 10);
    gotoxy(8, 74);
    cout << h;
}

void DrawCode()
{
    char h = 146, c = 158, b = 225;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 10);
    gotoxy(8, 73);
    cout << h << c << b;
}
int BestTime()
{
    int j;
    int bestM = minte[0];
    bestS = sec[0];
    for (int i = 1; i < timecount; i++)
    {
        if (minte[i] < bestM)
        {
            bestM = minte[i];
            j = i;
            bestS = sec[j];
        }
        else if (minte[i] == bestM)
        {
            if (sec[i] < bestS)
            {
                bestS = sec[i];
                j = i;
            }
            bestS = sec[j];
        }
    }

    return bestM;
}

void LoadTime()
{
    timecount = 0;
    fstream file;
    file.open("score.txt", ios::in);
    while (!(file.eof()))
    {
        file >> minte[timecount];
        file >> sec[timecount];
        timecount++;
    }
    file.close();
}

void StoreTime()
{
    fstream file;
    file.open("score.txt", ios::out);
    for (int i = 0; i < timecount; i++)
    {
        file << minte[i] << " " << sec[i] << endl;
    }
    file.close();
}
void DrawGameWindow()
{
    char a = 205, b = 186, c = 201, e = 187, f = 200, g = 188;
    DrawWindowSpace(1, 115, 33, 40);
    int A_x = 3, B_x = 115, A_y = 35, B_y = 40;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 9);
    for (int i = A_x; i < B_y; i++)
    {
        gotoxy(i + 1, A_y);
        cout << b;
        gotoxy(i + 1, B_x);
        cout << b;
    }
    for (int i = A_y; i < B_x; i++)
    {
        gotoxy(A_x, i);
        cout << a;
        gotoxy(B_y, i);
        cout << a;
    }
    gotoxy(A_x, A_y);
    cout << c;
    gotoxy(B_y, A_y);
    cout << f;
    gotoxy(A_x, B_x);
    cout << e;
    gotoxy(B_y, B_x);
    cout << g;
}
// *Draw Game Info

void TimerShape()
{
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 10);
    gotoxy(2, 113);
    cout << count;
    gotoxy(2, 111);
    cout << ":";
    gotoxy(2, 109);
    cout << mint;
}
void DrawGameStyles()
{
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 15);
    gotoxy(2, 35);
    cout << "LIVES : ";
    gotoxy(2, 68);
    cout << " ENERGY : ";
    gotoxy(2, 102);
    cout << "TIMER ";
}

void Gameinfo()
{
    char Energy = 222;
    char Lives = 3;
    if (energy == 0)
    {
        gotoxy(2, 78);
        cout << " ";
        energy = 5;
        lives--;
    }
    if (lives == 8)
    {
        gotoxy(2, 51);
        cout << " ";
    }
    if (lives == 7)
    {
        gotoxy(2, 50);
        cout << " ";
    }
    if (lives == 6)
    {
        gotoxy(2, 49);
        cout << " ";
    }
    if (lives == 5)
    {
        gotoxy(2, 48);
        cout << " ";
    }
    if (lives == 4)
    {
        gotoxy(2, 47);
        cout << " ";
    }
    if (lives == 3)
    {
        gotoxy(2, 46);
        cout << " ";
    }
    if (lives == 2)
    {
        gotoxy(2, 45);
        cout << " ";
    }
    if (lives == 1)
    {
        gotoxy(2, 44);
        cout << " ";
    }
    if (lives == 0)
    {
        gotoxy(2, 43);
        cout << " ";
    }
    if (energy == 7)
    {
        gotoxy(2, 85);
        cout << " ";
    }
    if (energy == 6)
    {
        gotoxy(2, 84);
        cout << " ";
    }
    if (energy == 5)
    {
        gotoxy(2, 83);
        cout << " ";
    }
    if (energy == 4)
    {
        gotoxy(2, 82);
        cout << " ";
    }
    if (energy == 3)
    {
        gotoxy(2, 81);
        cout << " ";
    }
    if (energy == 2)
    {
        gotoxy(2, 80);
        cout << " ";
    }
    if (energy == 1)
    {
        gotoxy(2, 79);
        cout << " ";
    }

    for (int i = 0; i < lives; i++)
    {

        gotoxy(2, 43 + i);
        HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(m, 12);
        cout << Lives;
        for (int j = 0; j < energy; j++)
        {
            gotoxy(2, 78 + j);
            HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(n, 14);
            cout << Energy;
        }
    }
}

void Timer()
{
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 10);
    Sleep(8);

    if ((x1_thief != 9 && y2_thief != 74) || (x2_thief != 9 && y1_thief != 74) || (x2_thief != 9 && y3_thief != 74) || (x2_thief != 9 && y2_thief != 74))
    {
        if (score == 30)
        {
            if (count == 0)
            {
                gotoxy(2, 114);
                {
                    cout << " ";
                }
            }
            count++;
            gotoxy(2, 113);
            HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(n, 10);
            cout << count;

            score = 0;
        }
        if (count == 60)
        {
            mint++;
            gotoxy(2, 109);
            HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(m, 10);
            cout << mint;
            count = 0;
        }
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = y;
    coordinates.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void DrawRoom(int A_x, int B_x, int A_y, int B_y)
{
    char a = 205, b = 186, c = 201, e = 187, f = 200, g = 188;
    DrawWindowSpace(A_x, B_x, A_y, B_y);
    for (int i = A_x; i < B_y; i++)
    {
        gotoxy(i + 1, A_y);
        cout << b;
        gotoxy(i + 1, B_x);
        cout << b;
    }
    for (int i = A_y; i < B_x; i++)
    {
        gotoxy(A_x, i);
        cout << a;
        gotoxy(B_y, i);
        cout << a;
    }
    gotoxy(A_x, A_y);
    cout << c;
    gotoxy(B_y, A_y);
    cout << f;
    gotoxy(A_x, B_x);
    cout << e;
    gotoxy(B_y, B_x);
    cout << g;
}
void DrawTiles()
{
    char a = 178, b = 186, c = 201, e = 187, f = 200, g = 188;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 14);
    DrawTileSace(16, 112, 38, 33);
    int A_x = 16, B_x = 112, A_y = 38, B_y = 33;
    for (int i = A_x; i < B_y; i++)
    {
        gotoxy(i + 1, A_y);
        cout << a;
        gotoxy(i + 1, B_x);
        cout << a;
    }
    for (int i = A_y; i < B_x; i++)
    {
        gotoxy(A_x, i);
        cout << a;
        gotoxy(B_y, i);
        cout << a;
    }
    gotoxy(A_x, A_y);
    cout << a;
    gotoxy(B_y, A_y);
    cout << a;
    gotoxy(A_x, B_x);
    cout << a;
    gotoxy(B_y, B_x);
    cout << a;
    DrawWindowSpace(22, 76, 73, 23);
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 15);
    gotoxy(23, 74);
    char j = 254;
    cout << j;
}

void DrawRightPath()
{
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(o, 15);
    // When Alarm is off Then this display the Right Path with White Color
    DrawTileSace(15, 55, 50, 33);
    DrawTileSace(24, 73, 55, 28);
    DrawTileSace(15, 100, 95, 33);
    DrawTileSace(24, 95, 76, 28);
}
void TilesAttack()
{

    if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 38 && y2_thief <= 49)))
    {
        energy--;
        Gameinfo();
    }
    else if ((((x1_thief >= 15 && x1_thief <= 24) || (x2_thief > 15 && x2_thief < 24)) && (y2_thief >= 55 && y2_thief <= 72)))
    {
        energy--;
        Gameinfo();
    }
    else if ((((x1_thief >= 28 && x1_thief <= 33) || (x2_thief > 28 && x2_thief < 33)) && (y2_thief >= 55 && y2_thief <= 72)))
    {
        energy--;
        Gameinfo();
    }

    else if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 100 && y2_thief <= 112)))
    {
        energy--;
        Gameinfo();
    }
    else if ((((x1_thief >= 15 && x1_thief <= 24) || (x2_thief > 15 && x2_thief < 24)) && (y2_thief >= 76 && y2_thief <= 94)))
    {
        energy--;
        Gameinfo();
    }
    else if ((((x1_thief >= 28 && x1_thief <= 33) || (x2_thief > 28 && x2_thief < 33)) && (y2_thief >= 76 && y2_thief <= 94)))
    {
        energy--;
        Gameinfo();
    }
    else if ((((x1_thief >= 15 && x1_thief <= 22) || (x2_thief > 15 && x2_thief < 22)) && (y2_thief >= 73 && y2_thief <= 75)))
    {
        energy--;
        Gameinfo();
    }
    else if ((((x1_thief >= 24 && x1_thief <= 33) || (x2_thief > 24 && x2_thief < 33)) && (y2_thief >= 73 && y2_thief <= 75)))
    {
        energy--;
        Gameinfo();
    }
}

void CloseRoom()
{

    char a = 205, b = 186, c = 201, e = 187, f = 200, g = 188;
    int A_x = 6, B_x = 113, A_y = 37, B_y = 35;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 12);
    for (int i = A_y; i < B_x; i++)
    {
        gotoxy(B_y, i);
        cout << a;
    }
    gotoxy(B_y, A_y);
    cout << f;
    gotoxy(B_y, B_x);
    cout << g;
}
void diamnond(int A_x, int B_x, int A_y, int B_y)
{
    char a = 205, b = 186, c = 201, e = 187, f = 200, g = 188;
    DrawWindowSpace(A_x, B_x, A_y, B_y);
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 9);
    for (int i = A_x; i < B_y; i++)
    {
        gotoxy(i + 1, A_y);
        cout << b;
        gotoxy(i + 1, B_x);
        cout << b;
    }
    for (int i = A_y; i < B_x; i++)
    {
        gotoxy(A_x, i);
        cout << a;
        gotoxy(B_y, i);
        cout << a;
    }
    gotoxy(A_x, A_y);
    cout << c;
    gotoxy(B_y, A_y);
    cout << f;
    gotoxy(A_x, B_x);
    cout << e;
    gotoxy(B_y, B_x);
    cout << g;
}

void DrawAlarmAndDiamond()
{
    char h = 4, j = 254;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 15);
    gotoxy(8, 74);
    cout << h;
    gotoxy(20, 111);
    cout << j;
}
void diamnondopen()
{
    char a = 205, b = 186, c = 201, e = 187, f = 200, g = 188, h = 4, j = 254;
    DrawWindowSpace(7, 79, 69, 11);
    int A_x = 7, B_x = 79, A_y = 69, B_y = 11;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 9);
    for (int i = A_x; i < B_y; i++)
    {
        // This Command print the Left Side of Security Box
        gotoxy(i + 1, A_y);
        cout << " ";
        // This Command print the Right side of security Box
        gotoxy(i + 1, B_x);
        cout << " ";
    }
    for (int i = A_y; i < B_x; i++)
    {
        // This command print the upper boarder of Diamond security box.
        gotoxy(A_x, i);
        cout << a;
        gotoxy(B_y, i);
        cout << " ";
    }
    // This Command Print the Upper Left Corner Of Box
    gotoxy(A_x, A_y);
    cout << c;
    // This Command Print the Lower Left Corner Of Box
    gotoxy(B_y, A_y);
    cout << " ";
    // This Command Print the Right Upper Corner of Box
    gotoxy(A_x, B_x);
    cout << e;
    // This Command Print the Lower Right Corner of Box
    gotoxy(B_y, B_x);
    cout << " ";
    if (Level == 2)
    {
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 15);
        gotoxy(8, 74);
        cout << h;
    }
    if (Level == 4)
    {
        DrawCode();
    }
    if (Level == 3)
    {
        DrawChip();
    }
}
void Drawthief()
{
    char j = 239;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    gotoxy(38, 70);
    cout << j;
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 15);
    gotoxy(39, 69);
    cout << "<";
    gotoxy(39, 71);
    cout << ">";
    gotoxy(39, 70);
    cout << "T";
}

void Draw2Theif()
{
    char j = 239;
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    gotoxy(38, 70);
    cout << j;
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 15);
    gotoxy(39, 70);
    cout << "T";
}
void thiefLeft()
{
    char a = 178;
    TilesAttack();
    score++;
    Timer();

    char j = 239;
    if (y2_thief > 38)
    {
        if (x1_thief <= 32 && x2_thief > 16)
        {
            if (y2_thief <= 112 && y2_thief > 38)
            {
                HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(k, 14);

                if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 50 && y2_thief <= 54)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                if ((((x1_thief >= 25 && x1_thief <= 27) || (x2_thief > 25 && x2_thief < 27)) && (y2_thief >= 55 && y2_thief <= 72)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 95 && y2_thief <= 99)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 25 && x1_thief <= 27) || (x2_thief > 25 && x2_thief < 27)) && (y2_thief >= 76 && y2_thief <= 95)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                gotoxy(x1_thief, y2_thief);
                cout << a;
                gotoxy(x2_thief, y2_thief);
                cout << a;

                y2_thief--;

                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 15);
                gotoxy(x1_thief, y2_thief);
                cout << j;
                HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(l, 12);
                gotoxy(x2_thief, y2_thief);
                cout << "T";
            }
        }
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        if (x1_thief > 32 || x1_thief <= 15)
        {
            y2_thief--;
        }
        if (x2_thief == 16)
        {
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 14);

            gotoxy(x2_thief, y2_thief + 1);
            cout << a;
        }
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        TilesAttack();
    }
}

void thiefRight()
{

    char a = 178;
    TilesAttack();
    score++;
    Timer();

    char j = 239;
    if (y2_thief < 112)
    {
        if (x1_thief <= 32 && x2_thief > 16)
        {
            if (y2_thief <= 112 && y2_thief >= 38)
            {
                HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(k, 14);

                if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 50 && y2_thief <= 54)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                if ((((x1_thief >= 25 && x1_thief <= 27) || (x2_thief > 25 && x2_thief < 27)) && (y2_thief >= 55 && y2_thief <= 72)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 95 && y2_thief <= 99)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 25 && x1_thief <= 27) || (x2_thief > 25 && x2_thief < 27)) && (y2_thief >= 76 && y2_thief <= 95)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                gotoxy(x1_thief, y2_thief);
                cout << a;
                gotoxy(x2_thief, y2_thief);
                cout << a;

                y2_thief++;

                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 15);
                gotoxy(x1_thief, y2_thief);
                cout << j;
                HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(l, 12);
                gotoxy(x2_thief, y2_thief);
                cout << "T";
            }
        }
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        if (x1_thief > 32 || x1_thief <= 15)
        {
            y2_thief++;
        }
        if (x2_thief == 16)
        {
            HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(n, 14);

            gotoxy(x2_thief, y2_thief - 1);
            cout << a;
        }
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        TilesAttack();
    }
}
void thiefUP()
{
    char a = 178, j = 239;
    int x = 11, y = 10;
    if (Thief2 > 1)
    {
        x = 8;
        y = 7;
    }
    TilesAttack();
    score++;
    Timer();
    if (x1_thief > x && x2_thief > y)
    {
        if (x1_thief <= 32 && x2_thief >= 16)
        {
            if (y2_thief <= 112 && y2_thief >= 38)
            {
                HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(k, 14);

                if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 50 && y2_thief <= 55)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                if ((((x1_thief >= 24 && x1_thief <= 27) || (x2_thief > 26 && x2_thief < 27)) && (y2_thief >= 55 && y2_thief <= 72)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 95 && y2_thief <= 100)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 24 && x1_thief <= 27) || (x2_thief > 26 && x2_thief < 27)) && (y2_thief >= 76 && y2_thief <= 95)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                gotoxy(x1_thief, y2_thief);
                cout << a;
                gotoxy(x2_thief, y2_thief);
                cout << a;
                x1_thief--;
                x2_thief--;
                if (x1_thief == 14)
                {
                    gotoxy(x2_thief + 1, y2_thief);
                    cout << a;
                }
                if (x1_thief == 15)
                {
                    Thief2++;
                }
                if (((x1_thief > 23 && x1_thief <= 24) || (x2_thief > 23 && x2_thief <= 24) || (x2_thief <= 23 && x2_thief <= 24)) && (y2_thief >= 73 && y2_thief <= 76))
                {

                    DrawWindowSpace(22, 76, 73, 23);
                    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(n, 15);
                    gotoxy(23, 74);
                    char j = 254;
                    cout << j;
                    DrawRightPath();
                }
                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 15);
                gotoxy(x1_thief, y2_thief);
                cout << j;
                HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(l, 12);
                gotoxy(x2_thief, y2_thief);
                cout << "T";
            }
        }

        // Sleep(0);
        char j = 239;
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        if (x1_thief > 32 || x1_thief < 15)
        {
            x1_thief--;
            x2_thief--;
        }
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        TilesAttack();
    }
}

void thiefDown()
{
    char a = 178, j = 239;
    TilesAttack();
    score++;
    Timer();
    if (x1_thief < 32 && x2_thief < 33)
    {
        if (x1_thief <= 32 && x1_thief > 15)
        {
            if (y2_thief <= 112 && y2_thief >= 38)
            {
                HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(k, 14);

                if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 50 && y2_thief <= 55)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                if ((((x1_thief >= 25 && x1_thief <= 28) || (x2_thief > 25 && x2_thief < 27)) && (y2_thief >= 55 && y2_thief <= 72)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 15 && x1_thief <= 33) || (x2_thief > 15 && x2_thief < 33)) && (y2_thief >= 95 && y2_thief <= 100)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                else if ((((x1_thief >= 25 && x1_thief <= 28) || (x2_thief > 25 && x2_thief < 27)) && (y2_thief >= 76 && y2_thief <= 95)))
                {
                    HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(k, 15);
                }
                gotoxy(x1_thief, y2_thief);
                cout << a;
                gotoxy(x2_thief, y2_thief);
                cout << a;
                if (((x1_thief > 23 && x1_thief <= 24) || (x2_thief > 23 && x2_thief <= 24) || (x2_thief == 23 && x2_thief <= 24)) && (y2_thief >= 73 && y2_thief <= 76))
                {
                    DrawWindowSpace(22, 76, 73, 23);
                    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(n, 15);
                    gotoxy(23, 74);
                    char j = 254;
                    cout << j;
                }
                x1_thief++;
                x2_thief++;
                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 15);
                gotoxy(x1_thief, y2_thief);
                cout << j;
                HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(l, 12);
                gotoxy(x2_thief, y2_thief);
                cout << "T";
            }
        }

        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        if (x1_thief > 32 || x1_thief <= 15)
        {
            x1_thief++;
            x2_thief++;
        }
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        TilesAttack();
    }
}

void policeGuard()
{
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    char j = 220;
    gotoxy(12, 72);
    cout << j;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 9);
    gotoxy(13, 72);
    cout << "P";
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 15);
    gotoxy(13, 71);
    cout << "<";
    gotoxy(13, 73);
    cout << ">";
}
void DrawSecurity()
{
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 12);
    char j = 220;
    gotoxy(12, 62);
    cout << j;
    gotoxy(12, 88);
    cout << j;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 9);
    gotoxy(13, 62);
    cout << "P";
    gotoxy(13, 88);
    cout << "P";
    char c = 254;
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 15);
    gotoxy(18, 73);
    cout << c;
}

void thiefmovement()
{
    PoliceMove();
    score++;
    Timer();
    Sleep(0);
    if (GetAsyncKeyState(VK_LEFT))
    {
        ThiefLeft(); // Move Thief Left
        score++;
        Timer();
        PoliceMove();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        ThiefRight(); // Move Thief Right
        score++;
        Timer();
        PoliceMove();
    }

    if (GetAsyncKeyState(VK_UP))
    {
        ThiefUP(); // Move Thief UP
        score++;
        Timer();
        PoliceMove();
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        ThiefDown(); // Move Thief Down
        score++;
        Timer();
        PoliceMove();
    }

    if (GetAsyncKeyState(VK_SPACE))
    {
        ThiefFire(); // Thief Fire When Alarm is off
    }
}

void Thief2Movement()
{
    score++;
    Timer();
    Sleep(50);
    if (GetAsyncKeyState(VK_LEFT))
    {
        thiefLeft(); // Move Thief Left
        score++;
        Timer();
        TilesAttack();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        thiefRight(); // Move Thief Right
        score++;
        Timer();
        TilesAttack();
    }

    if (GetAsyncKeyState(VK_UP))
    {
        thiefUP(); // Move Thief UP
        score++;
        Timer();
        TilesAttack();
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        thiefDown(); // Move Thief Down
        score++;
        Timer();
        TilesAttack();
    }
}

void Theif3Movement()
{
    SecurityMove();
    score++;
    Timer();
    Sleep(0);
    if (GetAsyncKeyState(VK_LEFT))
    {
        Thief3Left(); // Move Thief Left
        score++;
        Timer();
        SecurityMove();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        Thief3Right(); // Move Thief Right
        score++;
        Timer();
        SecurityMove();
    }

    if (GetAsyncKeyState(VK_UP))
    {
        Thief3UP(); // Move Thief UP
        score++;
        Timer();
        SecurityMove();
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        Thief3Down(); // Move Thief Down
        score++;
        Timer();
        SecurityMove();
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        Thief3Fire();
    }
}

void ThiefLeft()
{
    PoliceMove();
    score++;
    Timer();

    char j = 239;
    if (y1_thief > 38 && y2_thief > 38 && y3_thief > 37)
    {
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y1_thief);
        cout << " ";
        gotoxy(x2_thief, y3_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        y2_thief--;
        y1_thief--;
        y3_thief--;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        gotoxy(x2_thief, y1_thief);
        cout << "<";
        gotoxy(x2_thief, y3_thief);
        cout << ">";
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        PoliceMove();
    }
}
void ThiefUP()
{
    int x = 11, y = 10;
    if (Thief > 1)
    {
        x = 7;
        y = 6;
    }
    PoliceMove();
    score++;
    Timer();
    if (x1_thief > x && x2_thief > y)
    {

        char j = 239;
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y1_thief);
        cout << " ";
        gotoxy(x2_thief, y3_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        x1_thief--;
        x2_thief--;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        gotoxy(x2_thief, y1_thief);
        cout << "<";
        gotoxy(x2_thief, y3_thief);
        cout << ">";
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        PoliceMove();
    }
}

void ThiefRight()
{
    PoliceMove();
    score++;
    Timer();

    char j = 239;
    if (y1_thief < 113 && y2_thief < 113 && y3_thief < 112)
    {
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y1_thief);
        cout << " ";
        gotoxy(x2_thief, y3_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        y2_thief++;
        y1_thief++;
        y3_thief++;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        gotoxy(x2_thief, y1_thief);
        cout << "<";
        gotoxy(x2_thief, y3_thief);
        cout << ">";
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        PoliceMove();
    }
}

void ThiefDown()
{

    PoliceMove();
    score++;
    Timer();
    if (x1_thief < 32 && x2_thief < 33)
    {

        char j = 239;
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y1_thief);
        cout << " ";
        gotoxy(x2_thief, y3_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        x1_thief++;
        x2_thief++;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        gotoxy(x2_thief, y1_thief);
        cout << "<";
        gotoxy(x2_thief, y3_thief);
        cout << ">";
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        PoliceMove();
    }
}

void Thief3Left()
{

    SecurityMove();
    score++;
    Timer();
    // Sleep(0);
    char j = 239;
    if (y2_thief > 38)
    {
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        y2_thief--;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        SecurityMove();
    }
}

void Thief3Right()
{
    SecurityMove();
    score++;
    Timer();

    char j = 239;
    if (y2_thief < 113)
    {
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        y2_thief++;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        SecurityMove();
    }
}

void Thief3UP()
{
    char j = 239;
    int x = 11, y = 10;
    if (Pcount == 1)
    {
        x = 8;
        y = 7;
    }
    score++;
    Timer();
    SecurityMove();
    if (x1_thief > x && x2_thief > y)
    {
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        x1_thief--;
        x2_thief--;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        SecurityMove();
    }
}

void Thief3Down()
{
    SecurityMove();
    score++;
    Timer();
    int x = 32, x1 = 33;
    if (Pcount == 1)
    {
        x = 39, x1 = 38;
    }
    if (x1_thief < x && x2_thief < x1)
    {

        char j = 239;
        gotoxy(x1_thief, y2_thief);
        cout << " ";
        gotoxy(x2_thief, y2_thief);
        cout << " ";
        x1_thief++;
        x2_thief++;
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 15);
        gotoxy(x1_thief, y2_thief);
        cout << j;
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 12);
        gotoxy(x2_thief, y2_thief);
        cout << "T";
        SecurityMove();
    }
}
void Alarm()
{
    char j = 254;
    if (Alarm_count == 0)
    {
        if (x1_thief <= 35)
        {
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 12);
            gotoxy(20, 111);
            cout << j;
        }
    }
    if ((x1_thief - 1 == 20 && y2_thief == 111) || (x2_thief - 1 == 20 && y3_thief == 111))
    {
        HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(l, 15);
        gotoxy(20, 111);
        cout << j;
        Alarm_count++;
    }
    if (Alarm_count == 1)
    {
        if (x1_thief <= 35)
        {
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 15);
            gotoxy(20, 111);
            cout << j;
        }
    }
}

void PoliceMove()
{
    if (Alarm_count == 0)
    {
        score++;
        Timer();
        char j = 220;

        if (y1_police == 38)
        {
            count1++;
        }
        if (count1 == 0)
        {
            Sleep(20);
            gotoxy(x1_police, y2_police);
            cout << " ";
            gotoxy(x2_police, y1_police);
            cout << " ";
            gotoxy(x2_police, y3_police);
            cout << " ";
            gotoxy(x2_police, y2_police);
            cout << " ";
            y2_police--;
            y1_police--;
            y3_police--;
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 12);
            gotoxy(x1_police, y2_police);
            cout << j;
            HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(o, 15);
            gotoxy(x2_police, y1_police);
            cout << "<";
            gotoxy(x2_police, y3_police);
            cout << ">";
            HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(k, 9);
            gotoxy(x2_police, y2_police);
            cout << "P";
        }
        if (y1_police == 109)
        {
            count1--;
        }
        if (count1 == 1)
        {
            Sleep(20);
            gotoxy(x1_police, y2_police);
            cout << " ";
            gotoxy(x2_police, y1_police);
            cout << " ";
            gotoxy(x2_police, y3_police);
            cout << " ";
            gotoxy(x2_police, y2_police);
            cout << " ";
            y2_police++;
            y1_police++;
            y3_police++;
            HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(n, 12);
            gotoxy(x1_police, y2_police);
            cout << j;
            HANDLE p = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(p, 15);
            gotoxy(x2_police, y1_police);
            cout << "<";
            gotoxy(x2_police, y3_police);
            cout << ">";
            HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(m, 9);
            gotoxy(x2_police, y2_police);
            cout << "P";
        }

        if (x1_thief <= 35)
        {
            PoliceFirecontinues();
        }
    }
}

void SecurityMove()
{
    char j = 220;
    int x = 50, y = 72, x1 = 74, y1 = 90;

    if (police_count >= 1)
    {
        if (y1_security1 == x)
        {
            security1count++;
        }
        if (security1count == 0)
        {
            Sleep(20);
            gotoxy(x1_security1, y1_security1);
            cout << " ";
            gotoxy(x2_security1, y1_security1);
            cout << " ";
            cout << " ";
            y1_security1--;
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 12);
            gotoxy(x1_security1, y1_security1);
            cout << j;
            HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(k, 9);
            gotoxy(x2_security1, y1_security1);
            cout << "P";
        }
        if (y1_security1 == y)
        {
            security1count--;
        }
        if (security1count == 1)
        {
            Sleep(20);
            gotoxy(x1_security1, y1_security1);
            cout << " ";
            gotoxy(x2_security1, y1_security1);
            cout << " ";
            cout << " ";
            y1_security1++;
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 12);
            gotoxy(x1_security1, y1_security1);
            cout << j;
            HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(k, 9);
            gotoxy(x2_security1, y1_security1);
            cout << "P";
        }
    }
    if (police_count1 >= 1)
    {
        if (y1_security2 == x1)
        {
            security2count++;
        }
        if (security2count == 0)
        {
            Sleep(20);
            gotoxy(x1_security2, y1_security2);
            cout << " ";
            gotoxy(x2_security2, y1_security2);
            cout << " ";
            cout << " ";
            y1_security2--;
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 12);
            gotoxy(x1_security2, y1_security2);
            cout << j;
            HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(k, 9);
            gotoxy(x2_security2, y1_security2);
            cout << "P";
        }
        score++;
        Timer();
        if (y1_security2 == y1)
        {
            security2count--;
        }
        if (security2count == 1)
        {
            Sleep(20);
            gotoxy(x1_security2, y1_security2);
            cout << " ";
            gotoxy(x2_security2, y1_security2);
            cout << " ";
            cout << " ";
            y1_security2++;
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 12);
            gotoxy(x1_security2, y1_security2);
            cout << j;
            HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(k, 9);
            gotoxy(x2_security2, y1_security2);
            cout << "P";
        }
    }
    if (Alarm_count1 == 0)
    {
        gotoxy(x1_Security1Fire, y1_Security1Fire);
        cout << " ";
        gotoxy(x1_Security2Fire, y1_Security2Fire);
        cout << " ";
        SecurityFire();
        gotoxy(x1_Security1Fire, y1_Security1Fire);
        cout << " ";
        gotoxy(x1_Security2Fire, y1_Security2Fire);
        cout << " ";
    }
}

void SecurityFire()
{
    score++;
    Timer();
    while (true)
    {
        char i = 31, c = 254;
        gotoxy(x1_Security1Fire, y1_Security1Fire);
        cout << " ";
        gotoxy(x1_Security1Fire + 1, y1_Security1Fire);
        cout << i;
        x1_Security1Fire++;
        if (x1_Security1Fire + 1 == 35)
        {
            gotoxy(x1_Security1Fire, y1_Security1Fire);
            cout << " ";
            x1_Security1Fire = x2_security1 + 1;
            y1_Security1Fire = y1_security1;
            break;
        }
        if ((x1_thief - 1 == x1_Security1Fire && y2_thief == y1_Security1Fire))
        {

            energy = energy - 1;
            Gameinfo();
            gotoxy(x1_Security1Fire - 1, y1_Security1Fire);
            cout << " ";
            gotoxy(x1_thief - 1, y2_thief);
            cout << " ";
            gotoxy(x1_thief - 1, y2_thief + 1);
            cout << " ";
            // When Bullet Hit the Space ship Then this Show You that Bullet Hit Thief
            Erase();
            break;
        }

        gotoxy(x1_Security2Fire, y1_Security2Fire);
        cout << " ";
        gotoxy(x1_Security2Fire + 1, y1_Security2Fire);
        cout << i;
        x1_Security2Fire++;
        if (x1_Security2Fire + 1 == 35)
        {
            gotoxy(x1_Security2Fire, y1_Security2Fire);
            cout << " ";
            x1_Security2Fire = x2_security2 + 1;
            y1_Security2Fire = y1_security2;
            break;
        }
        if ((x1_thief - 1 == x1_Security2Fire && y2_thief == y1_Security2Fire))
        {

            energy = energy - 1;
            Gameinfo();
            gotoxy(x1_Security2Fire - 1, y1_Security2Fire);
            cout << " ";
            gotoxy(x1_thief - 1, y2_thief);
            cout << " ";
            gotoxy(x1_thief - 1, y2_thief + 1);
            cout << " ";
            // When Bullet Hit the Space ship Then this Show You that Bullet Hit Thief
            Erase();
            break;
        }
        if (Alarm_count1 == 0)
        {
            gotoxy(x1_Security1Fire, y1_Security1Fire);
            cout << " ";
            gotoxy(x1_Security2Fire, y1_Security2Fire);
            cout << " ";
        }
    }
}
void PoliceFirecontinues()
{
    score++;
    Timer();
    while (true)
    {
        char i = 31;
        gotoxy(x_Fire, y_Fire);
        cout << " ";
        gotoxy(x_Fire + 1, y_Fire);
        cout << i;
        x_Fire++;
        if (x_Fire + 1 == 35)
        {
            gotoxy(x_Fire, y_Fire);
            cout << " ";
            x_Fire = x2_police + 1;
            y_Fire = y2_police;
            break;
        }
        if ((x1_thief - 1 == x_Fire && y2_thief == y_Fire) || (x2_thief - 2 == x_Fire && y1_thief == y_Fire) || (x2_thief - 2 == x_Fire && y3_thief == y_Fire) || (x2_thief - 2 == x_Fire && y1_thief - 1 == y_Fire) || (x2_thief - 2 == x_Fire && y3_thief + 1 == y_Fire))
        {

            energy = energy - 1;
            Gameinfo();
            gotoxy(x_Fire - 1, y_Fire);
            cout << " ";
            gotoxy(x1_thief - 1, y2_thief);
            cout << " ";
            gotoxy(x1_thief - 1, y2_thief + 1);
            cout << " ";
            // When Bullet Hit the Space ship Then this Show You that Bullet Hit Thief
            Erase();
            break;
        }
    }
}

void Erase()
{
    if (Level == 1)
    {
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 12);
        Sleep(200);
        gotoxy(x1_thief, y2_thief);
        cout << "*";
        gotoxy(x2_thief, y1_thief);
        cout << "*";
        gotoxy(x2_thief, y3_thief);
        cout << "*";
        gotoxy(x2_thief, y2_thief);
        cout << "*";
    }
    if (Level == 3)
    {
        HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(n, 12);
        Sleep(200);
        gotoxy(x1_thief, y2_thief);
        cout << "*";
        gotoxy(x2_thief, y2_thief);
        cout << "*";
    }
}
void ThiefFire()
{
    score++;
    Timer();

    if (Thief == 0 && Alarm_count != 0)
    {

        char c = 30;
        x_TFire = x2_thief - 1;
        y_TFire = y3_thief;
        while (true)
        {
            Sleep(20);
            gotoxy(x_TFire, y_TFire);
            cout << " ";
            gotoxy(x_TFire - 1, y_TFire);
            cout << c;
            x_TFire--;
            char j = 220;
            if ((x2_police + 1 == x_TFire && y2_police == y_TFire) || (x2_police == x_TFire && y1_police == y_TFire) || (x2_police == x_TFire && y3_police == y_TFire))
            {
                gotoxy(x2_police + 1, y2_police);
                cout << " ";
                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 12);
                gotoxy(x1_police, y2_police);
                cout << j;
                HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(m, 9);
                gotoxy(x2_police, y2_police);
                cout << "P";
                HANDLE p = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(p, 15);
                gotoxy(x2_police, y1_police);
                cout << "<";
                gotoxy(x2_police, y3_police);
                cout << ">";
                gotoxy(x_TFire, y_TFire);
                cout << " ";
                HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(l, 15);
                gotoxy(x2_police, y1_police);
                cout << "<";
                police++;
                Health();
                break;
            }
            if (police >= 200)
            {
                Thief++;
                gotoxy(x1_police, y2_police);
                cout << " ";
                gotoxy(x2_police, y1_police);
                cout << " ";
                gotoxy(x2_police, y3_police);
                cout << " ";
                gotoxy(x2_police, y2_police);
                cout << " ";
                gotoxy(x2_thief - 2, y3_thief);
                cout << " ";
                break;
            }
            if (x_TFire == 11)
            {
                gotoxy(x_TFire, y_TFire);
                cout << " ";
                x_TFire = x2_thief - 1;
                y_TFire = y3_thief;
                break;
            }
        }
    }
}

void Thief3Fire()
{
    score++;
    Timer();
    if (FireCount == 1 && (police_count1 >= 0 || police_count > 0))
    {

        char c = 30;
        x_TFire = x1_thief - 1;
        y_TFire = y2_thief;
        while (true)
        {
            score++;
            Timer();
            Sleep(20);
            gotoxy(x_TFire, y_TFire);
            cout << " ";
            gotoxy(x_TFire - 1, y_TFire);
            cout << c;
            x_TFire--;
            char j = 220;
            if (x2_security1 + 1 == x_TFire && y1_security1 == y_TFire)
            {
                gotoxy(x2_security1 + 1, y1_security1);
                cout << " ";
                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 12);
                gotoxy(x1_security1, y1_security1);
                cout << j;
                HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(m, 9);
                gotoxy(x2_security1, y1_security1);
                cout << "P";
                gotoxy(x_TFire, y_TFire);
                cout << " ";
                police_count--;
                Health_3();
                break;
            }
            if (x2_security2 + 1 == x_TFire && y1_security2 == y_TFire)
            {
                gotoxy(x2_security2 + 1, y1_security2);
                cout << " ";
                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 12);
                gotoxy(x1_security2, y1_security2);
                cout << j;
                HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(m, 9);
                gotoxy(x2_security2, y1_security2);
                cout << "P";
                gotoxy(x_TFire, y_TFire);
                cout << " ";
                police_count1--;
                Health_3();
                break;
            }
            if (police_count == 1)
            {
                police_count--;
                Pcount++;
                gotoxy(x1_security1, y1_security1);
                cout << " ";
                gotoxy(x2_security1, y1_security1);
                cout << " ";
                gotoxy(x2_thief - 2, y1_thief);
                cout << " ";
                break;
            }
            if (police_count1 == 1)
            {
                police_count1--;
                Pcount++;
                gotoxy(x1_security2, y1_security2);
                cout << " ";
                gotoxy(x2_security2, y1_security2);
                cout << " ";
                gotoxy(x2_thief - 2, y1_thief);
                cout << " ";
                break;
            }
            if (x_TFire == 12)
            {
                gotoxy(x_TFire, y_TFire);
                cout << " ";
                x_TFire = x1_thief - 1;
                y_TFire = y2_thief;
                break;
            }
        }
    }
}
void GameStartWindow()
{
    DisplayBox();
    HANDLE J = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(J, 12);
    DrawRoom(16, 88, 67, 27);
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 15);
    gotoxy(18, 73);
    cout << "1-PLAY GAME";
    gotoxy(20, 73);
    cout << "2-BEST TIME";
    gotoxy(22, 73);
    cout << "3-CONTROLS";
    gotoxy(24, 73);
    cout << "4-INSTRUCTIONS";
    gotoxy(26, 73);
    cout << "5-QUITE";
}

void StartWindow()
{
    HANDLE J = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(J, 12);
    char x = 128, y = 233, z = 237;
    gotoxy(12, 66);
    Sleep(300);
    cout << "M";
    Sleep(300);
    cout << x;
    Sleep(300);
    cout << "S";
    Sleep(300);
    cout << "T";
    Sleep(300);
    cout << y;
    Sleep(300);
    cout << "R    ";
    Sleep(300);
    cout << "T";
    Sleep(300);
    cout << "H";
    Sleep(300);
    cout << z;
    Sleep(300);
    cout << y;
    Sleep(300);
    cout << "F   ";
    Sleep(300);
    cout << "M";
    Sleep(300);
    cout << "Y";
    Sleep(300);
    cout << "S";
    Sleep(300);
    cout << "T";
    Sleep(300);
    cout << y;
    Sleep(300);
    cout << "R";
    Sleep(300);
    cout << "Y";
    gotoxy(14, 62);
    HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(n, 9);
    Sleep(500);
    cout << "Developed By Muhammad Danish - 2021";
    gotoxy(16, 57);
    HANDLE v = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(v, 10);
    Sleep(2000);
    cout << "Your Mission is to Steal Diamond and then Steal";
    gotoxy(17, 57);
    Sleep(2000);
    cout << "Computer Hacking Device From Army Base and then";
    gotoxy(18, 57);
    Sleep(2000);
    cout << "Steal Door Security Code To come Out From Army Base";
    gotoxy(19, 57);
    Sleep(2000);
    cout << "But This Very difficult because in 1-Level You Face";
    gotoxy(20, 57);
    Sleep(2000);
    cout << "Computer Security Machine is Active and start Fire ";
    gotoxy(21, 57);
    Sleep(2000);
    cout << "When You Enter in Base and then in 2_Level there is";
    gotoxy(22, 57);
    Sleep(2000);
    cout << "Computerized Tiles active and then in 3-Level there is";
    gotoxy(23, 57);
    Sleep(2000);
    cout << "Computer Robot that fire you to take you away from the";
    gotoxy(24, 57);
    Sleep(2000);
    cout << "Security Code";
    gotoxy(26, 60);
    Sleep(2000);
    cout << "             BEST OF LUCK";
}

void CONTROLS()
{
    char c = 254;
    DisplayBox();
    HANDLE J = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(J, 15);
    DrawRoom(16, 82, 71, 18);
    HANDLE i = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(i, 12);
    gotoxy(17, 73);
    cout << "CONTROLS";
    HANDLE b = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(b, 9);
    gotoxy(21, 62);
    cout << c << " LEFT ARROW KEY FOR LEFT MOVE";
    gotoxy(22, 62);
    cout << c << " RIGHT ARROW KEY FOR RIGHT MOVE";
    gotoxy(23, 62);
    cout << c << " UP ARROW KEY FOR UPWARD MOVE";
    gotoxy(24, 62);
    cout << c << " DOWN ARROW KEY FOR DOWN MOVE";
    gotoxy(25, 62);
    cout << c << " PRESS SPACE KEY FOR FIRE BULLET";
}

void DisplayBox()
{
    char x = 128, y = 233, z = 237;
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 12);
    DrawRoom(10, 103, 53, 30);
    HANDLE N = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(N, 15);
    DrawRoom(11, 102, 54, 14);
    HANDLE K = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(K, 12);
    gotoxy(12, 66);
    cout << " M" << x << "ST" << y << "R    TH" << z << y << "F    MYST" << y << "RY";
}
void Instructions()
{
    char c = 254;
    DisplayBox();
    HANDLE J = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(J, 15);
    DrawRoom(16, 85, 69, 18);
    HANDLE i = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(i, 12);
    gotoxy(17, 72);
    cout << "INSTRUCTIONS";
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(o, 9);
    gotoxy(21, 62);
    cout << c << " LEVEL 1- AWAY FROM SECURITY FIRE";
    gotoxy(22, 62);
    cout << c << " LEVEL 2- AWAY FROM WRONG TILES";
    gotoxy(23, 62);
    cout << c << " LEVEL 3- AWAY FROM ARMY SHOOTERS";
}

void BestTIME()
{
    char c = 254;
    DisplayBox();
    HANDLE J = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(J, 15);
    DrawRoom(16, 81, 69, 18);
    HANDLE i = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(i, 12);
    gotoxy(17, 71);
    cout << "BEST TIME";
    int Time = BestTime();
    gotoxy(21, 71);
    cout << c << " " << Time << " : " << bestS;
}