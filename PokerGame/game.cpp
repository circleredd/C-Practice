#include<iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include"game.h"
#include"player.h"
using namespace std;

int Game::game_score = 0;

int Game::card_score[52] = {1, 2, 3, 0, 0, 6, 7, 8, 9, 10, 0, 12, 13,
                            1, 2, 3, 0, 0, 6, 7, 8, 9, 10, 0, 12, 13,
                            1, 2, 3, 0, 0, 6, 7, 8, 9, 10, 0, 12, 13,
                            0, 2, 3, 0, 0, 6, 7, 8, 9, 10, 0, 12, 13};


bool Game::card_flag[52] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

string Game::card_face[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

void Game::Gotoxy(int x, int y)
{
        COORD position;
        position.X = x;
        position.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Game::SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

Player* Game::one = nullptr;
Player* Game::two = nullptr;
Player* Game::three = nullptr;
Player* Game::four = nullptr;
Player* Game::AI_1 = nullptr;

void Game::Set_Ptr(Player *A, Player *B)
{
        one = A;
        two = B;
}

void Game::Set_Ptr(Player *A, Player *B, Player *C)
{
        one = A;
        two = B;
        three = C;
}

void Game::Set_Ptr(Player *A, Player *B, Player *C, Player *D)
{
        one = A;
        two = B;
        three = C;
        four = D;
}

void Game::Init_flag()
{
        for(int i=0; i<52; i++){
                card_flag[i] = 1;
        }
}

void Game::card_deal()
{
        int store[20], i=0, tmp;
        while(i<=20){
                tmp = rand()%52;
                if(card_flag[tmp]){
                        card_flag[tmp] = false;
                        store[i] = tmp;
                        i++;
                }
                else
                        continue;
        }
        if(Player::n == 4){
                for(int i=0; i<5; i++){
                        one->p_set_card_hand(i%5, store[i]);
                }
                for(int i=5; i<10; i++){
                        two->p_set_card_hand(i%5, store[i]);
                }
                for(int i=10; i<15; i++){
                        three->p_set_card_hand(i%5, store[i]);
                }
                for(int i=15; i<20; i++){
                        four->p_set_card_hand(i%5, store[i]);
                }

        }
        if(Player::n == 3){
                for(int i=0; i<5; i++){
                        one->p_set_card_hand(i%5, store[i]);
                }
                for(int i=5; i<10; i++){
                        two->p_set_card_hand(i%5, store[i]);
                }
                for(int i=10; i<15; i++){
                        three->p_set_card_hand(i%5, store[i]);
                }
                for(int i=15; i<20; i++){
                        card_flag[store[i]] = false;
                }

        }
        if(Player::n == 2){
                for(int i=0; i<5; i++){
                        one->p_set_card_hand(i%5, store[i]);
                }
                for(int i=5; i<10; i++){
                        two->p_set_card_hand(i%5, store[i]);
                }
                for(int i=10; i<20; i++){
                        card_flag[store[i]] = false;
                }
        }


}

Player* Game::get_ptr(int target)
{
        if(target == 1)
                return one;
        else if(target == 2)
                return two;
        else if(target == 3)
                return three;
        else if(target == 4)
                return four;
}

void Game::Print_Draw_Card(Player *p)
{
        int tmp_x = Player::pos_x, tmp_y = Player::pos_y;

        Gotoxy(tmp_x, tmp_y++);
        cout << p->p_name;
        if(p->p_tmp_num%4 == 0){

                        SetColor(240);
                        Gotoxy(tmp_x, tmp_y++);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << " 10            " << endl;
                        else
                                cout << " " << card_face[p->p_tmp_num/4] << "             " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *** ***    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ****   ****  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << " *****   ***** " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ****   ****  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      * *      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << "            " << "10" << " " << endl;
                        else
                                cout << "             " << card_face[p->p_tmp_num/4] << " " << endl;
                        SetColor();

                }
                else if(p->p_tmp_num%4 == 1){
                        Gotoxy(tmp_x, tmp_y++);
                        SetColor(252);

                        if(p->p_tmp_num/4+1 == 10)
                                cout << " " << 10 << "    *       " << endl;
                        else
                                cout << " " << card_face[p->p_tmp_num/4] << "     *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***********  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << "       *    " <<  "10" << " " << endl;
                        else
                                cout << "       *     " <<  card_face[p->p_tmp_num/4] << " " << endl;
                        SetColor();

                }
                else if(p->p_tmp_num%4 == 2){
                        Gotoxy(tmp_x, tmp_y++);
                        SetColor(252);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << " " << 10 << "            " << endl;
                        else
                                cout << " " << card_face[p->p_tmp_num/4] <<"             " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***     ***  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << " *****   ***** " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << " ************* " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***********  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << "            " << "10" << " ";
                        else
                                cout << "             " << card_face[p->p_tmp_num/4] << " ";
                        SetColor();

                }
                else if(p->p_tmp_num%4 == 3){
                        Gotoxy(tmp_x, tmp_y++);
                        SetColor(240);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << " " << 10 << "            " << endl;
                        else
                                cout << " " << card_face[p->p_tmp_num/4] << "             " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***********  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   **** ****   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     ** **     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(p->p_tmp_num/4+1 == 10)
                                cout << "     *****  " << "10" << " ";
                        else
                                cout << "     *****   " << card_face[p->p_tmp_num/4] << " ";
                        SetColor();

                }
                cout << endl;
                Player::pos_x += 20;


}

void Game::Print_Five_Card(int ID)
{
        int tmp_x = get_ptr(ID)->p_x, tmp_y = get_ptr(ID)->p_y;

        for(int i=0; i<5; i++){
                if(get_ptr(ID)->p_card_hand[i]%4 == 0){

                        SetColor(240);
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << " 10            " << endl;
                        else
                                cout << " " << card_face[get_ptr(ID)->p_card_hand[i]/4] << "             " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *** ***    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ****   ****  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << " *****   ***** " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ****   ****  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      * *      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << "            " << "10" << " " << endl;
                        else
                                cout << "             " << card_face[get_ptr(ID)->p_card_hand[i]/4] << " " << endl;
                        SetColor();
                        tmp_x += 16;
                        tmp_y = get_ptr(ID)->p_y;
                }
                else if(get_ptr(ID)->p_card_hand[i]%4 == 1){
                        Gotoxy(tmp_x, tmp_y++);
                        SetColor(252);

                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << " " << 10 << "    *       " << endl;
                        else
                                cout << " " << card_face[get_ptr(ID)->p_card_hand[i]/4] << "     *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***********  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << "       *    " <<  "10" << " " << endl;
                        else
                                cout << "       *     " <<  card_face[get_ptr(ID)->p_card_hand[i]/4] << " " << endl;
                        SetColor();
                        tmp_x += 16;
                        tmp_y = get_ptr(ID)->p_y;
                }
                else if(get_ptr(ID)->p_card_hand[i]%4 == 2){
                        Gotoxy(tmp_x, tmp_y++);
                        SetColor(252);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << " " << 10 << "            " << endl;
                        else
                                cout << " " << card_face[get_ptr(ID)->p_card_hand[i]/4] <<"             " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***     ***  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << " *****   ***** " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << " ************* " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***********  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << "            " << "10" << " ";
                        else
                                cout << "             " << card_face[get_ptr(ID)->p_card_hand[i]/4] << " ";
                        SetColor();
                        tmp_x += 16;
                        tmp_y = get_ptr(ID)->p_y;
                }
                else if(get_ptr(ID)->p_card_hand[i]%4 == 3){
                        Gotoxy(tmp_x, tmp_y++);
                        SetColor(240);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << " " << 10 << "            " << endl;
                        else
                                cout << " " << card_face[get_ptr(ID)->p_card_hand[i]/4] << "             " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "      ***      " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     *****     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "    *******    " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   *********   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "  ***********  " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "   **** ****   " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "     ** **     " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "       *       " << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << "     *****  " << "10" << " ";
                        else
                                cout << "     *****   " << card_face[get_ptr(ID)->p_card_hand[i]/4] << " ";
                        SetColor();
                        tmp_x += 16;
                        tmp_y = get_ptr(ID)->p_y;

                }
        }

}

/*
void Game::Print_Five_Card(int ID)
{
        int tmp_x = get_ptr(ID)->p_x, tmp_y = get_ptr(ID)->p_y;
        for(int i=0; i<5; i++){

                        SetColor(240);
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << "|10           |" << endl;
                        else
                                cout << "|" << card_face[get_ptr(ID)->p_card_hand[i]/4] << "            |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|     ***     |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|    *****    |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|   *** ***   |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "| ****   **** |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|*****   *****|" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "| ****   **** |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|     * *     |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|      *      |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        cout << "|     ***     |" << endl;
                        Gotoxy(tmp_x, tmp_y++);
                        if(get_ptr(ID)->p_card_hand[i]/4+1 == 10)
                                cout << "|           " << "10" << "|" << endl;
                        else
                                cout << "|            " << card_face[get_ptr(ID)->p_card_hand[i]/4] << "|" << endl;
                        SetColor();
                        tmp_x += 16;
                        tmp_y = get_ptr(ID)->p_y;
                }

}
*/
void Game::Print_Play_Card(int ID, int tmp_play)
{
        int tmp_x = get_ptr(ID)->p_x, tmp_y = get_ptr(ID)->p_y;
        Gotoxy(tmp_x, tmp_y++);
        SetColor(1);
        for(int i=0; i<11; i++){
                for(int j=0; j<14; j++)
                        cout << "                ";
                Gotoxy(tmp_x, tmp_y++);
        }
        SetColor();
        tmp_x = get_ptr(ID)->p_x;
        tmp_y = get_ptr(ID)->p_y;
        if(tmp_play%4 == 0){

                SetColor(240);
                Gotoxy(tmp_x, tmp_y++);
                if(tmp_play/4+1 == 10)
                        cout << " 10            " << endl;
                else
                        cout << " " << card_face[tmp_play/4] << "             " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      ***      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "     *****     " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "    *** ***    " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "  ****   ****  " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << " *****   ***** " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "  ****   ****  " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      * *      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "       *       " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      ***      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                if(tmp_play/4+1 == 10)
                        cout << "            " << "10" << " " << endl;
                else
                        cout << "             " << card_face[tmp_play/4] << " " << endl;
                SetColor();
                tmp_x += 16;
                tmp_y = get_ptr(ID)->p_y;
        }
        else if(tmp_play%4 == 1){
                Gotoxy(tmp_x, tmp_y++);
                SetColor(252);

                if(tmp_play/4+1 == 10)
                        cout << " " << 10 << "    *       " << endl;
                else
                        cout << " " << card_face[tmp_play/4] << "     *       " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      ***      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "     *****     " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "    *******    " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "   *********   " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "  ***********  " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "   *********   " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "    *******    " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "     *****     " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      ***      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                if(tmp_play/4+1 == 10)
                        cout << "       *    " <<  "10" << " " << endl;
                else
                        cout << "       *     " <<  card_face[tmp_play/4] << " " << endl;
                SetColor();
                tmp_x += 16;
                tmp_y = get_ptr(ID)->p_y;
        }
        else if(tmp_play%4 == 2){
                Gotoxy(tmp_x, tmp_y++);
                SetColor(252);
                if(tmp_play/4+1 == 10)
                        cout << " " << 10 << "            " << endl;
                else
                        cout << " " << card_face[tmp_play/4] <<"             " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "  ***     ***  " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << " *****   ***** " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << " ************* " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "  ***********  " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "   *********   " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "    *******    " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "     *****     " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      ***      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "       *       " << endl;
                Gotoxy(tmp_x, tmp_y++);
                if(tmp_play/4+1 == 10)
                        cout << "            " << "10" << " ";
                else
                        cout << "             " << card_face[tmp_play/4] << " ";
                SetColor();
                tmp_x += 16;
                tmp_y = get_ptr(ID)->p_y;
        }
        else if(tmp_play%4 == 3){
                Gotoxy(tmp_x, tmp_y++);
                SetColor(240);
                if(tmp_play/4+1 == 10)
                        cout << " " << 10 << "            " << endl;
                else
                        cout << " " << card_face[tmp_play/4] << "             " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "       *       " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "      ***      " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "     *****     " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "    *******    " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "   *********   " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "  ***********  " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "   **** ****   " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "     ** **     " << endl;
                Gotoxy(tmp_x, tmp_y++);
                cout << "       *       " << endl;
                Gotoxy(tmp_x, tmp_y++);
                if(tmp_play/4+1 == 10)
                        cout << "     *****  " << "10" << " ";
                else
                        cout << "     *****   " << card_face[tmp_play/4] << " ";
                SetColor();
                tmp_x += 16;
                tmp_y = get_ptr(ID)->p_y;

        }

}

void Game::Print_GameOver(Player *tmp_player)
{
        int tmp_x = 0; //tmp_player->p_x;
        int tmp_y = 4; //tmp_player->p_y;
        Gotoxy(tmp_x, tmp_y);
        SetColor();
        cout << "Game over!";


}


void Game::Show_Game_Score()
{
        Gotoxy(0,0);
        SetColor(1);
        cout << "                                    ";
        Gotoxy(0,0);
        SetColor();
        cout << "Score:" << game_score;
        if(Player::n == 4){
                Gotoxy(25, 0);
                cout << "1 " << one->p_name << "'s points:" << one->p_point;
                Gotoxy(50, 0);
                cout << "2 " << two->p_name << "'s points:" << two->p_point;
                Gotoxy(75, 0);
                cout << "3 " << three->p_name << "'s points:" << three->p_point;
                Gotoxy(100, 0);
                cout << "4 " << four->p_name << "'s points:" << four->p_point;
        }
        else if(Player::n == 3){
                Gotoxy(25, 0);
                cout << "1 " << one->p_name << "'s points:" << one->p_point;
                Gotoxy(50, 0);
                cout << "2 " << two->p_name << "'s points:" << two->p_point;
                Gotoxy(75, 0);
                cout << "3 " << three->p_name << "'s points:" << three->p_point;
        }
        else if(Player::n == 2){
                Gotoxy(25, 0);
                cout << "1 " << one->p_name << "'s points:" << one->p_point;
                Gotoxy(50, 0);
                cout << "2 " << two->p_name << "'s points:" << two->p_point;
        }
}

void Game::Show_UI()
{
        if(Player::n == 4){
                Gotoxy(0, 1);
                cout << "----------------------------------------------------------------------------------------------------------------------";
                Gotoxy(0, 16);
                cout << "----------------------------------------------------------------------------------------------------------------------";
                Gotoxy(0, 31);
                cout << "----------------------------------------------------------------------------------------------------------------------";
                Gotoxy(0, 46);
                cout << "----------------------------------------------------------------------------------------------------------------------";

        }
        else if(Player::n == 3){
                Gotoxy(0, 1);
                cout << "----------------------------------------------------------------------------------------------------------------------";
                Gotoxy(0, 16);
                cout << "----------------------------------------------------------------------------------------------------------------------";
                Gotoxy(0, 31);
                cout << "----------------------------------------------------------------------------------------------------------------------";

        }
        else if(Player::n == 2){
                Gotoxy(0, 1);
                cout << "----------------------------------------------------------------------------------------------------------------------";
                Gotoxy(0, 16);
                cout << "----------------------------------------------------------------------------------------------------------------------";
        }
}



