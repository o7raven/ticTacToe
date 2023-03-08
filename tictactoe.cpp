#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void displayPlayGround();
void move(char player);
void decide();
void draw();
bool checkState();
void winner(char winner);

bool XonTheMove();

char weiner; 


int whosOnTheMove = 0;
int moves = 0;

const int columns =3;
const int rows = 3;

const char blankSpace = '-';


char players[] = {'x', 'o'};

char playGround[columns][rows] = {
    {blankSpace,blankSpace,blankSpace},
    {blankSpace,blankSpace,blankSpace},
    {blankSpace,blankSpace,blankSpace},
};



int main(){

    displayPlayGround();
    decide();
    return 0; 
}

void displayPlayGround(){    

    cout << endl;
    cout << moves;
    cout << endl;

    for(int i = 0; i < columns; i++){
        for(int j = 0;  j < rows; j++){
            cout << " | ";
            cout << playGround[i][j];
            cout << " | ";
        }
        cout << endl;
    }

}

void decide(){
    if(XonTheMove()){
        move('x');
    }else{
        move('o');
    }
}

bool XonTheMove(){
    if(whosOnTheMove % 2 == 0){
        whosOnTheMove++;
        return true;
    }else{
        whosOnTheMove++;
        return false;
    }
}

void move(char player){
    char plrOnTheMove = player;
    cout << "\n(" << plrOnTheMove << ")" << "Where to you want to move? (Columns) ";
    int columnsMove;
    cin >> columnsMove;
    cout << "\n(" << plrOnTheMove << ")" << "Where to you want to move? (Rows) ";
    int rowsMove;
    cin >> rowsMove;

    if(columnsMove > columns || columnsMove <= (columns - columns) || rowsMove > rows || rowsMove <= (rows - rows)){

        cout << "\nInvalid option, try again";
        move(plrOnTheMove);
    }

    if(playGround[columnsMove-1][rowsMove-1] == blankSpace){



            playGround[columnsMove-1][rowsMove-1] = plrOnTheMove;
            moves++;
            displayPlayGround();
            if(checkState()){
                winner(weiner);
            }else{

                decide();

            }
        
       


    }else{
        cout << "\nInvalid move (There's not blank space you idiot)\n";
        displayPlayGround();
        move(plrOnTheMove);
        
    }

}

bool checkState(){


    for(char i:players){
        for(int j = 0; j < rows; j++){


            if(i == playGround[j][0] && i == playGround[j][1] && i == playGround[j][2]){
                char &_weiner = weiner;
                _weiner = i;
                return true;
            }

        }
        for(int k = 0; k < columns; k++){


            if(i == playGround[0][k] && i == playGround[1][k] && i == playGround[2][k]){
                char &_weiner = weiner;
                _weiner = i;
                return true;
            }

        }


        if(i == playGround[0][0] && i == playGround[1][1] && i == playGround[2][2]){
            char &_weiner = weiner;
            _weiner = i;
            return true;
        }

        

        if(i == playGround[0][2] && i == playGround[1][1] && i == playGround[2][0]){
            char &_weiner = weiner;
            _weiner = i;
            return true;
        }

        
    }
    return false;
}

void winner(char winner){
    cout << endl  << winner << " has won!\n";

    
}

void draw(){
    cout << "No winner, no loser. It's a draw nerds";
}