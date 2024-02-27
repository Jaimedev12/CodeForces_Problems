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
    string s; cin >> s;

    vector<int> count(30);
    fore(i, 0, n) {
        count[s[i]-'a']++;
    }

    int mostCommon = 0;
    fore(i, 0, 30) {
        mostCommon = max(count[i], mostCommon);
    }

    int rest = n-mostCommon;

    while (rest > mostCommon) {
        rest -= 2;
    }

    print(mostCommon-rest);
}


int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}