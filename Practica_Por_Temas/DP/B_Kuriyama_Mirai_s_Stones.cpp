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


int main(){ FIN;
    ll n; cin >> n;
    ll m;
    vector<ll> a(n+1);
    
    // one-based
    fore(i, 1, n + 1)
        cin >> a[i];

    cin >> m;

    vector<ll> a_sorted = a;

    sort(all(a_sorted));

    fore(i, 1, n + 1){
        a[i] += a[i-1];
        a_sorted[i] += a_sorted[i-1];
    }

    // fore(i,1,n){
    //     cout 
    //     a[i] += a[i-1];
    //     a_sorted[i] += a_sorted[i-1];
    // }


    fore(i,0,m){
        ll l, r, t; cin >> t >> l >> r;
        if(t == 1)
            print(a[r] - a[l-1]);
        else
            print(a_sorted[r] - a_sorted[l-1]);
    }

    


}