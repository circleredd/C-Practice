#include"Sokoban.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<conio.h>
#include<windows.h>

using namespace std;

Sokoban::Sokoban()
{
        Is_Complete = false;
}

/*
void Sokoban::Set_Row_Col(int r, int c)
{
        row = r;
        col = c;
}
*/

void Sokoban::Set_Map(string name)
{
        Is_Complete = false;
        Gotoxy(0,0);
        fstream A;
        A.open(name, ios::in);

        if(!A.is_open()){
                cerr << "File is not opened!" << endl;
                exit(1);
        }

        A >> row;
        A >> col;
        char tmp;
        map_1.resize(row, vector<char>(col));
        for(int i=0; i<map_1.size(); i++){
                for(int j=0; j<map_1[i].size(); j++){
                        A >> tmp;
                        if(tmp == '0'){
                                x = i;
                                y = j;
                        }
                        else if(tmp == '2'){
                                des_x = i;
                                des_y = j;
                        }
                        map_1[i][j] = tmp;
                        cout << map_1[i][j];
                }
                cout << endl;
        }
}



int Sokoban::Move_Rule(int dir)
{
        /*
        0: Do nothing
        1: Move player
        2: Move player & Push the box
        3: Move player to the destination
        4: Leave player from destinaion
        */
        switch(dir){
        case 1:
                if(map_1[x-1][y] == '/')
                        return 0;
                else if(map_1[x-1][y] == '1')
                        return 2;
                else if(map_1[x-1][y] == '2')
                        return 3;
                else if(x == des_x && y == des_y)
                        return 4;
                else
                        return 1;
                break;
        case 2:
                if(map_1[x+1][y] == '/')
                        return 0;
                else if(map_1[x+1][y] == '1')
                        return 2;
                else if(map_1[x+1][y] == '2')
                        return 3;
                else if(x == des_x && y == des_y)
                        return 4;
                else
                        return 1;
                break;
        case 3:
                if(map_1[x][y-1] == '/')
                        return 0;
                else if(map_1[x][y-1] == '1')
                        return 2;
                else if(map_1[x][y-1] == '2')
                        return 3;
                else if(x == des_x && y == des_y)
                        return 4;
                else
                        return 1;
                break;
        case 4:
                if(map_1[x][y+1] == '/')
                        return 0;
                else if(map_1[x][y+1] == '1')
                        return 2;
                else if(map_1[x][y+1] == '2')
                        return 3;
                else if(x == des_x && y == des_y)
                        return 4;
                else
                        return 1;
                break;

        }
}

