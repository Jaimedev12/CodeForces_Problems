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
const lli MOD = 1e9+7;

lli gcd(lli a, lli b) { return b == 0 ? a : gcd(b, a % b); }

lli modMult(lli a, lli b) {return ((a%MOD) * (b%MOD))%MOD;}

int main() { _

    int n; cin >> n;
    vi coprimes;

    fore(i, 0, n) {
        if (gcd(i, n) == 1) {
            coprimes.pb(i);
        }
    }

    lli p = 1;
    fore(i, 0, sz(coprimes)) {
        p = modMult(p, coprimes[i]);
    }

    lli mod = p%n;
    print(mod);
    if (mod == 1) {
        cout << sz(coprimes) << endl;
        fore(i, 0, coprimes.size()) {
            cout << coprimes[i] << " ";
        }
        cout << endl;
        return 0;
    }


    cout << sz(coprimes)-1 << endl;
    fore(i, 0, coprimes.size()) {
        if (coprimes[i] != mod) {
            cout << coprimes[i] << " ";
        }
    }
    cout << endl;

	return 0;
}