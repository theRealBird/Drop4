#include <bits/stdc++.h>
using namespace std;

class Matrix{
    
    public:
    bool win;
    deque< deque<char> > x;       //Array of an array (but using deques for convenience)
    

    void Push(deque <char> y){
        x.push_back(y);
    }

    void DisplayGame(){         //Outputs the current state of the game
        for (int i=5;i>=0;i--){
            for (int j=0;j<7;j++){
                cout<<x[j][i]<<" "<<" "<<" "<<" ";  //For formatting purpose (PDF to cpp) (Need to put spaces like this)
            }
            cout<<endl<<endl;
        }
        for (int i=0;i<7;i++){
            cout<<i+1<<" "<<" "<<" "<<" ";  //For formatting purpose (PDF to cpp)(Need to put spaces like this)
        }
        cout<<endl<<endl;
    }

    //The following methods check if there are four 
    //symbols in a consecutive order in a row, column 
    // or diagonally. 

    //The efficiency is increased by only checking
    // the rows, columns and diagonals of the board 
    //of which the symbol that was dropped
    //is a part of.

    //The move at a place which generates a win 
    //must be a part of the winning 4 symbol
    //combination. Hence it is sufficient to 
    //check for the rows and columns and diagonals 
    //of that place only.

    void WinCheckHorizontal(int i,int j){  
        int count=1;
        for (int z=0;z<6;z++){
            if (x[z][j]==x[z+1][j] && x[z][j]!='_' ){
                count+=1;
                if (count>=4){win=true;}
            }
            else {count=1;}
        }
    }

    
    void WinCheckVertical(int i,int j){
        int count=1;
        for (int z=0;z<5;z++){
            if (x[i][z]==x[i][z+1] && x[i][z]!='_'){
                count+=1;
                if (count>=4){win=true;}
            }
            else {count=1;}
        }
        
    }
    //Diagonal 1 checks for the diagonal with slope=1

    void WinCheckDiagonal1(int i,int j){
        int count=1;
        if (i<=j){
            for (int z=j-i;z<5;z++){
                if (x[z-j+i][z]==x[z-j+i+1][z+1] && x[z-j+i][z]!='_' ){
                    count+=1;
                    if (count>=4){win=true;}
                }
                else {count=1;}
            }
           
        }
        else if(i>j){
            for (int z=i-j;z<6;z++){
                if (x[z][z-i+j]==x[z+1][z-i+j+1] && x[z][z-i+j]!='_' ){
                    count+=1;
                    if (count>=4){win=true;}
                }
                else {count=1;}
            }
        }
    }
    //Diagonal 2 checks for the diagonal with slope= -1
    
    void WinCheckDiagonal2(int i,int j){
        int count=1;
        int k=i+j;
        if (k<=5){
            for (int z=k;z>0;z--){
                if (x[z][k-z]==x[z-1][k-z+1] && x[z][k-z]!='_'){
                    count+=1;
                    if (count>=4){win=true;}
                }
                else {count=1;}
            }
        }
        else if (k>5){
            for (int z=5;z>=0;z--){
                if(x[z][k-z]==x[z--][k-z+1]  && x[z][k-z]!='_'){
                    count+=1;
                    if (count>=4){win=true;}
                }
                else {count=1;}
            }
        }
    }
};
