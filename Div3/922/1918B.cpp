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
    vector<pair<int, int>> ab(n);

    fore(i, 0, n) {
        cin >> ab[i].first;
    }

    fore(i, 0, n) {
        cin >> ab[i].second;
    }

    sort(ab.begin(), ab.end());

    fore(i, 0, n) {
        cout << ab[i].first << " ";
    }
    cout << endl;

    fore(i, 0, n) {
        cout << ab[i].second << " ";
    }
    cout << endl;
}

int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}