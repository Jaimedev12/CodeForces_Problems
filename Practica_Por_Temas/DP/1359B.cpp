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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    char mat[n][m];

    fore(i, 0, n) {
        fore(j, 0, m) {
            cin >> mat[i][j];
        }
    }

    lli ans = 0;
    fore(i, 0, n) {
        int aTiles = 0;
        int bTiles = 0;

        fore(j, 0, m) {
            if (mat[i][j] == '*') continue;
            if (j == m-1) {
                aTiles++;
                continue;
            }

            if (mat[i][j+1] == '*') {
                aTiles++;
                continue;
            }

            bTiles++;
            j++;
        }

        if (b < a*2) {
            ans += (bTiles*b) + (aTiles*a);
        } else {
            ans += (aTiles*a) + (bTiles*2*a);
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