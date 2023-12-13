#ifndef SOKOBAN_H
#define SOKOBAN_H
#include<iostream>
#include<vector>



class Sokoban{

int row;
int col;
int x;
int y;
int des_x, des_y;
bool Is_Complete;
//std::string file_name;
std::vector<std::vector<char>> map_1;

public:

        Sokoban();
        //void Set_Row_Col(int, int);
        void Set_Map(std::string);
        void Set_File_Name(std::string);
        void Move();
        int Move_Rule(int);
        //bool Is_Complete();
        void Show();
        void Clear();
        void Show_Instruct();
        void Clear_Instruct();

        void Gotoxy(int, int);
        void SetColor(int);

};






#endif // SOKOBAN_H
