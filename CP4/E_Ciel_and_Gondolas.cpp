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

const int MAX_N = 4000;
const int MAX_K = 800;
const int INF = numeric_limits<int>::max();

int n, k;
lli unfam[MAX_N][MAX_N];
lli dp[MAX_N][MAX_K];
lli groupCost[MAX_N][MAX_N];

void precomGroupCost(){
    fore(i, 0, n) {
        groupCost[i][i] = 0;
        fore(j, i+1, n) {
            groupCost[i][j] = groupCost[i][j-1];

            fore(k, i, j){
                groupCost[i][j] += unfam[j][k];
            }
        }
    }
}

lli findOptimalPartition() {
    fore(i, 0, MAX_N) {
        fore(j, 0, MAX_K) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    fore(i, 1, n+1) {
        fore(j, 1, k+1) {
            fore(p, j-1, i) {
                dp[i][j] = min(dp[i][j], dp[p][j-1] + groupCost[p][i-1]);
            }
        }
    }

    // fore(i, 0, n) {
    //     fore(j, 0, n) {
    //         if (groupCost[i][j] == INF) {
    //             cout << "INF" << " ";
    //             continue;
    //         }
    //         cout << groupCost[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;

    // fore(i, 0, n+1) {
    //     fore(j, 0, k+1) {
    //         if (dp[i][j] == INF) {
    //             cout << "INF" << " ";
    //             continue;
    //         }
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;


    return dp[n][k];
}

int main() { _
    cin >> n >> k;

    fore(i, 0, n) {
        fore(j, 0, n) {
            cin >> unfam[i][j];
        }
    }

    precomGroupCost();

    print(findOptimalPartition());

	return 0;
}