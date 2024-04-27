#include <bits/stdc++.h>
#include "column.cpp" 
#include "matrix.cpp"
#include "player.cpp"
using namespace std;

int main(){
    bool win = false;
    //Welcome message and instructions

    cout<<"Welcome To Drop4!!!!!!!"<<endl<<endl<<endl<<endl;
    cout<<"RULES OF THE GAME:"<<endl;
    cout<<"It's a two player game in which two players are assigned a symbol each"<<endl;
    cout<<" and then take turns 'dropping' one symbol at a time into the LOWEST available"<<endl;
    cout<<" space in a column selected by them so that:"<<endl;
    cout<<"Four symbols of the same type occur consecutively in the same"<<endl;
    cout<<" row, column or in a diagonal direction."<<endl<<endl<<endl;

    //Setting up the board
    Column a,b,c,d,e,f,g;
    Matrix board;
    board.Push(a.position);
    board.Push(b.position);
    board.Push(c.position);
    board.Push(d.position);
    board.Push(e.position);
    board.Push(f.position);
    board.Push(g.position);

    cout<<"The Game Grid: (7x6)"<<endl<<endl;
    board.DisplayGame();

    
    Player one,two;

    srand(time(0));

    one.setPlayer();
    if (rand()%2==0){
        one.setSymbol('O');
        two.setSymbol('#');
        }
    else {
        one.setSymbol('#');
        two.setSymbol('O');
        }
    char temp1=one.returnSymbol();
    cout<<"Your symbol has been randomly decided as: "<<temp1<<endl<<endl<<" Other player's turn: "<<endl;
    two.setPlayer();
    temp1=two.returnSymbol();
    cout<<"Your symbol has been randomly decided as: "<<temp1<<endl<<endl<<endl;

    cout<<"We are good to go!"<<endl<<endl<<endl;
    cout<<" # always plays first... ";

    //Setting the player who goes first as temp2 for the first run
    
    Player temp2;                           //This variable will essentially track the current player 
    if (one.returnSymbol()=='#'){           //and keep on changing between the two...
        temp2.setName(one.returnName());
        temp2.setSymbol('#');}
    else {
        temp2.setName(two.returnName());
        temp2.setSymbol('#');}
    cout<<"So it's "<<temp2.returnName()<<"'s turn!"<<endl;

    
    // Loop which keeps the game running 
    //until somebody wins
    while(!win){
        u:
        cout<<"Make a move!"<<endl;
        cout<<"Choose the column in which you want to drop in your symbol by entering the column number: "<<endl;
        int temp3,temp4;
        cin>>temp3;
       
        switch (temp3){
                case 1: 
                temp4=a.tracker;
                board.x[0][a.tracker]=temp2.returnSymbol();
                a.tracker++;
                break;
                
                case 2:
                temp4=b.tracker;
                board.x[1][b.tracker]=temp2.returnSymbol();
                b.tracker++;
                break;
                
                case 3:
                temp4=c.tracker;
                board.x[2][c.tracker]=temp2.returnSymbol();
                c.tracker++;
                break;
                
                case 4:
                temp4=d.tracker;
                board.x[3][d.tracker]=temp2.returnSymbol();
                d.tracker++;
                break;
                
                case 5:
                temp4=e.tracker; 
                board.x[4][e.tracker]=temp2.returnSymbol();
                e.tracker++;
                break;

                case 6:
                temp4=f.tracker; 
                board.x[5][f.tracker]=temp2.returnSymbol();
                f.tracker++;
                break;

                case 7:
                temp4=g.tracker; 
                board.x[6][g.tracker]=temp2.returnSymbol();
                g.tracker++;
                break;

                default:
                cout<<"Error: Please Choose a valid response! "<<endl<<endl<<endl;
                goto u;
                break;
            }
        
   
        
        
        cout<<"Good move! "<<temp2.returnName()<<endl;
       
        temp3--;        //To adjust for index (Index is one less than the column number)

        //Checking if the move has lead to a victory:

        board.WinCheckHorizontal(temp3,temp4);
        board.WinCheckVertical(temp3,temp4);
        board.WinCheckDiagonal1(temp3,temp4);
        board.WinCheckDiagonal2(temp3,temp4);
        if (win){break;}

        board.DisplayGame();

        // Changing the players for the next turn
        if (temp2.returnSymbol()==one.returnSymbol()){
            temp2.setSymbol(two.returnSymbol());
            temp2.setName(two.returnName());
        }
        else{
            temp2.setSymbol(one.returnSymbol());
            temp2.setName(one.returnName());
        }
        cout<<endl<<endl<<endl<<"It's now "<<temp2.returnName()<<"'s turn..."<<endl<<endl<<endl<<endl;

        
    }
    //Victory message!
    board.DisplayGame();
    cout<<"Congrats! "<<temp2.returnName()<<" You have won!!!"<<"Thanks for playing!"<<endl;
    
    return 0;
    }
