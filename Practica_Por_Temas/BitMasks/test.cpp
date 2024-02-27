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

    1100100
   10101100 
____________
   11001000


*/

void test(lli n, vector<lli> nums) {
    lli val = nums[0] ^ nums[1];
    fore(i, 1, n-1) {
        val = max(val, (nums[i]^nums[i+1]));
    }

    print(val);
}

lli calcMSB(lli n) {
    lli ans = 0;
    while (n) {
        n /= 2;
        ans++;
    }
    return ans;
}

int main() { _

    lli n; cin >> n;
    vector<lli> nums(n);
    fore(i, 0, n) {
        cin >> nums[i];
    }
    
    lli msb = calcMSB(n);
    lli end = (1 << (msb-1));
    vector<lli> ans;

    for (lli i = n-1; i >= end; i--) {
        ans.push_back(i);
    }
    ans.push_back(0);

    for (lli i = end-1; i >= 1; i--) {
        ans.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    } cout << endl;

    test(n, nums);
    test(n, ans);

	return 0;
}