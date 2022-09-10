#include <Windows.h>

#include <conio.h>  
#include <iostream>
#include<ostream>
using namespace std;
string tab[3][3] = { " "," "," "," "," "," "," "," "," " };
char player = 'X';

void Gotoposition(int x, int y) {
    HANDLE  h =  GetStdHandle(STD_OUTPUT_HANDLE);
    int x_position = x, y_position = y;
    COORD screen;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    screen.X = x_position;
    screen.Y = y_position;
    SetConsoleCursorPosition(hOutput, screen);

}
void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 

void Drawtab() {




   cout << "                 |----|----|----|" << endl
        << "                 |    |    |    |" << endl
        << "                 |----|----|----|" << endl
        << "                 |    |    |    |" << endl
        << "                 |----|----|----|" << endl
        << "                 |    |    |    |" << endl
        << "                 |----|----|----|" << endl;
}
void Drawmati() {



    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            gotoxy(19, 1);
        }
        else if (i == 1)
            gotoxy(19, 3);

        else {
            gotoxy(19, 5);
        }

        for (int j = 0; j < 3; j++) {
            cout << tab[i][j] << "    ";
        }


        cout << "             " << endl;
        cout << endl;
    }

}

void Play() {
     int b;
     int cou = 0;
    
    cout << "donner le nemuero de case: " <<player<< endl;
    cin >> b;
    if (b == 1) {
        if (tab[0][0] != "X" && tab[0][0] != "O")
            tab[0][0] = player;
        else cin >> b;
    }
    else if (b == 2) {
        if (tab[0][1] != "X" && tab[0][1] != "O")
            tab[0][1] = player;
        else cou = 1;
    }
    else if (b == 3) {
        if (tab[0][2] != "X" && tab[0][2] != "O")
            tab[0][2] = player;
        else cou = 1;
      
    }
    else if (b == 4) {
        if (tab[1][0] != "X" && tab[1][0] != "O")
            tab[1][0] = player;
        else cou = 1;
         
    }
    else if (b == 5) {
        if (tab[1][1] != "X" && tab[1][1] != "O")
            tab[1][1] = player;
        else cou = 1;
        
    }
    else if (b == 6) {
        if (tab[1][2] != "X" && tab[1][2] != "O")
            tab[1][2] = player;
        else cou = 1;
    }
    else if (b == 7) {
        if (tab[2][0] != "X" && tab[2][0] != "O")
            tab[2][0] = player;
        else cou = 1;

    }
    else if (b == 8) {
        if (tab[2][1] != "X" && tab[2][1] != "O")
            tab[2][1] = player;
        else cou = 1;
    }
    else {
        if (tab[2][2] != "X" && tab[2][2] != "O")
            tab[2][2] = player;
        else cou = 1;
    }
    if (cou == 0) {
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

}
 void PLay2() {
     while (true) {
         if (GetAsyncKeyState(0x01)) {
             POINT p;
             GetCursorPos(&p);
             HWND hWND = NULL;
             ScreenToClient(hWND, &p);
             gotoxy(p.x, p.y);

             cout << "(" << p.x << "," << p.y << ")" << endl;
             if (p.x <300&& p.y < 300) {
                 cout << "X";
                 gotoxy(242, 127);
                 

             }
         }
     }
}
char whowin() {
    int cX = 0, cO = 0;
    int c=0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] != "X" && tab[i][j] != "O") {
                c++;
            }
            if (tab[i][j] == "X") cX++;
            else if (tab[i][j] == "O") cO++;
            if (cX == 3 || cO == 3) {
                return cX > cO ? 'X' : 'O';
            }
        }
        cX = cO = 0;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[j][i] == "X") cX++;
            else if (tab[j][i] == "O") cO++;
            if (cX == 3 || cO == 3) {
                return cX > cO ? 'X' : 'O';
            }
        }
        cX = cO = 0;
    }
    if (tab[0][0] == "X" && tab[1][1] == "X" && tab[2][2] == "X")  return 'X';
    else if (tab[0][0] == "O" && tab[1][1] == "O" && tab[2][2] == "O")  return 'O';
    else if (tab[0][2] == "X" && tab[1][1] == "X" && tab[2][0] == "X")  return 'X';
    else if (tab[0][2] == "O" && tab[1][1] == "O" && tab[2][0] == "O")  return 'O';
    if (c == 0) return 'Z';

    return '.';
}
char Game(){
    int x = 0;
     Drawtab();

    while (whowin() == '.' || x==1){
        Play();
        Drawmati();
        if (whowin() == 'X') {
            gotoxy(1, 100);

            cout << endl;
            gotoxy(10, 10);
            cout << "   X winnnnnnnnnnnn";
            gotoxy(10, 10);
                cout << endl;
                char i;
                cout << "Do we want to play again!!!(y/n)";
                cin >> i;
                if (i == 'y') {
                    
                    return 'y';
                    x = 1;
                }
                else {
                    cout << "byyyyyyye" << endl;
                }
        }
        else if (whowin() == 'O') {
            gotoxy(10, 10);
            cout << endl << "  O winnnnnnnnnnnn" << endl;
            char i;
            cout << "Do we want to play again!!!(y/n)";
            cin >> i;
            if (i == 'y') {
                
                return 'y';
                x = 1;
            }
            else {
                cout << "byyyyyyye" << endl;
            }
        }
        else if (whowin() == 'Z') {
            gotoxy(10, 10);
            cout << endl << "No one winnnnn !!!" << endl;
            char i;
            cout << "Do you want to play again!!!(y/n)";
            cin >> i;
            if (i == 'y') {
                
                return 'y';
                x = 1;
            }
            else {
                cout << "byyyyyyye" << endl;
            }
        }
    }
}









int main()
{
    while (Game()=='y'){
        Game();
    }
   
    

 
   system("pause");
   /* while (true) {
       
            if (GetAsyncKeyState(0x01)) {
                POINT p;
                GetCursorPos(&p);
                HWND hWND = NULL;
                ScreenToClient(hWND, &p);
                gotoxy(p.x, p.y);

                cout << "(" << p.x << "," << p.y << ")" << endl;
                if (p.x< 200 && p.y <200) {
                    gotoxy(1, 19);
                    cout << "hello";
                   
               }
               
            }
    }*/

}
   
    
    
   
   
    
 

    


