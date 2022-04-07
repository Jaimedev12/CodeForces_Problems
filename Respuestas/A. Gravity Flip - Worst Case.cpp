
// A. Gravity Flip - Worst Case

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;
int n;

void readNumbers(){
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
}

void printNumbers(){
    for (size_t i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<int> v2(n);
    v = v2;
    
    readNumbers();
    sort(v.begin(), v.end());
    printNumbers();
}

