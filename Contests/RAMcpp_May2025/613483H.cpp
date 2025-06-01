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
	lli n, m;
    cin >> n >> m;

    vector<string> mat(n);

    fore(i, 0, n) {
        cin >> mat[i];
    }

    lli holes = 0;
    lli plugs = 0;

    fore(i, 0, n) {
        fore(j, 0, m) {
            if (i > 0 && i < n-1 && j > 0 && j < m-1) continue;
            holes += mat[i][j] - '0';
        }
    }

    holes = ((n*2 + m*2) - 4) - holes;

    fore(i, 1, n-1) {
        fore(j, 1, m-1) {
            plugs += mat[i][j] - '0';
        }
    }

    // print("Holes: " << holes);
    // print("Plugs: " << plugs);

    if (holes > plugs) {
        print(-1);
        return;
    }

    print(holes);
}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}