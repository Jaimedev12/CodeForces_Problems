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

const lli MOD = (1e9)+7;

void solve() {
    int n, k;
    cin >> n >> k;

    lli ans = 1;

    fore(i, 0, k) {
        ans *= n;
        ans %= MOD;
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