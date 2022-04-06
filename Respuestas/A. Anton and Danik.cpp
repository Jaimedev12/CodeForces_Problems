
// A. Anton and Danik

#include <iostream>
using namespace std;

void countGames(int n, string games, int &a, int &d){
    for (int i = 0; i < n; i++){
        if (games[i] == 'A')
            a++;
        else
            d++;
    }
}

void printWinner(int a, int d){
    if (a > d)
        cout << "Anton";
    else if (d > a)
        cout << "Danik";
    else
        cout << "Friendship";
}

int main(){
   int n, aCnt = 0, dCnt = 0;
   string games;
 
   cin >> n;
   cin >> games;
   
   countGames(n, games, aCnt, dCnt);
   printWinner(aCnt, dCnt);
}

