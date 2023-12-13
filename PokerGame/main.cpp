#include <iostream>
#include <vector>
#include <cstdlib> /* �üƬ������ */
#include <ctime>   /* �ɶ�������� */
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
        cout << "�бN�����̤j�� !" << endl;
        int n;
        while (true)
        {
                Gotoxy(0, 1);
                SetColor(1);
                cout << "                         ";
                Gotoxy(0, 1);
                SetColor();
                cout << "�п�J���a�H��(2~4�H):";
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
        cout << "�п�J��" << n << "�쪱�a���W�r:";
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
                        cout << "��J0�H��P�M�w����";
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
                cout << "����: " << Game::get_ptr(1)->get_name() << " -> " << Game::get_ptr(2)->get_name() << " -> "
                     << Game::get_ptr(3)->get_name() << " -> " << Game::get_ptr(4)->get_name() << endl;
                while (true)
                {
                        int n = 1;
                        cout << "��J0�H�}�l�C��";
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
                        cout << "��J0�H��P�M�w����";
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
                cout << "����: " << Game::get_ptr(1)->get_name() << " -> " << Game::get_ptr(2)->get_name() << " -> "
                     << Game::get_ptr(3)->get_name() << endl;
                while (true)
                {
                        int n = 1;
                        cout << "��J0�H�}�l�C��";
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
                        cout << "��J0�H��P�M�w����";
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
                cout << "����: " << Game::get_ptr(1)->get_name() << " -> " << Game::get_ptr(2)->get_name() << endl;
                while (true)
                {
                        int n = 1;
                        cout << "��J0�H�}�l�C��";
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
                        cout << "�O�_�n�N��" << i + 1 << "�쪱�a�]��AI?(�n�h��J1�A�_�h��J0)";
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
                cout << "��J0�H�h�X:";
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
                        cout << "�O�_�n�N��" << i + 1 << "�쪱�a�]��AI?(�n�h��J1�A�_�h��J0)";
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
                cout << "��J0�H�h�X:";
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
                        cout << "�O�_�n�N��" << i + 1 << "�쪱�a�]��AI?(�n�h��J1�A�_�h��J0)";
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
                cout << "��J0�H�h�X:";
                cin >> quit;
        }

        return 0;
}
