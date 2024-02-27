// Two Substrings
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

bool solapan(pii a, pii b) {

    if (a.first == b.second || a.second == b.first) return 1;

    return 0;
}

bool solve() {
    string s; cin >> s;
    vector<pii> bas;
    vector<pii> abs;

    fore(i, 0, s.size()-1) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            abs.push_back({i, i+1});
        }
    }
     fore(i, 0, s.size()-1) {
        if (s[i] == 'B' && s[i+1] == 'A') {
            bas.push_back({i, i+1});
        }
    }

    // print("BAs: ");
    // fore(i, 0, bas.size()) {
    //     print("    " << bas[i].first << " " << bas[i].second);
    // }

    // print("ABs: ");
    // fore(i, 0, abs.size()) {
    //     print("    " << abs[i].first << " " << abs[i].second);
    // }

    if (abs.size() > 1 && bas.size() > 1) {
        return 1;
    }

    fore(i, 0, abs.size()) {
        fore(j, 0, bas.size()) {
            if (!solapan(abs[i], bas[j])) return 1;
        }
    }
    return 0;
}

int main() { _
    
    print((solve() ? "YES" : "NO"));
	return 0;
}