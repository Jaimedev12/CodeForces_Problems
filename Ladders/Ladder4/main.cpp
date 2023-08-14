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

const int MAXN = 100;

int solve(int mat[MAXN][MAXN], int n, int m) {
    for(int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (i+2 < n && j+1 < m) {
                mat[i+2][j+1] += mat[i][j];
            }

            if (i+1 < n && j+2 < m) {
                mat[i+1][j+2] += mat[i][j];
            }
        }
    }
    return mat[n-1][m-1];
}

int main() { _

    int n, m;
    int mat[MAXN][MAXN];
    mat[0][0] = 1;
    cin  >> n >> m;
    cout << solve(mat, n, m) << endl;

    return 0;

}