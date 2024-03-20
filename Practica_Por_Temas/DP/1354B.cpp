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

void solve() {
    string s; cin >> s;
    int ans = INT_MAX;

    if (s.size() < 3) {
        print(0);
        return;
    }

    int l = 1;
    int r = 1;

    fore(i, 1, s.size()) {
        // print("l: " << l << "    r: " << r);
        if (s[i] == s[i-1]) {
            r++;
            continue;
        }

        if (l == 0) {
            l = i;
            r = i;
            continue;
        }

        if (s[l-1] != s[l] && 
            s[r+1] != s[r] && 
            s[l-1] != s[r+1]) {
                ans = min(ans, r-l+3);
        }

        l = i;
        r = i;
    }

    print((ans == INT_MAX ? 0 : ans));
}

int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}