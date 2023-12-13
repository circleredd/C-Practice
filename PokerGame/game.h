#ifndef GAME_H
#define GAME_H
#include"player.h"

class Game{
        static int game_score;
        static int card_score[52];
        static bool card_flag[52];

        static string card_face[13];
        static string card_suit[4];
        static Player *one, *two , *three, *four;
        static Player *AI_1;


        friend class Player;
public:
        Game();
        void Set_Score(int);
        int Get_Score();
        static void Set_Ptr(Player*, Player*);
        static void Set_Ptr(Player*, Player*, Player*);
        static void Set_Ptr(Player*, Player*, Player*, Player*);
        static void Init_flag();
        static void card_deal();
        static Player* get_ptr(int);
        static void Print_Draw_Card(Player*);
        static void Print_Five_Card(int);
        static void Print_Play_Card(int, int);
        static void Print_GameOver(Player*);
        static void Show_UI();
        static void Show_Game_Score();

        static void Gotoxy(int,int);
        static void SetColor(int);


};



#endif // GAME_H
