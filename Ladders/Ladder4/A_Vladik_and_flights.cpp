#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int n; cin >> n;
    int a; cin >> a;
    int b; cin >> b;
    string s; cin >> s;

    if (s[a-1] == s[b-1]) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }

    return 0;

}

