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

vector<bool> isElegible(360, 0);

int main() { _

    int n; cin >> n;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        isElegible[temp] = true;
    }

    int maxNumParejas = 0;
    for (int r = 1; r < 360; r++) {
        int curMaxParejas = 0;
        vector<bool> isElegibleCopy = isElegible;

        for (int i = 0; i < 360; i++) {
            if (isElegibleCopy[i] && isElegibleCopy[(i+r)%360]) {
                curMaxParejas++;
                isElegibleCopy[i] = 0;
                isElegibleCopy[(i+r)%360] = 0;
            }
        }

        maxNumParejas = max(curMaxParejas, maxNumParejas);
    }

    cout << maxNumParejas << endl;
}   






