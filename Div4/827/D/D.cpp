// Plantilla de Tsurus Tuneados

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


///-------------------------------------------------------------------------
///-------------------------------------------------------------------------

const lli MOD = 1e9 + 7;

///-------------------------------------------------------------------------

lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}

vi pares[1001];

void solve() {


    int n; cin >> n;

    vi inds[1001];

    fore(i, 0, n) {
        int temp; cin >> temp;
        inds[temp].pb(i);
    }

    lli maxSum = -1;
    fore(i, 1, 1001) {
        for (lli j: pares[i]) {
            if (!inds[i].empty() && !inds[j].empty()) {
                maxSum = max(maxSum, (inds[i].back() + inds[j].back()));
            }
        }
    }

    if (maxSum > 0) {
        maxSum += 2;
    }

    cout << maxSum << endl;

}

int main() { _
    
    int T; cin >> T;

    fore (i, 1, 1001) {
        fore (j, 1, 1001) {

            if (mcd(i, j) == 1) {
                pares[i].pb(j);
            }

        }
    }
    
    while (T--) {
        solve();
    }

}   