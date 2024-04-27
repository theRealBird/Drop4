#include <bits/stdc++.h>
using namespace std;

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