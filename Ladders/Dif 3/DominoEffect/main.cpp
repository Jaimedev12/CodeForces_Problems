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
    vector<char> vec(n);
    vector<pair<char, int>> pushes;

    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        vec[i] = s[i];

        if (s[i] == 'L' || s[i] == 'R') {
            pushes.push_back(make_pair(s[i], i));
        }
        
    }

    int ans = n;

    if (pushes.size() == 0) {
        cout << ans << endl;
        return 0;
    }

    /*
    if (pushes.size() == 1) {
        if (pushes[0].first == 'L') {
            ans -= pushes[0].second +1;
        } else {
            ans -= (n - pushes[0].second) - 1;
        }

        cout << ans << endl;
        return 0;
    }
    */

    if (pushes[0].first == 'L') {
        ans -= pushes[0].second +1;
    } else if (pushes[pushes.size()-1].first == 'R') {
        ans -= (n - pushes[0].second) - 1;
    }


}   