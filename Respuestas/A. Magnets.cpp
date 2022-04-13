// A. Magnets

#include <iostream>
#include <vector>

using namespace std;

int n = 0, cnt = 0;

void readInput(vector<int> &v){
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
}

void countGroups(vector<int> &v){
    for (int i = 0; i < n; i++){
        if (v[i] != v[i+1])
            cnt++;
    }
}

int main()
{
    cin >> n;
    vector<int> v(n);
    
    readInput(v);
    countGroups(v);
    
    cout << cnt;
}