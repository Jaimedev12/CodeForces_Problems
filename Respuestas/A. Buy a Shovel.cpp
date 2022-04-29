// A. Buy a Shovel

#include <iostream>

using namespace std;

int main()
{
    int k, r, change = 1, cnt = 1, rest;
    cin >> k >> r;
    
    while (change != 0){
        rest = (k * cnt) % 10;
        change = rest - r;
        
        if (change != 0)
            cnt++;
    }
    
    cout << cnt << endl;
}
