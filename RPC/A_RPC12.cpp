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
    lli n, d;
    cin >> n >> d;

    print((double)n/(d+1));

    if (n == 1) {
        print(0);
        return;
    }

    lli ans = 1;
    lli maxComp = d+1;

    while (maxComp < n) {
        ans++;
        maxComp *= d+1;
    }

    print(ans);
    return;
}

int main() { _
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;    
}
