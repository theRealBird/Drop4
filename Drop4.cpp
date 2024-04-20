// DROP 4 GAME
// IC-151 SPRING 2020 END SEMESTER PROJECT
// 190003005 
// (Sample Output Image pasted at bottom of document) (Instructions are printed when the program is run) 

#include <bits/stdc++.h>
using namespace std;

bool win=false;         //Represents if someone has won the game or not

// A Player class for name customisation and programming comfort

class Player{
    private:
    string name;
    char symbol;

    public:
    Player(){name="";symbol='_';}

   void setPlayer(){
        cout<<"Welcome to Drop 4! What should I call you?"<<endl;cout<<"(Enter your name please):"<<endl;
        cin>>name;
        cout<<endl<<endl<<"Okay "<<name<<" Time to assign you your symbol..."<<endl<<endl;
    }
    
    void setSymbol(char p){
        symbol=p;}

    void setName(string s){
        name=s;
    }

    string returnName(){
        return name;
    }

    char returnSymbol(){
        return symbol;
    }
};
// A Colum class which represent actual columns of the game
//Tracker variable keeps track of the available slot
// where your "symbol" would drop into

class Column {
    public:
    int tracker;
    deque <char> position;
    Column(){
        tracker=0;
        for (int i=0;i<6;i++){
            position.push_back('_');
        }
    }
};

//A Matrix class which essentially helps in representing the 
// board as a Matrix with some very helpful member 
//functions that help in operating the game board

class Matrix{
    public:
    deque<deque<char>> x;       //Array of an array (but using deques for convenience)
    

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


int main(){

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

// This is how a typical game looks in the terminal }
