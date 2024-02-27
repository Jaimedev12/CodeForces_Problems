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

/*
    0 1 2 3 4 5
    4 5

*/

void solve() {
    lli a, b;
    cin >> a >> b;

    lli ans = a;

    // checar el xor de los últimos números después de dividirlos entre 4;

    lli start = ((a)/4)*4;

    lli allXor = 0;
    fore(i, start, a) {
        // print("i: " << i);
        allXor ^= i;
    }

    if (allXor == b) {
        print(ans);
        return;
    }
    
    if ((allXor ^ a) == b) {
        ans += 2;
    } else {
        ans++;
    }

    print(ans);

}

int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}