void Sokoban::Move()
{
        int ascii_1, ascii_2;
        while(true){
                ascii_1 = getch();
                if(ascii_1 == 224){
                        switch(ascii_2 = getch()){
                        case 72:
                                if(Move_Rule(1) == 1){
                                        swap(map_1[x][y], map_1[x-1][y]);
                                        x--;
                                }
                                else if(Move_Rule(1) == 2){
                                        if(map_1[x-2][y] == '/')
                                                break;
                                        else if(map_1[x-2][y] == '2'){
                                                map_1[x-2][y] = '-';
                                                swap(map_1[x-1][y], map_1[x-2][y]);
                                                swap(map_1[x][y], map_1[x-1][y]);
                                                x--;
                                                Is_Complete = true;
                                        }
                                        else{
                                                swap(map_1[x-1][y], map_1[x-2][y]);
                                                swap(map_1[x][y], map_1[x-1][y]);
                                                x--;
                                        }
                                }
                                else if(Move_Rule(1) == 3){
                                        swap(map_1[x][y], map_1[x-1][y]);
                                        map_1[x][y] = '-';
                                        x--;
                                }
                                else if(Move_Rule(1) == 4){
                                        swap(map_1[x][y], map_1[x-1][y]);
                                        map_1[x][y] = '2';
                                        x--;
                                }
                                break;
                        case 80:
                                if(Move_Rule(2) == 1){
                                        swap(map_1[x][y], map_1[x+1][y]);
                                        x++;
                                }
                                else if(Move_Rule(2) == 2){
                                        if(map_1[x+2][y] == '/')
                                                break;
                                        else if(map_1[x+2][y] == '2'){
                                                map_1[x+2][y] = '-';
                                                swap(map_1[x+1][y], map_1[x+2][y]);
                                                swap(map_1[x][y], map_1[x+1][y]);
                                                x--;
                                                Is_Complete = true;
                                        }
                                        else{
                                                swap(map_1[x+1][y], map_1[x+2][y]);
                                                swap(map_1[x][y], map_1[x+1][y]);
                                                x++;
                                        }
                                }
                                else if(Move_Rule(2) == 3){
                                        swap(map_1[x][y], map_1[x+1][y]);
                                        map_1[x][y] = '-';
                                        x++;
                                }
                                else if(Move_Rule(2) == 4){
                                        swap(map_1[x][y], map_1[x+1][y]);
                                        map_1[x][y] = '2';
                                        x++;
                                }
                                break;
                        case 75:
                                if(Move_Rule(3) == 1){
                                        swap(map_1[x][y], map_1[x][y-1]);
                                        y--;
                                }
                                else if(Move_Rule(3) == 2){
                                        if(map_1[x][y-2] == '/')
                                                break;
                                        else if(map_1[x][y-2] == '2'){
                                                map_1[x][y-2] = '-';
                                                swap(map_1[x][y-1], map_1[x][y-2]);
                                                swap(map_1[x][y], map_1[x][y-1]);
                                                x--;
                                                Is_Complete = true;
                                        }
                                        else{
                                                swap(map_1[x][y-1], map_1[x][y-2]);
                                                swap(map_1[x][y], map_1[x][y-1]);
                                                y--;
                                        }
                                }
                                else if(Move_Rule(3) == 3){
                                        swap(map_1[x][y], map_1[x][y-1]);
                                        map_1[x][y] = '-';
                                        y--;
                                }
                                else if(Move_Rule(3) == 4){
                                        swap(map_1[x][y], map_1[x][y-1]);
                                        map_1[x][y] = '2';
                                        y--;
                                }
                                break;
                        case 77:
                                if(Move_Rule(4) == 1){
                                        swap(map_1[x][y], map_1[x][y+1]);
                                        y++;
                                }
                                else if(Move_Rule(4) == 2){
                                        if(map_1[x][y+2] == '/')
                                                break;
                                        else if(map_1[x][y+2] == '2'){
                                                map_1[x][y+2] = '-';
                                                swap(map_1[x][y+1], map_1[x][y+2]);
                                                swap(map_1[x][y], map_1[x][y+1]);
                                                x--;
                                                Is_Complete = true;
                                        }
                                        else{
                                                swap(map_1[x][y+1], map_1[x][y+2]);
                                                swap(map_1[x][y], map_1[x][y+1]);
                                                y++;
                                        }
                                }
                                else if(Move_Rule(4) == 3){
                                        swap(map_1[x][y], map_1[x][y+1]);
                                        map_1[x][y] = '-';
                                        y++;
                                }
                                else if(Move_Rule(4) == 4){
                                        swap(map_1[x][y], map_1[x][y+1]);
                                        map_1[x][y] = '2';
                                        y++;
                                }
                                break;
                        }
                }
                else
                        break;
                Show();
                if(Is_Complete){
                        Clear();
                        Gotoxy(0,0);
                        cout << "Congratulations !" << endl;
                        cout << "請按任意鍵";
                        if(getch())
                                break;
                }
        }
        Gotoxy(0,0);
        SetColor(1);
        cout << "                          " << endl << "                      ";
        SetColor(7);
}



void Sokoban::Show()
{
        Gotoxy(0,0);
        for(int i=0; i<map_1.size(); i++){
                for(int j=0; j<map_1[i].size(); j++){
                        cout << map_1[i][j];
                }
                cout << endl;
        }
}

void Sokoban::Clear()
{
        Gotoxy(0,0);
        SetColor(1);
        for(int i=0; i<map_1.size(); i++){
                for(int j=0; j<map_1[i].size(); j++){
                        cout << " ";
                }
                cout << endl;
        }
        SetColor(7);
}

void Sokoban::Show_Instruct()
{
        Gotoxy(0, 25);
        cout << "使用方向鍵操控遊戲角色 / 按任意鍵退出遊戲";
        Gotoxy(0,0);

}

void Sokoban::Clear_Instruct()
{
        Gotoxy(0, 25);
        SetColor(1);
        cout << "                                                                ";
        SetColor(7);
        Gotoxy(0,0);
}


void Sokoban::Gotoxy(int x, int y)
{
        COORD position;
        position.X = x;
        position.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Sokoban::SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}





