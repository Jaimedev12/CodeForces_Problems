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
    vector<int> nums(n);
    fore(i, 0, n) {
        cin >> nums[i];
    }

    int negatives = 0;
    fore(i, 0, n) {
        if (nums[i] <= 0) {
            negatives++;
        }
    }
    sort(all(nums));

    lli ans = 0;
    int index = 0;
    for (index; index < negatives-(negatives%2); index++) {
        if (nums[index] == 0) {
            ans ++;
            continue;
        }
        ans += nums[index] * (-1) -1;
    }

    for (index; index < n; index++) {
        ans += abs(1-nums[index]);
    }

    print(ans);

	return 0;
}