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
#define sz(s) lliss.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(ll i = (a), TT = (b); i < TT; ++i)

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> dp(n);
    vector<bool> visited(1e5+5);

    fore(i,0,n){
        cin >> a[i];
    }

    dp[n-1] = 1;
    visited[a[n-1]] = 1; // Primer elemento visitado

    for(ll i = n - 2; i >= 0; i--){
        ll x = a[i];
        dp[i] = dp[i+1];
        
        if(visited[x])
            continue;

        dp[i]++;
        visited[x] = 1;
    }

    fore(i,0,m){
        ll q; cin >> q;
        cout << dp[q - 1] << endl; 
    }



}