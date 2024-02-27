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
    // vector<int> dp(n);
    int prevDp = 1;
    int ans = 1;

    int prev; cin >> prev;
    int num;
    fore(i, 1, n) {
        cin >> num;
        if (num >= prev) {
            prevDp++;
        } else {
            prevDp = 1;
        }
        prev = num;
        ans = max(ans, prevDp);
    }

    cout << ans;

	return 0;
}