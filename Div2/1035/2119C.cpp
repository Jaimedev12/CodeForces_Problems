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

const lli MOD = 1e9 + 7;

lli sumMod(lli a, lli b) {
    return ((a%MOD) + (b%MOD))%MOD;
}

lli multMod(lli a, lli b) {
    return ((a%MOD) * (b%MOD))%MOD;
}


void solve() {
	lli n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n % 2 == 1) {
        print(l);
        return;
    }

    if (n == 2) {
        print(-1);
        return;
    }


    lli secondNum = (1LL << lli(log2(l)+1));

    if (secondNum > r) {
        print(-1);
        return;
    }

    
    if (k <= n-2) {
        print(l);
    } else {
        print(secondNum);
    }

}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}