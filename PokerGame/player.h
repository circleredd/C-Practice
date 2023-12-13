#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
int p_id;
bool Is_AI;
string p_name;
int p_tmp_num = 0;              //��e�ʧ@�o�쪺�P��
int p_tmp_pos;                  //��e���a�X�P/�ɵP����l
int p_point = 0;                //���a�ֿn����
int p_card_hand[5];             //���a�b��W�����i�P
Player *left, *right;
int p_x, p_y;
int p_text_x, p_text_y;
static int n;

static int pos_x, pos_y;

public:
        Player(int, string, bool = 0);


        int p_get_point(){return p_point;}
        int p_draw_card();        //��@�i�P�øɶi��P
        int p_play_card();      //���X�@�i�P
        int AI_play_card();
        static int p_round();          //�@��
        int get_tmp_num();
        void p_set_card_hand(int,int);
        int p_get_card_hand(int);
        static void p_order();
        int get_id(){return p_id;}
        string get_name(){return p_name;}

        void p_set_ptr(Player*, Player*);
        static void p_set_circular();
        int get_point(){return p_point;}

        static void Gotoxy(int,int);
        static void SetColor(int);
        friend class Game;


};



#endif // PLAYER_H
