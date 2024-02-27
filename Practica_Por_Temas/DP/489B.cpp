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
    vector<lli> boys(n);
    fore(i, 0, n) {
        cin >> boys[i];
    }

    lli m; cin >> m;
    vector<lli> girls(m);
    fore(i, 0, m) {
        cin >> girls[i];
    }

    sort(boys.rbegin(), boys.rend());
    sort(girls.rbegin(), girls.rend());

    lli i = 0;
    lli j = 0;
    lli ans = 0;
    while (i < n && j < m) {

        /*
        3 1 1 1
        7 6 1
        */

        lli curDif = abs(boys[i] - girls[j]);
        if (curDif <= 1) {
            i++;
            j++;
            ans++;
            continue;
        }

        if (boys[i] > girls[j]) {
            i++;
        } else {
            j++;
        }

        // print("i: " << i);
        // print("j: " << j);
        // cout << endl;
    }

    print(ans);
	return 0;
}