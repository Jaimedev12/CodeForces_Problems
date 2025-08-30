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

    vector<bitset<32>> mat(n);

    lli temp;
    fore(i, 0, n) {
        cin >> temp;
        mat[i] = temp;
    }

    // fore(i, 0, n) {
    //     print(mat[i]);
    // }

    lli ans = 0;
    lli currAporte = 1;

    fore(i, 0, 32) {
        lli currCount = 0;
        // print("Checking bit: " << i << " con aporte: " << currAporte);

        fore(j, 0, n) {
            if (mat[j][i]) {
                currCount++;
            } else {
                lli totalSubarrs = (currCount * (currCount+1))/2;
                ans += totalSubarrs * currAporte;
                currCount = 0;
            }
        }
        lli totalSubarrs = (currCount * (currCount+1))/2;
        ans += totalSubarrs * currAporte;
        currCount = 0;
        currAporte = currAporte<<1;
        // print("CurrAns: " << ans);
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