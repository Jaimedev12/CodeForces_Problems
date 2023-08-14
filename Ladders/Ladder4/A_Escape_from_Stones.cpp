#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    string s; cin >> s;
    int n = s.length();

    vector<int> l;
    l.reserve(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'l') {
            l.push_back(i+1);
        } else {
            cout << i+1 << endl;
        }
    }

    for (int i = l.size()-1; i >= 0; i--) {
        cout << l[i] << endl;
    }

    return 0;

}