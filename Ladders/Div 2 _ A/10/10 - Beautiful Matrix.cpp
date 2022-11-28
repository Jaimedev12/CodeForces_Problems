
// A. Beautiful Matrix

#include <cmath>
#include <utility>
#include <iostream>
using namespace std;

void get1Coords(pair<int, int> &coord1){
    int x = 0;
    for (int i = 1; i < 6; i++){
        coord1.first = i;
        for (int j = 1; j < 6; j++){
            coord1.second = j;
            cin >> x;
            if (x == 1)
                return;
        }
    }
}

// Resta vectorial de las coordenadas del centro y el 1
void calculateMoves(pair<int, int> &coord1, int &cnt){
    cnt = abs(3 - coord1.first);
    cnt = cnt + abs(3 - coord1.second);
}

int main(){
    int x, y, cnt = 0;
    pair<int, int> coord1 = {x, y};
    
    get1Coords(coord1);
    calculateMoves(coord1, cnt);
    
    cout << cnt;
}

