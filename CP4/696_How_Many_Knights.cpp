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

    int n, m;

    while (cin >> n >> m, n) {
        int k;

        if (min(n, m) == 1) {
            k = max(n, m);
        } else if (min(n, m) == 2) {
            k = 4 * int(max(n, m) / 4) + 2 * min(2, max(n, m) % 4);
        } else {
            k = (n*m+1)/2;
        }

        print(k << " knights may be placed on a " << n << " row " << m << " column board.");
    }

	return 0;
}