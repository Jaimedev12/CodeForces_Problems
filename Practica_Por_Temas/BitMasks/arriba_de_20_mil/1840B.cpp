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
    lli n, k;
    cin >> n >> k;

    lli mNbit = calcMSB(n);
    // print("mNbit:" << mNbit);

    if (mNbit > k) {
        lli ans = 1;
        ans = ans << k;
        print(ans); 
    } else {
        print(n+1);
    }
}

int main() { _
    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}