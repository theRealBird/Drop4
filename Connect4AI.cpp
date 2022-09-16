#include <bits/stdc++.h>
using namespace std;

int AlphaBeta(const BitBoard &P, int alpha, int beta) {


  if(P.NumberofMoves() == BitBoard::WIDTH*BitBoard::HEIGHT){
      return 0;
  } 
     

  for(int x = 0; x < BitBoard::WIDTH; x++){

      if(P.Valid(x) && P.WinningMove(x)){
          return (BitBoard::WIDTH*BitBoard::HEIGHT+1 - P.NumberofMoves())/2;
      }
      
  } // check if current player can win next move
    

  int maxx = (BitBoard::WIDTH*BitBoard::HEIGHT-1 - P.NumberofMoves())/2;	// upper bound of our score as we cannot win immediately
  if(beta > maxx) {
    beta = maxx;                     // there is no need to keep beta above our max possible score.
    if(alpha >= beta) return beta;  // prune the exploration if the [alpha;beta] window is empty.
  }

  for(int x = 0; x < BitBoard::WIDTH; x++){ // compute the score of all possible next move and keep the best one
    
    if(P.Valid(x)) {
      BitBoard P2(P);
      P2.Move(x);               // It's opponent turn in P2 position after current player plays x column.
      int score = -AlphaBeta(P2, -beta, -alpha); // explore opponent's score within [-beta;-alpha] windows:
      // no need to have good precision for score better than beta (opponent's score worse than -beta)
      // no need to check for score worse than alpha (opponent's score worse better than -alpha)

      if(score >= beta) return score;  // prune the exploration if we find a possible move better than what we were looking for.
      if(score > alpha) alpha = score; // reduce the [alpha;beta] window for next exploration, as we only 
      // need to search for a position that is better than the best so far.
    }

  }
    
  return alpha;
}






class BitBoard{


    private:
    
    unsigned long long CurrentPositions;
    unsigned long long Occupied;
    unsigned int Moves;

    vector<int> ColumnOrder;

    public:

    BitBoard(){ //Default Constructor

        CurrentPositions = 0;
        Occupied = 0;
        Moves = 0;

        for(int i = 0; i <WIDTH; i++)
        ColumnOrder[i] = WIDTH/2 + (1-2*(i%2))*(i+1)/2; // initialize the column exploration order, starting with center columns
    }
    

    friend int AlphaBeta(const BitBoard &P, int alpha, int beta);

    static const int HEIGHT = 6;
    static const int WIDTH = 7;

    static unsigned long long ColumnMask (int column){
        
        unsigned long long x = 1;
        x = x<<HEIGHT;
        x = x - 1;      //Tall column of ones
        x = x<< column*(HEIGHT+1);  //Right position now
        return x;

    }

    static unsigned long long BottomMask (int column){

        long long x = 1;
        x = x<< column*(HEIGHT+1);  //Bottom most 1 of 'column'
        return x;

    }

    static unsigned long long TopMask (int column){

        long long x = 1;
        x = x<< HEIGHT-1;
        x = x<< column*(HEIGHT+1);  //Top most 1 of 'column'
        return x;

    }

    static bool Check (unsigned long long board){

        //Horizontal 
        unsigned long long x = board & (board>>(HEIGHT+1));
        if(x & (x>> (2*(HEIGHT+1)))) return true;

        //Vertical
        x = board & (board>>1);
        if(x & (x>>2)) return true;

        //Diagonals 
        x = board & (board>>(HEIGHT+2));
        if(x & (x>>2)) return true;

        //and...

        x = board & (board>>1);
        if(x & (x>>2)) return true;

        return false;
    }

    

    bool Valid (int column) const
    {

        return (Occupied & TopMask(column)) == 0 ;

    }

    void Move (int column){

        CurrentPositions ^= Occupied;
        Occupied |= Occupied + BottomMask(column);

    }

    unsigned int Move (string List){

        for(unsigned int i=0;i<List.size();i++){

            int column = List[i]-'1';
            if( column<0 || column >= BitBoard::WIDTH || !Valid(column) || WinningMove(column)) return i;
            Move(column);

        }

        return List.size();

    }

    bool WinningMove (int column) const
    {

        unsigned long long x = CurrentPositions;
        x |= (Occupied + BottomMask(column)) & ColumnMask(column);
        return Check(x);

    }

    unsigned int NumberofMoves() const
    {
        return Moves;
    }

    unsigned long long Key(){
        return CurrentPositions+Occupied;
    }


};




vector <vector<int>> Solution (vector<vector<int>> Board){

    BitBoard x;
    


}