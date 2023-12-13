#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include"game.h"
#include"player.h"

using namespace std;

Player::Player(int num, string name, bool AI)
{
        n = num;
        p_name = name;
        Is_AI = AI;
        while(true){
                p_tmp_num = rand()%52;
                if(Game::card_flag[p_tmp_num]){
                        Game::card_flag[p_tmp_num] = 0;
                        break;
                }
        }

}
int Player::n = 0;
int Player::pos_x = 0;
int Player::pos_y = 0;

void Player::Gotoxy(int x, int y)
{
        COORD position;
        position.X = x;
        position.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Player::SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

int Player::p_draw_card()
{
        while(true){
                p_tmp_num = rand()%52;
                if(Game::card_flag[p_tmp_num]){
                        Game::card_flag[p_tmp_num] = 0;
                        p_card_hand[p_tmp_pos] = p_tmp_num;
                        break;
                }
        }
        return p_tmp_num;
}

int Player::get_tmp_num()
{
        return p_tmp_num;
}


void Player::p_order()
{
        Player *tmp = nullptr;
        if(n == 4){
                if(Game::one->get_tmp_num() < Game::two->get_tmp_num()){
                        tmp = Game::one;
                        Game::one = Game::two;
                        Game::two = tmp;
                }
                if(Game::one->get_tmp_num() < Game::three->get_tmp_num()){
                        tmp = Game::one;
                        Game::one = Game::three;
                        Game::three = tmp;
                }
                if(Game::one->get_tmp_num() < Game::four->get_tmp_num()){
                        tmp = Game::one;
                        Game::one = Game::four;
                        Game::four = tmp;
                }
                if(Game::two->get_tmp_num() < Game::three->get_tmp_num()){
                        tmp = Game::two;
                        Game::two = Game::three;
                        Game::three = tmp;
                }
                if(Game::two->get_tmp_num() < Game::four->get_tmp_num()){
                        tmp = Game::two;
                        Game::two = Game::four;
                        Game::four = tmp;
                }
                if(Game::three->get_tmp_num() < Game::four->get_tmp_num()){
                        tmp = Game::three;
                        Game::three = Game::four;
                        Game::four = tmp;
                }
                Game::one->p_id = 1;
                Game::one->p_x = 40;
                Game::one->p_y = 4;

                Game::two->p_id = 2;
                Game::two->p_x = 40;
                Game::two->p_y = 19;

                Game::three->p_id = 3;
                Game::three->p_x = 40;
                Game::three->p_y = 34;

                Game::four->p_id = 4;
                Game::four->p_x = 40;
                Game::four->p_y = 49;

        }
        if(n == 3){
                if(Game::one->get_tmp_num() < Game::two->get_tmp_num()){
                        tmp = Game::one;
                        Game::one = Game::two;
                        Game::two = tmp;
                }
                if(Game::one->get_tmp_num() < Game::three->get_tmp_num()){
                        tmp = Game::one;
                        Game::one = Game::three;
                        Game::three = tmp;
                }
                if(Game::two->get_tmp_num() < Game::three->get_tmp_num()){
                        tmp = Game::two;
                        Game::two = Game::three;
                        Game::three = tmp;
                }
                Game::one->p_id = 1;
                Game::two->p_id = 2;
                Game::three->p_id = 3;

                Game::one->p_id = 1;
                Game::one->p_x = 40;
                Game::one->p_y = 4;

                Game::two->p_id = 2;
                Game::two->p_x = 40;
                Game::two->p_y = 19;

                Game::three->p_id = 3;
                Game::three->p_x = 40;
                Game::three->p_y = 34;
        }
        if(n == 2){
                if(Game::one->p_tmp_num < Game::two->p_tmp_num){
                        tmp = Game::one;
                        Game::one = Game::two;
                        Game::two = tmp;
                }
                Game::one->p_id = 1;
                Game::two->p_id = 2;

                Game::one->p_id = 1;
                Game::one->p_x = 40;
                Game::one->p_y = 4;

                Game::two->p_id = 2;
                Game::two->p_x = 40;
                Game::two->p_y = 19;
        }



}


void Player::p_set_card_hand(int i,int key)
{
        p_card_hand[i] = key;

}

int Player::p_get_card_hand(int i)
{
        return p_card_hand[i];
}


int Player::p_play_card()
{
        int seq;
        Game::Gotoxy(0, p_y-1);
        while(true){
                cout << "ID:" << p_id << "  Name:" << p_name << endl;
                cout << "請輸入欲出牌之編號(1~5):";
                cin >> seq;
                if(seq >= 6 || seq <= 0)
                        continue;
                seq--;
                Game::card_flag[p_card_hand[seq]] = 1;
                p_tmp_num = p_card_hand[seq];
                p_card_hand[seq] = -1;
                p_tmp_pos = seq;
                break;
        }
        return p_tmp_num;

}

int Player::AI_play_card()
{
        int seq;
        bool flag = 1;
        if(Game::game_score <= 79){
                if(flag){
                        for(int i=0; i<5; i++){
                                if(6 <= p_card_hand[i]/4+1 <= 9){
                                         seq = i;
                                         flag = 0;
                                         break;
                                }
                        }
                }
                if(flag){
                        for(int i=0; i<5; i++){
                                if(1 <= p_card_hand[i]/4+1 <= 3){
                                         seq = i;
                                         flag = 0;
                                         break;
                                }
                        }
                }
                if(flag){
                        for(int i=0; i<5; i++){
                                if(p_card_hand[i]/4+1 == 10 || p_card_hand[i]/4+1 == 20){
                                         seq = i;
                                         flag = 0;
                                         break;
                                }
                        }
                }
                if(flag){
                        seq = rand()%5;
                        flag = 0;
                }

        }
        else if(Game::game_score > 79){
                if(flag){
                        for(int i=0; i<5; i++){
                                if(p_card_hand[i]/4+1 == 4 || p_card_hand[i]/4+1 == 5 ||
                                   p_card_hand[i]/4+1 == 11 || p_card_hand[i]/4+1 == 13){
                                         seq = i;
                                         flag = 0;
                                         break;
                                }
                        }
                }
                if(flag){
                        for(int i=0; i<5; i++){
                                if(p_card_hand[i]/4+1 == 10 || p_card_hand[i]/4+1 == 20){
                                         seq = i;
                                         flag = 0;
                                         break;
                                }
                        }
                }
                if(flag){
                        seq = rand()%5;
                        flag = 0;
                }

        }

        Game::card_flag[p_card_hand[seq]] = 1;
        p_tmp_num = p_card_hand[seq];
        p_card_hand[seq] = -1;
        p_tmp_pos = seq;


        return p_tmp_num;
}

void Player::p_set_ptr(Player *l, Player *r)
{
        left = l;
        right = r;
}

void Player::p_set_circular()
{
        if(Player::n == 4){
                Game::one->p_set_ptr(Game::four, Game::two);
                Game::two->p_set_ptr(Game::one, Game::three);
                Game::three->p_set_ptr(Game::two, Game::four);
                Game::four->p_set_ptr(Game::three, Game::one);
        }
        else if(Player::n == 3){
                Game::get_ptr(1)->p_set_ptr(Game::get_ptr(3), Game::get_ptr(2));
                Game::get_ptr(2)->p_set_ptr(Game::get_ptr(1), Game::get_ptr(3));
                Game::get_ptr(3)->p_set_ptr(Game::get_ptr(2), Game::get_ptr(1));
        }
        else if(Player::n == 2){
                Game::get_ptr(1)->p_set_ptr(Game::get_ptr(2), Game::get_ptr(2));
                Game::two->p_set_ptr(Game::one, Game::one);
        }
}


int Player::p_round()
{

        int tmp_play;
        bool none = 1;
        bool flag = 1;  //順時針
        int point = 1;  //個人得分
        bool over[n] = {0};
        Player* tmp_player = Game::one;
        while(true){
                while(flag){
                        for(int i=0; i<5; i++){                               //判斷當前玩家有沒有手牌出
                                if(tmp_player->p_card_hand[i]/4+1 != 4 &&
                                   tmp_player->p_card_hand[i]/4+1 != 5 &&
                                   tmp_player->p_card_hand[i]/4+1 != 10&&
                                   tmp_player->p_card_hand[i]/4+1 != 11&&
                                   tmp_player->p_card_hand[i]/4+1 != 12&&
                                   tmp_player->p_card_hand[i]/4+1 != 13&&
                                   tmp_player->p_card_hand[i]     != 3 &&
                                   tmp_player->p_card_hand[i]/4+1 + Game::game_score >= 100){
                                        none = 0;
                                   }
                                   else{
                                        none = 1;
                                        break;
                                   }
                        }
                        if(none == 0){
                                //Game::Print_GameOver(tmp_player);
                                over[tmp_player->p_id] = 1;
                                tmp_player->p_point = point++;
                                tmp_player->left->right = tmp_player->right;
                                tmp_player->right->left = tmp_player->left;
                                tmp_player = tmp_player->right;
                                none = 1;
                        }
                        if(tmp_player->left == tmp_player || tmp_player->right == tmp_player){ //剩下一人
                                break;
                        }
                        Game::Print_Five_Card(tmp_player->p_id); //印出當前玩家5張手牌
                        if(tmp_player->Is_AI)
                                tmp_play = tmp_player->AI_play_card();
                        else
                                tmp_play = tmp_player->p_play_card();     //出一張牌
                        tmp_player->p_draw_card();                //抽一張卡
                        Game::Print_Play_Card(tmp_player->p_id, tmp_play);      //印出當前玩家出的牌
                        if(tmp_play/4+1 == 4){
                                flag = 0;
                                tmp_player = tmp_player->left;
                                break;
                        }
                        else if(tmp_play/4+1 == 5){
                                int select;
                                if(tmp_player->Is_AI){
                                       while(true){
                                                select = rand()%n+1;
                                                if(over[select] == 0 && select != tmp_player->p_id)
                                                        break;
                                       }
                                }
                                else{
                                        while(true){
                                                Game::Gotoxy(0, tmp_player->p_y+2);
                                                SetColor(1);
                                                cout << "                         ";
                                                Game::Gotoxy(0, tmp_player->p_y+2);
                                                SetColor();
                                                cout << "請輸入指定的玩家ID:";
                                                cin >> select;
                                                if(select > 0 && select <= n && over[select] == 0 && select != tmp_player->p_id)
                                                        break;
                                        }
                                }
                                tmp_player = Game::get_ptr(select);
                                continue;
                        }
                        else if(tmp_play/4+1 == 10){
                                if(tmp_player->Is_AI){
                                       if(Game::game_score > 89)
                                                Game::game_score -= 10;
                                       else
                                                Game::game_score += 10;
                                }
                                else{
                                        if(Game::game_score < 10)
                                                Game::game_score += 10;
                                        else if(Game::game_score >89)
                                                Game::game_score -= 10;
                                        else{
                                                while(true){
                                                        char select;
                                                        Game::Gotoxy(0, tmp_player->p_y+2);
                                                        cout << "請輸入 + 或 - :";
                                                        cin >> select;
                                                        if(select == '+'){
                                                                Game::game_score += 10;
                                                                break;
                                                        }
                                                        else if(select == '-'){
                                                                Game::game_score -= 10;
                                                                break;
                                                        }
                                                }
                                        }
                                }
                        }
                        else if(tmp_play/4+1 == 11){

                        }
                        else if(tmp_play/4+1 == 12){
                                if(tmp_player->Is_AI){
                                       if(Game::game_score > 79)
                                                Game::game_score -= 20;
                                       else
                                                Game::game_score += 20;
                                }
                                else{
                                        if(Game::game_score < 20)
                                                Game::game_score += 20;
                                        else if(Game::game_score >79)
                                                Game::game_score -= 20;
                                        else{
                                                while(true){
                                                        char select;
                                                        Game::Gotoxy(0, tmp_player->p_y+2);
                                                        cout << "請輸入 + 或 - :";
                                                        cin >> select;
                                                        if(select == '+'){
                                                                Game::game_score += 20;
                                                                break;
                                                        }
                                                        else if(select == '-'){
                                                                Game::game_score -= 20;
                                                                break;
                                                        }
                                                }
                                        }
                                }
                        }
                        else if(tmp_play/4+1 == 13){
                                Game::game_score = 99;
                        }
                        else if(tmp_play == 3){
                                Game::game_score = 0;
                        }
                        else{
                                Game::game_score += tmp_play/4+1;
                        }
                        if(Game::game_score > 99){
                                over[tmp_player->p_id] = 1;
                                tmp_player->p_point = point++;
                                tmp_player->left->right = tmp_player->right;
                                tmp_player->right->left = tmp_player->left;
                                Game::game_score = 0;
                        }

                        tmp_player = tmp_player->right;           //tmp指標指向下一位
                        Game::Show_Game_Score();

                }

                while(flag == 0){
                        for(int i=0; i<5; i++){                               //判斷當前玩家有沒有手牌出
                                if(tmp_player->p_card_hand[i]/4+1 != 4 &&
                                   tmp_player->p_card_hand[i]/4+1 != 5 &&
                                   tmp_player->p_card_hand[i]/4+1 != 10&&
                                   tmp_player->p_card_hand[i]/4+1 != 11&&
                                   tmp_player->p_card_hand[i]/4+1 != 12&&
                                   tmp_player->p_card_hand[i]/4+1 != 13&&
                                   tmp_player->p_card_hand[i]     != 3 &&
                                   tmp_player->p_card_hand[i]/4+1 + Game::game_score >= 100){
                                        none = 0;
                                   }
                                   else{
                                        none = 1;
                                        break;
                                   }
                        }
                        if(none == 0){
                                //Game::Print_GameOver(tmp_player);
                                tmp_player->p_point = point++;
                                tmp_player->left->right = tmp_player->right;
                                tmp_player->right->left = tmp_player->left;
                                tmp_player = tmp_player->left;
                                none = 1;
                        }
                        if(tmp_player->left == tmp_player || tmp_player->right == tmp_player){ //剩下一人
                                break;
                        }
                        Game::Print_Five_Card(tmp_player->p_id); //印出當前玩家5張手牌
                        if(tmp_player->Is_AI)
                                tmp_play = tmp_player->AI_play_card();
                        else
                                tmp_play = tmp_player->p_play_card();     //出一張牌
                        tmp_player->p_draw_card();                //抽一張卡
                        Game::Print_Play_Card(tmp_player->p_id, tmp_play);      //印出當前玩家出的牌

                        if(tmp_play/4+1 == 4){
                                flag = 1;
                                tmp_player = tmp_player->right;
                                break;
                        }
                        else if(tmp_play/4+1 == 5){
                                int select;
                                if(tmp_player->Is_AI){
                                       while(true){
                                                select = rand()%n+1;
                                                if(over[select] == 0 && select != tmp_player->p_id)
                                                        break;
                                       }
                                }
                                else{
                                        while(true){
                                                Game::Gotoxy(0, tmp_player->p_y+2);
                                                SetColor(1);
                                                cout << "                         ";
                                                Game::Gotoxy(0, tmp_player->p_y+2);
                                                SetColor();
                                                cout << "請輸入指定的玩家ID:";
                                                cin >> select;
                                                if(select > 0 && select <= n && over[select] == 0 && select != tmp_player->p_id)
                                                        break;
                                        }
                                }
                                tmp_player = Game::get_ptr(select);
                                continue;
                        }
                        else if(tmp_play/4+1 == 10){
                                if(Game::game_score < 10)
                                        Game::game_score += 10;
                                else if(Game::game_score >89)
                                        Game::game_score -= 10;
                                else{
                                        while(true){
                                                char select;
                                                Game::Gotoxy(0, tmp_player->p_y+2);
                                                cout << "請輸入 + 或 - :";
                                                cin >> select;
                                                if(select == '+'){
                                                        Game::game_score += 10;
                                                        break;
                                                }
                                                else if(select == '-'){
                                                        Game::game_score -= 10;
                                                        break;
                                                }
                                        }
                                }
                        }
                        else if(tmp_play/4+1 == 11){

                        }
                        else if(tmp_play/4+1 == 12){
                                if(tmp_player->Is_AI){
                                       if(Game::game_score > 79)
                                                Game::game_score -= 20;
                                       else
                                                Game::game_score += 20;
                                }
                                else{
                                        if(Game::game_score < 20)
                                                Game::game_score += 20;
                                        else if(Game::game_score >79)
                                                Game::game_score -= 20;
                                        else{
                                                while(true){
                                                        char select;
                                                        Game::Gotoxy(0, tmp_player->p_y+2);
                                                        cout << "請輸入 + 或 - :";
                                                        cin >> select;
                                                        if(select == '+'){
                                                                Game::game_score += 20;
                                                                break;
                                                        }
                                                        else if(select == '-'){
                                                                Game::game_score -= 20;
                                                                break;
                                                        }
                                                }
                                        }
                                }
                        }
                        else if(tmp_play/4+1 == 13){
                                Game::game_score = 99;
                        }
                        else if(tmp_play == 3){
                                Game::game_score = 0;
                        }
                        else{
                                Game::game_score += tmp_play/4+1;
                        }
                        if(Game::game_score > 99){
                                over[tmp_player->p_id] = 1;
                                tmp_player->p_point = point++;
                                tmp_player->left->right = tmp_player->right;
                                tmp_player->right->left = tmp_player->left;
                                Game::game_score = 0;
                        }

                        tmp_player = tmp_player->left;            //tmp指標指向下一位
                        Game::Show_Game_Score();
                }
                Game::Show_Game_Score();
                if(tmp_player->left == tmp_player || tmp_player->right == tmp_player){
                                tmp_player->p_point = point;
                                //Game::Show_Game_Score();
                                break;
                }

        }
        Game::Show_Game_Score();
}





