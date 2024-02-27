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
    fore(i, 0, n) cin >> nums[i];

    int ans = 0;
    int curSum = 0;
    int maxSum = 0;
    int maxZeroes = 0;
    int curZeroes = 0;
    int l = 0;
    int r = 0;
    int ansL = 0;
    int ansR = 0;
    fore(i, 0, n) {
        if (nums[i] == 1) {
            curSum--;
        } else {
            curSum++;
            curZeroes++;
            r = i;
        }

        if (curSum > maxSum) {
            maxSum = curSum;
            maxZeroes = curZeroes;
            ansL = l;
            ansR = r;
        }

        if (curSum < 0) {
            curSum = 0;
            curZeroes = 0;
            l = i+1;
        }
    }
    ans = maxZeroes;
    // print("PrevAns: " << ans);

    fore (i, 0, ansL) {
        if (nums[i] == 1) {
            ans++;
        }
    }

    fore (i, ansR+1, n) {
        if (nums[i] == 1) {
            ans++;
        }
    }

    print(ans);
    // print("l: " << ansL);
    // print("r: " << ansR);
	return 0;
}