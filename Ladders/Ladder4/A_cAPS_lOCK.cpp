#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

string convert(string s) {
    fore(i, 0, s.length()) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        } else {
            s[i] = toupper(s[i]);
        }
    }

    return s;
}

int main() { _

    string s; cin >> s;
    string newS = s;

    if (s.length() == 1) {
        newS = convert(s);
    }

    bool flag = 1;
    fore(i, 1, s.length()) {
        if (islower(s[i])) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        newS = convert(s);
    }

    print(newS);

    return 0;

}