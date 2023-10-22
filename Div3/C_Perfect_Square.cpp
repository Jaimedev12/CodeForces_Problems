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
    vector<vector<char>> mat(n, vector<char>(n));

    fore(i, 0, n) {
        fore(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    int cnt = 0;
    fore(i, 0, n) {
        fore(j, 0, n) {
            int a = mat[i][j];
            int b = mat[i][n-1-j];
            int c = mat[n-1-i][j];
            int d = mat[j][i];

            int maxChar = max(a, b);
            maxChar = max(maxChar, c);
            maxChar = max(maxChar, d);

            cnt += (maxChar-'a') - (a-'a');
        }
    }

    print(cnt);
    return;
}

int main() { _

    int t; cin >> t;

    while (t--) {
        solve();
    }

	return 0;
}