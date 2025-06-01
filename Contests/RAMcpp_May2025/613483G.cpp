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

    vi nums(n);
    fore(i, 0, n) {
        cin >> nums[i];
    }

    vi largestFromLeft(n);
    largestFromLeft[0] = nums[0];
    vi smallestFromRight(n);
    smallestFromRight[n-1] = nums[n-1];

    fore(i, 1, n) {
        largestFromLeft[i] = max(nums[i], largestFromLeft[i-1]);
    }

    for(int i = n-2; i >= 0; i--) {
        smallestFromRight[i] = min(smallestFromRight[i+1], nums[i]);
    }

    lli ans = 0;

    fore(i, 1, n-1) {
        lli num = nums[i];
        if (num <= smallestFromRight[i+1] && num >= largestFromLeft[i-1]) {
            ans++;
        }
    }

    print(ans);
}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}