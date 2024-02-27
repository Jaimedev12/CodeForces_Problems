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

bool solve() {
    lli n; cin >> n;

    if (n < 2020) return 0;

    lli div = n/2020;
    lli dif = n%2020;

    if (dif <= div) return 1;
    
    return 0;
}

int main() { _
    int t; cin >> t;
    while(t--) {
        print((solve() ? "YES" : "NO"));
    }

	return 0;
}