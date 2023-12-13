#include <iostream>
#include <vector>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include <windows.h>
#include "game.h"
#include "player.h"

using namespace std;

void Gotoxy(int x, int y)
{
        COORD position;
        position.X = x;
        position.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int color = 7)
{
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
}

int select_num()
{
        cout << "請將視窗最大化 !" << endl;
        int n;
        while (true)
        {
                Gotoxy(0, 1);
                SetColor(1);
                cout << "                         ";
                Gotoxy(0, 1);
                SetColor();
                cout << "請輸入玩家人數(2~4人):";
                cin >> n;
                if (n >= 2 && n <= 4)
                        break;
        }
        Gotoxy(0, 0);
        SetColor(1);
        cout << "                         " << endl;
        cout << "                         ";
        Gotoxy(0, 0);
        SetColor();
        return n;
}

string select_name()
{
        static int n = 1;
        string name;

        Gotoxy(0, 0);
        SetColor(1);
        cout << "                              ";
        Gotoxy(0, 0);
        SetColor();
        cout << "請輸入第" << n << "位玩家的名字:";
        cin >> name;
        n++;
        return name;
}

void Show_Draw_Card(int n, Player *p1, Player *p2, Player *p3 = nullptr, Player *p4 = nullptr)
{
        if (n == 4)
        {
                while (true)
                {
                        int n = 1;
                        cout << "輸入0以抽牌決定順序";
                        cin >> n;
                        if (n == 0)
                                break;
                }
                Gotoxy(0, 0);
                SetColor(1);
                cout << "                                    " << endl;
                cout << "                                    ";
                SetColor();
                Game::Print_Draw_Card(p1);
                Game::Print_Draw_Card(p2);
                Game::Print_Draw_Card(p3);
                Game::Print_Draw_Card(p4);
                cout << "順序: " << Game::get_ptr(1)->get_name() << " -> " << Game::get_ptr(2)->get_name() << " -> "
                     << Game::get_ptr(3)->get_name() << " -> " << Game::get_ptr(4)->get_name() << endl;
                while (true)
                {
                        int n = 1;
                        cout << "輸入0以開始遊戲";
                        cin >> n;
                        if (n == 0)
                                break;
                }
        }
        else if (n == 3)
        {
                while (true)
                {
                        int n = 1;
                        cout << "輸入0以抽牌決定順序";
                        cin >> n;
                        if (n == 0)
                                break;
                }
                Gotoxy(0, 0);
                SetColor(1);
                cout << "                                    " << endl;
                cout << "                                    ";
                SetColor();
                Game::Print_Draw_Card(p1);
                Game::Print_Draw_Card(p2);
                Game::Print_Draw_Card(p3);
                cout << "順序: " << Game::get_ptr(1)->get_name() << " -> " << Game::get_ptr(2)->get_name() << " -> "
                     << Game::get_ptr(3)->get_name() << endl;
                while (true)
                {
                        int n = 1;
                        cout << "輸入0以開始遊戲";
                        cin >> n;
                        if (n == 0)
                                break;
                }
        }
        else if (n == 2)
        {
                while (true)
                {
                        int n = 1;
                        cout << "輸入0以抽牌決定順序";
                        cin >> n;
                        if (n == 0)
                                break;
                }
                Gotoxy(0, 0);
                SetColor(1);
                cout << "                                    " << endl;
                cout << "                                    ";
                SetColor();
                Game::Print_Draw_Card(p1);
                Game::Print_Draw_Card(p2);
                cout << "順序: " << Game::get_ptr(1)->get_name() << " -> " << Game::get_ptr(2)->get_name() << endl;
                while (true)
                {
                        int n = 1;
                        cout << "輸入0以開始遊戲";
                        cin >> n;
                        if (n == 0)
                                break;
                }
        }
        Gotoxy(0, 0);
        SetColor(1);
        for (int i = 0; i < 60; i++)
        {
                cout << "                                                                            ";
        }
        SetColor();
}

