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
    int a = 0;
    int b = 0;
    string s1, s2;
    cin >> s1 >> s2;

    fore(i, 0, n) {

        if (s1[i] == s2[i]) continue;

        if (s1[i] == '1') a++;
        if (s2[i] == '1') b++;
    }

    int ans = 0;
    ans += abs(a-b);
    ans += min(a, b);
    print(ans);
}

int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}