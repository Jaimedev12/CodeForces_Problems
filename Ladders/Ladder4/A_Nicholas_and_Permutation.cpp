#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int n; cin >> n;
    vector<int> vec(n);

    vector<int> pos(2);
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        if (vec[i] == 1 || vec[i] == n) {pos[k] = i; k++;}
    }
    
    cout << max(pos[1], n-1 - pos[0]) << endl;

    return 0;

}