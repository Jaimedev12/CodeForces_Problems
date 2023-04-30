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

    int n; cin >> n;

    int l, r; cin >> l >> r;

    while (n--) {

        string temp;
        cin >> temp;

        if (temp == "Y") {
            if (l > 0) {
                cout << "Y ";
                l--;
                r++;
            } else {
                cout << "N ";
            }
        } else {
            if (r == 0) {
                cout << "Y ";
                l--;
                r++;
            } else {
                cout << "N ";
            }
        }

        cin >> temp;

        if (temp == "Y") {
            if (r > 0) {
                cout << "Y " << endl;
                r--;
                l++;
            } else {
                cout << "N " << endl;
            }
        } else {
            if (l == 0) {
                cout << "Y " << endl;
                r--;
                l++;
            } else {
                cout << "N " << endl;
            }
        }

    }

}   
