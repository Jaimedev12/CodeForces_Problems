#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int n; cin >> n;
    string s; cin >> s;

    int cnt = 0;

    for (int i = 0; i < n-1; i += 2) {
        if (s[i] == s[i+1]) {
            if (s[i] == 'a') {
                s[i] = 'b';
                cnt++;
            } else {
                s[i] = 'a';
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    cout << s << endl;


}