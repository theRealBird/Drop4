#include <bits/stdc++.h>
using namespace std;

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