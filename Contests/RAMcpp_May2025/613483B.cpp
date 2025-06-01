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
    lli n, m;
    cin >> n >> m;

    vi nums(n);

    lli firstDefined = -1;
    fore(i, 0, n) {
        cin >> nums[i];

        if (nums[i] != -1 && firstDefined == -1) {
            firstDefined = i;
        }
    }

    for (int i = firstDefined-1; i >= 0; i--) {
        nums[i] = nums[i+1]-1;
        if (nums[i] < 0) nums[i] = m-1;
    }

    fore(i, firstDefined+1, n) {
        nums[i] = (nums[i-1]+1)%m;
    }

    fore(i, 0, n) {
        cout << nums[i] << " ";
    }
    cout << endl;
}  

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}