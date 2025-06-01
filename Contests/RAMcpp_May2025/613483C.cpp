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

const lli MOD = 1e9 + 7;

void solve() {
	lli n; cin >> n;
    vi nums(n);

    fore(i, 0, n) {
        cin >> nums[i];
    }

    vi numsOrdered = nums;
    sort(all(numsOrdered));

    fore(i, 0, n) {
        lli x = nums[i];
        lli y = 0;

        auto ity = lower_bound(all(numsOrdered), MOD-x);

        if (ity == numsOrdered.end()) ity--;

        // print(*ity);

        while (*ity >= MOD-x) {
            if (ity == numsOrdered.begin()) {
                ity = numsOrdered.end();
                ity--;
                break;
            }

            ity--;
        }

        if (*ity == x) {
            if (ity == numsOrdered.begin()) {
                ity = numsOrdered.end();
            } 
            ity--;
        }

        y = *ity;

        cout << (x+y)%MOD << " ";
    }
    cout << endl;


    // fore(i, 0, n) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    // fore(i, 0, n) {
    //     cout << numsOrdered[i] << " ";
    // }
    // cout << endl;
}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}