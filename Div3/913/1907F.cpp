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

    fore(i, 0, n) {
        cin >> nums[i];
    }

    if (is_sorted(nums.begin(), nums.end())) {
        print(0);
        return;
    }

    vector<int> tmp = nums;
    reverse(tmp.begin(), tmp.end());
    if (is_sorted(tmp.begin(), tmp.end())) {
        print(1);
        return;
    }

    auto isForwardCyclic = [&]{
        auto minIter = min_element(nums.begin(), nums.end());
        int minNum = *minIter;
        int minIndex = distance(nums.begin(), minIter);

        int curIndx = minIndex;
        fore(i, 0, n-1) {
            int next = curIndx+1;
            next %= n;

            if (nums[next] < nums[curIndx]) return false;

            curIndx++;
            curIndx %= n;
        }

        return true;
    };

    auto isBackCyclic = [&]{
        auto minIter = min_element(nums.begin(), nums.end());
        int minNum = *minIter;
        int minIndex = distance(nums.begin(), minIter);

        int curIndx = minIndex;
        fore(i, 0, n-1) {
            int next = curIndx-1;
            if (next == -1) next = n-1;

            if (nums[next] < nums[curIndx]) return false;

            curIndx--;
            if (curIndx == -1) curIndx = n-1;
        }

        return true;
    };

    if (!isForwardCyclic() && !isBackCyclic()) {
        print(-1);
        return;
    } else {
        print("Hay que checar más");
    }
}

int main() { _
    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}