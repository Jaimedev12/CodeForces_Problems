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
    lli n; cin >> n;
    vector<lli> nums(n);

    fore(i, 0, n) {
        cin >> nums[i];
    }

    lli sum = 0;
    fore(i, 0, n) {
        sum += nums[i];
    }

    if (sum % 3 != 0) {
        print(0);
        return 0;
    }

    // print("Sum: " << sum);

    lli ans = 0;
    lli curSumI = 0;  
    fore(i, 0, n-1) {
        curSumI += nums[i];
        // print("curSumI: " << curSumI);
        if (curSumI != sum/3) continue;
        lli curSumJ = 0;
        // print("i: " << i);

        fore(j, i+1, n-1) {
            curSumJ += nums[j];
            // print("   curSumJ: " << curSumJ);
            if (curSumJ != sum/3) continue;
            // cout << "   --------->" << endl;
            ans++;
        }
    }

    print(ans);
	return 0;
}