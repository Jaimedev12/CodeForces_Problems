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
    vector<int> nums(n);
    vector<int> dp(n);

    fore(i, 0, n) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = nums[i];

        if (i + nums[i] < n) {
            dp[i] += dp[i+nums[i]];
        }
        ans = max(ans, dp[i]);
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