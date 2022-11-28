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

bool isLucky(int num) {
    string s = to_string(num);

    for (char c : s) {
        if (!(c == '4') && !(c == '7')) {
            return false;
        }
    }

    return true;

}

int main() { _
    
    int N; cin >> N;

    for (int num = 1; num <= N; num++) {

        if (isLucky(num) && (N % num == 0)) {
            cout << "YES" << endl;
            return 0;
        }

    }

    cout << "NO" << endl;

}   
