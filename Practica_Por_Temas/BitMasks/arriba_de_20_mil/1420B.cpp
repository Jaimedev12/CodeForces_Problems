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


lli findHighestBit(lli n) {
    lli ans = 0;

    while (n) {
        n /= 2;
        ans++;
    }

    return ans;
}

void solve() {
    lli n; cin >> n;
    vector<lli> nums(n);
    vector<lli> maxBit(n);

    fore(i, 0, n) {
        cin >> nums[i];
    }

    fore(i, 0, n) {
        maxBit[i] = findHighestBit(nums[i]);
    }

    vector<lli> r(32);

    fore(i, 0, n) {
        r[maxBit[i]]++;
    }

    lli ans = 0;
    fore(i, 0, 32) {
        ans += ((r[i]) * (r[i]-1))/2;
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