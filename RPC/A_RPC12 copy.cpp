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

lli maxCompuestos(lli spaces, lli days) {
    return (1<<spaces)*days - days + 1;
}

void solve() {
    lli n, d;
    cin >> n >> d;

    if (n == 1) {
        print(0);
        return;
    }

    lli ans = 1;
    lli maxComp = maxCompuestos(ans, d);

    while (maxComp < n) {
        ans++;
        maxComp = maxCompuestos(ans, d);
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
