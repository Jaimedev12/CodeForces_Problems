// A. Stones on the Table

#include <iostream>
#include <string>

using namespace std;

int n = 0, cnt = 0;

void countRemovableStones(string &s){
    for (int i = 0; i < n; i++){
        if (s[i] == s[i+1])
            cnt++;
    }
}

int main()
{
    string s;
    
    cin >> n;
    cin >> s;
    
    countRemovableStones(s);
    
    cout << cnt;
}
