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

    vector<vector<lli>> mat(3, vector<lli>(n));

    fore(i, 0, 3) {
        fore(j, 0, n) {
            cin >> mat[i][j];
        }
    }

    vector<vector<pair<lli, lli>>> matPair(3, vector<pair<lli, lli>>(n));

    fore(i, 0, 3) {
        fore(j, 0, n){
            matPair[i][j] = make_pair(mat[i][j], j);
        }
    }

    fore(i, 0, 3){
        sort(matPair[i].rbegin(), matPair[i].rend());
    }

    lli ans = 0;

    fore(i, 0, 3) {
        fore(j, 0, 3) {
            fore (k, 0, 3) {
                if (matPair[0][i].second == matPair[1][j].second || 
                    matPair[0][i].second == matPair[2][k].second || 
                    matPair[2][k].second == matPair[1][j].second) continue;

                lli suma = 0;
                suma = matPair[0][i].first +
                       matPair[1][j].first +
                       matPair[2][k].first;
                    
                ans = max(ans, suma);
            }
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