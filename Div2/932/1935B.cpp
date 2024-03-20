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

/*
3 3 0
0 1 2 3 4 5 6 7 8
*/

void solve() {
    int n; cin >> n;
    vector<int> nums(n);

    fore(i, 0, n) {
        cin >> nums[i];
    }

    vector<int> cnts(n+1);

    fore(i, 0, n) {
        cnts[nums[i]]++;
    }

    int mex;

    fore(i, 0, n+1) {
        if (cnts[i] == 1) {
            print(-1);
            return;
        }

        if (cnts[i] == 0) {
            mex = i;
            break;
        }
    }

    vector<bool> included(n+1);
    int numsLeft = mex;

    /*
        0 0 1 1
    */

    int k = 0;
    fore(i, 0, n) {
        if (numsLeft == 0) break;

        if (nums[i] >= mex) continue;

        if (included[nums[i]] == false) {
            included[nums[i]] = true;
            numsLeft--;
            k = i;
        }
    }

    numsLeft = mex;
    included = vector<bool>(n+1);
    fore(i, k+1, n) {
        if (numsLeft == 0) break;

        if (nums[i] >= mex) continue;

        if (included[nums[i]] == false) {
            included[nums[i]] = true;
            numsLeft--;
        }
    }

    if (numsLeft > 0) {
        print(-1);
        return;
    }

    print(2);
    print(1 << " " << k+1);
    print(k+2 << " " << n);
}

int main() { _

    int t; cin >> t;

    while (t--) {
        solve();
    }

	return 0;
}