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

    lli n, k;
    cin >> n >> k;
    vector<lli> nums(n);
    vector<lli> sums(n);
    fore(i, 0, n) {
        cin >> nums[i];
    }
    sums[0] = nums[0];

    fore(i, 1, n) {
        sums[i] = sums[i-1] + nums[i];
    }

    lli ansInd = 1;
    lli minSum = sums[k-1];
    fore(i, k, n) {
        // print("pos: " << i);
        lli curSum = sums[i] - sums[i-k];
        // print("curSum: " << curSum);
        if (curSum < minSum) {
            ansInd = i-k+2;
            minSum = curSum;
        }
    }

    print(ansInd);

	return 0;
}