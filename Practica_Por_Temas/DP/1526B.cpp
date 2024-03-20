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
    if (n > 11*111) {
        print("YES");
        return;
    }

    unordered_set<int> possible;
    for (int i = 0; i <= 11*111; i += 111) {
        for (int j = 0; j+i <= 11*111; j += 11) {
            possible.insert(i+j);
        }
    }

    if (possible.count(n)) {
        print("YES");
    } else {
        print("NO");
    }
}

int main() { _

    int t; cin >> t;

    while (t--) {
        solve();
    }
	return 0;
}