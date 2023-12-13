#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
int p_id;
bool Is_AI;
string p_name;
int p_tmp_num = 0;              //當前動作得到的牌號
int p_tmp_pos;                  //當前玩家出牌/補牌的位子
int p_point = 0;                //玩家累積分數
int p_card_hand[5];             //玩家在手上的五張牌
Player *left, *right;
int p_x, p_y;
int p_text_x, p_text_y;
static int n;

static int pos_x, pos_y;

public:
        Player(int, string, bool = 0);


        int p_get_point(){return p_point;}
        int p_draw_card();        //抽一張牌並補進手牌
        int p_play_card();      //打出一張牌
        int AI_play_card();
        static int p_round();          //一輪
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
