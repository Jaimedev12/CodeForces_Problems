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

lli calcMSB(lli n) {
    lli ans = 0;
    while (n) {
        n /= 2;
        ans++;
    }
    return ans;
}

void solve() {
    lli n; cin >> n;

    if (n == 2) {
        cout << "0 1" << endl;
        return ;
    }

    lli msb = calcMSB(n);
    lli end = (1 << (msb-1));

    if (end == n) end /= 2;

    for (lli i = end-1; i >= 1; i--) {
        cout << i << " ";
    }

    if (end != n){
        cout << 0 << " ";
    }
    

    for (lli i = end; i < n; i++) {
        cout << i << " ";
    }
    if (end == n) {
        cout << 0 << " ";
    }
    // cout << 0 << " ";

    // for (lli i = 1; i < end; i++) {
    //     cout << i << " ";
    // }
    cout << endl;
}

int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}