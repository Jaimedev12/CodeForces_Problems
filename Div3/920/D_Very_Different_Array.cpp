#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long double ld;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(ll i = (a), TT = (b); i < TT; ++i)

/*
    1 2 4 6
    1 2 3 3 5 7

    1 2 3 4 5
    1 2 3 100 100 100 100 100
*/

void solve(){
    int n, m; cin >> n >> m;
    ll ans = 0;
    vector<ll> a(n), b(m);

    fore(i,0,n)
        cin >> a[i];
    fore(i,0,m)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lb = 0;
    int rb = m-1;
    int la = 0;
    int ra = n-1;

    while (la <= ra) {
        ll dif1 = abs(a[la]-b[rb]);
        ll dif2 = abs(a[ra]-b[lb]);

        if (dif1 > dif2) {
            la++;
            rb--;
            ans += dif1;
        } else {
            lb++;
            ra--;
            ans += dif2;
        }
    }
    
    cout << ans << "\n";
}

int main(){ FIN;
    int t; cin >> t;
    while(t--){
        solve();
    }
}