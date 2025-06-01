// DP - Mandar a Danna

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
	lli n; cin >> n;

    vi dp(n);
    vi nums(n);
    // color , pos
    unordered_map<int, int> prevColorPos;
    fore(i, 0, n) {
        cin >> nums[i];
        if (i == 0) {
            prevColorPos[nums[i]] = i;
            continue;
        }

        if (prevColorPos.count(nums[i]) == 0) {
            // print("Color: " << nums[i] << " Not found");
            prevColorPos[nums[i]] = i;
            dp[i] = dp[i-1]+1;
            continue;
        }

        dp[i] = min(dp[i-1]+1, dp[prevColorPos[nums[i]]]+1);
        prevColorPos[nums[i]] = i;
    }

    // fore(i, 0, n) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    print(dp[n-1]);
}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}