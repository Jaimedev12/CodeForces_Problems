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

lli countSetBits(lli n) {
    lli cnt = 0;
    while (n) {
        n &= (n-1);
        cnt++;
    }
    return cnt;
}

int main() { _
    lli n, m, k;
    cin >> n >> m >> k;

    vector<lli> players(m);
    fore(i, 0, m) {
        cin >> players[i];
    }

    
    int ans = 0;
    lli ours; cin >> ours;
    fore(i, 0, m) {
        lli dif = (ours ^ players[i]);
        if (countSetBits(dif) <= k) {
            ans++;
        }
    }

    print(ans);

	return 0;
}