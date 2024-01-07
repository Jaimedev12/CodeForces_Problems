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
    char piece; cin >> piece;
    int m, n; cin >> m >> n;

    if (piece == 'r') {
        print(min(m, n));
    } 
    else if (piece == 'k') {
        int rows = (n+1)/2;
        int cols = (m+1)/2;
        print(rows*cols + ((n/2)*(m/2)));
    }
    else if (piece == 'Q') {
        print(min(n, m));
    } 
    else if (piece == 'K') {
        int rows = (n+1)/2;
        int cols = (m+1)/2;
        print(rows*cols);
    }

    return;
}

int main() { _

    int t; cin >> t;

    while (t--) {
        solve();
    }

	return 0;
}