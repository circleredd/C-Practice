#include<iostream>
#include<fstream>
#include<vector>
#include<conio.h>
#include<windows.h>
#include"Sokoban.h"
using namespace std;

int main()
{
        Sokoban A, B, C;
        int mission;
        while(true){
                A.Gotoxy(0,0);
                cout << "請輸入欲遊玩的關卡(選擇關卡:1~3/退出遊戲:0):" << endl;
                cin >> mission;
                if(mission < 0 || mission > 3)
                        continue;
                A.Show_Instruct();
                A.Gotoxy(0,0);
                A.SetColor(1);
                cout << "                                                             " << endl << "                        ";
                A.SetColor(7);
                if(mission == 1){
                        A.Set_Map("Mission1.txt");
                        A.Show();
                        A.Move();
                        A.Clear();
                        A.Clear_Instruct();
                }
                else if(mission == 2){
                        B.Set_Map("Mission2.txt");
                        B.Show();
                        B.Move();
                        B.Clear();
                        B.Clear_Instruct();
                }
                else if(mission == 3){
                        C.Set_Map("Mission3.txt");
                        C.Show();
                        C.Move();
                        C.Clear();
                        C.Clear_Instruct();
                }
                else if(mission == 0)
                        break;
        }



        return 0;
}


