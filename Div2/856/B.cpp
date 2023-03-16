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

void solve() {

    int n; cin >> n;
    vector<int> vec(n, 0);
    int curNum = 0;

    for (int i = 0; i < n; i++) {
        cin >> curNum;

        if (curNum == 1) {
            vec[i] = 2;
        } else {
            vec[i] = curNum;
        }

    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i+1] % vec[i] == 0) {
            vec[i+1]++;
        } 

    }

    for (auto num : vec) {
        cout << num << " ";
    }

    return;

}


int main() { _
    int t; cin >> t;
    
    while (t--) {
        solve();
        cout << endl;
    }
    
}   