int main()
{
        srand(time(NULL));
        int quit;
        int n = select_num();
        if (n == 4)
        {
                string name_1 = select_name(), name_2 = select_name(), name_3 = select_name(), name_4 = select_name();
                bool Is_AI[4] = {0};
                for (int i = 0; i < 4; i++)
                {
                        Gotoxy(0, 0);
                        SetColor();
                        cout << "是否要將第" << i + 1 << "位玩家設為AI?(要則輸入1，否則輸入0)";
                        cin >> Is_AI[i];
                        Gotoxy(0, 0);
                        SetColor(1);
                        cout << "                                                                 ";
                        Gotoxy(0, 0);
                        SetColor();
                }
                Player p1(n, name_1, Is_AI[0]), p2(n, name_2, Is_AI[1]), p3(n, name_3, Is_AI[2]), p4(n, name_4, Is_AI[3]);
                Game::Set_Ptr(&p1, &p2, &p3, &p4);
                Player::p_order();
                Show_Draw_Card(n, &p1, &p2, &p3, &p4);

                Player::p_set_circular();
                Game::Init_flag();
                Game::card_deal();

                Game::Show_Game_Score();
                Game::Show_UI();

                Player::p_round();
                Gotoxy(0, 0);
                SetColor(1);
                for (int i = 0; i < 200; i++)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                cout << "                                        ";
                        }
                }
                Gotoxy(0, 0);
                SetColor();
                cout << p1.get_name() << "'s points:" << p1.get_point() << endl
                     << p2.get_name() << "'s points:" << p2.get_point() << endl
                     << p3.get_name() << "'s points:" << p3.get_point() << endl
                     << p4.get_name() << "'s points:" << p4.get_point() << endl;
                cout << "輸入0以退出:";
                cin >> quit;
        }
        else if (n == 3)
        {
                string name_1 = select_name(), name_2 = select_name(), name_3 = select_name();
                bool Is_AI[3] = {0};
                for (int i = 0; i < 3; i++)
                {
                        Gotoxy(0, 0);
                        SetColor();
                        cout << "是否要將第" << i + 1 << "位玩家設為AI?(要則輸入1，否則輸入0)";
                        cin >> Is_AI[i];
                        Gotoxy(0, 0);
                        SetColor(1);
                        cout << "                                                                 ";
                        Gotoxy(0, 0);
                        SetColor();
                }
                Player p1(n, name_1, Is_AI[0]), p2(n, name_2, Is_AI[1]), p3(n, name_3, Is_AI[2]);
                Game::Set_Ptr(&p1, &p2, &p3);
                Player::p_order();
                Show_Draw_Card(n, &p1, &p2, &p3);

                Player::p_set_circular();
                Game::Init_flag();
                Game::card_deal();

                Game::Show_Game_Score();
                Game::Show_UI();

                Player::p_round();
                Gotoxy(0, 0);
                SetColor(1);
                for (int i = 0; i < 200; i++)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                cout << "                                        ";
                        }
                }
                Gotoxy(0, 0);
                SetColor();
                cout << p1.get_name() << "'s points:" << p1.get_point() << endl
                     << p2.get_name() << "'s points:" << p2.get_point() << endl
                     << p3.get_name() << "'s points:" << p3.get_point() << endl;
                cout << "輸入0以退出:";
                cin >> quit;
        }
        else if (n == 2)
        {
                string name_1 = select_name(), name_2 = select_name();
                bool Is_AI[2] = {0};
                for (int i = 0; i < 2; i++)
                {
                        Gotoxy(0, 0);
                        SetColor();
                        cout << "是否要將第" << i + 1 << "位玩家設為AI?(要則輸入1，否則輸入0)";
                        cin >> Is_AI[i];
                        Gotoxy(0, 0);
                        SetColor(1);
                        cout << "                                                                 ";
                        Gotoxy(0, 0);
                        SetColor();
                }
                Player p1(n, name_1, Is_AI[0]), p2(n, name_2, Is_AI[1]);
                Game::Set_Ptr(&p1, &p2);
                Player::p_order();
                Show_Draw_Card(n, &p1, &p2);

                Player::p_set_circular();
                Game::Init_flag();
                Game::card_deal();

                Game::Show_Game_Score();
                Game::Show_UI();
                Player::p_round();
                Gotoxy(0, 0);
                SetColor(1);
                for (int i = 0; i < 200; i++)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                cout << "                                        ";
                        }
                }
                Gotoxy(0, 0);
                SetColor();
                cout << p1.get_name() << "'s points:" << p1.get_point() << endl
                     << p2.get_name() << "'s points:" << p2.get_point() << endl;
                cout << "輸入0以退出:";
                cin >> quit;
        }

        return 0;
}
