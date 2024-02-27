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

void solve(){
    ll n; cin >> n;
    vector<ll> a(n+2);
    
    fore(i, 0, n)
        cin >> a[i];


    ll ans = 0;
    ll curMax = a[0];

    fore(i, 1, n){
        if((a[i] < 0 && a[i - 1] < 0) || (a[i] > 0 && a[i - 1] > 0))
            curMax = max(curMax, a[i]);
        else {
            ans += curMax;
            curMax = a[i];
        }
    }

    ans += curMax;

    cout << ans << endl;
}

int main(){ FIN;
    ll t; cin >> t;

    while(t--){
        solve();
    }
}