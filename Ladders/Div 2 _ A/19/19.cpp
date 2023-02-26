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


int main() { _
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> vecn(n, 0);

    int p; cin >> p;

    while (p--) {
        int i;
        cin >> i;
        i--;
        
        if (vecn[i] == 0) {
            n--;
            vecn[i] = 1;
        }
    }

    int q; cin >> q;

    while (q--) {
        int i;
        cin >> i;
        i--;
        
        if (vecn[i] == 0) {
            n--;
            vecn[i] = 1;
        }
    }

    if (n == 0) {
        cout << "I become the guy." << endl;
    }
    else {
        cout << "Oh, my keyboard!" << endl;
    }

}   
