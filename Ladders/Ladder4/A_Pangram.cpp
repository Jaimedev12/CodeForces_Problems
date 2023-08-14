#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int n; cin >> n;
    string s; cin >> s;
    unordered_set<char> letters;

    for (char c : s) {
        letters.insert(tolower(c));
        if (letters.size() == 26) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;

}