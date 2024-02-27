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


bool solve() {
    string s; cin >> s;

    int x = s[0] - 'A';
    int y = s.back() - 'A';
    if (x == y) return false;

    vector<int> vals(3);
    vals[x] = 1;
    vals[y] = -1;

    if (count(s.begin(), s.end(), x + 'A') == s.size()/2) {
        vals[3^x^y] = -1;
    } else {
        vals[3^x^y] = 1;
    }

    int val = 0;
    for (auto c: s) {
        val += vals[c-'A'];
        if (val < 0) return false;
    }

    return val == 0;
}

int main() { _

    int t; cin >> t;
    while(t--) {
        print((solve() ? "YES" : "NO"));
    }

	return 0;
}