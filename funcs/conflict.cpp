#include <bits/stdc++.h>
using namespace std;

//INSTRUCTIONS TO REPLICATE
//Take pull of main
// change x = max(y,11) to max(y,10)
//Pull upstream's test into your local main
// Upstream's test has x = max(y,12,z)

int testFunc (int a){
    int y = 9;
    int z = 0;

    int x = max(y,12,z);
    
    return a;
}