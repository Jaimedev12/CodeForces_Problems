#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

using namespace std;

ll factor(ll n){
    ll ans = 0;
    for (ll i = 2; i * i <= n; i++) {
		ll k = i;
        while (n % k == 0) {
			ans++;
			n /= k;
            k *= i;
		}
        while (n % i == 0) {
			n /= i;
		}
	}

	if (n > 1) { 
        ans++;
    }
    return ans;
}


int main(){ FIN;
    ll n; cin >> n;
    cout << factor(n) << endl;
}