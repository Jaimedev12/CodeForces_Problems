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
    int n; cin >> n;
    string log; cin >> log;
    vector<int> cnts(30);

    int ans = 0;

    fore(i, 0, n) {
        cnts[log[i]-'A']++;
    }

    fore(i, 0, 30) {
        if (cnts[i] >= i+1) {
            ans++;
        }
    }

    print(ans);
}

int main() { _

    int t; cin >> t;

    while (t--) {
        solve();
    }    

	return 0;
}