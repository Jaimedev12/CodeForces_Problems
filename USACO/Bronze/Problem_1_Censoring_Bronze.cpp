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

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() { _

    setIO("censor");
    string s, t;
    cin >> s >> t;

    string ans;
    fore(i, 0, sz(s)) {
        ans.pb(s[i]);

        if (sz(ans) >= sz(t) &&
            ans.substr(sz(ans) - sz(t)) == t) {
            ans.resize(sz(ans) - sz(t));
        }
    }

    print(ans);

	return 0;
}