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

int a, n, m, q;

bool isInside(int i, int j, vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    return i >= 0 && j >= 0 && i < n && j < m;
}

void solve() {
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> endMat(n, vector<int>(m));
    vector<int> hates(a);

    fore(i, 0, a) {
        hates[i] = i+1;
        hates[i] %= a;
    }

    fore(i, 0, n) {
        fore(j, 0, m) {
            cin >> mat[i][j];
        }
    }
    endMat = mat;

    fore(k, 0, q) {
        fore(i, 0, n){
            fore(j, 0, m){
                vector<pair<int, int>> neighbours = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
                for(auto coord : neighbours) {
                    if (isInside(i+coord.first, j+coord.second, mat) && mat[i+coord.first][j+coord.second] == hates[mat[i][j]]) {
                        endMat[i+coord.first][j+coord.second] = mat[i][j];
                    }
                }
            }
        }
        mat = endMat;
    }

    fore(i, 0, n) {
        fore(j, 0, m-1) {
            cout << mat[i][j] << " ";
        }print(mat[i][m-1]);
    }

    return;
}

int main() { _

    while(cin >> a >> n >> m >> q, a) {
        solve();
    }

	return 0;
}