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

int main() { _

    int n; cin >> n;
    vector<int> days(n+1);
    fore(i, 1, n+1) {
        cin >> days[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(3));

    fore(i, 1, n+1) {
        dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
        // print("days: " << days[i]);

        if (days[i] == 1 || days[i] == 3) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        } else {
            dp[i][1] = dp[i-1][1]+1;
        }

        if (days[i] == 2 || days[i] == 3) {
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        } else {
            dp[i][2] = dp[i-1][2]+1;
        }        
    }

    // fore(i, 0, n+1) {
    //     fore(j, 0, 3) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    print(ans);

	return 0;
}