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

void solve(string first, string second, int n) {

    for (int i = 0; i < n/2; i++) {
        if (second[i] != first[(n/2)-i-1]) { 
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}


int main() { _
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; cin >> t;

    while (t--) {

        vector<string> vs(2);
        int index = 0;

        int n; cin >> n;
        string s;

        for (int i = 0; i < 2*n-2; i++) {
            cin >> s;

            if (s.length() == n/2) {
                vs[index] = s;
                index++;
            } 
        }

        string first, second;

        if (vs[0][0] == vs[1][(n/2)-1]) {
            first = vs[1]; second = vs[0];
        } else {
            first = vs[0]; second = vs[1];
        }

        solve(first, second, n);

        
 

    }
    
}   
