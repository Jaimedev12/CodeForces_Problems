#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long double ld;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) ll(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for (ll i = (a), TT = (b); i < TT; ++i)

int main()
{
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> request(n);
    vector<bool> vis(n, false);

    fore(i, 0, n) {
        ll pago, cantidad;
        cin >> cantidad >> pago;
        request[i] = {{cantidad, pago}, i};
    }

    sort(request.begin(), request.end());

    ll k;
    cin >> k;
    vector<pii> mesa(k);

    fore(i, 0, k)
    {
        cin >> mesa[i].first;
        mesa[i].second = i;
    }

    sort(mesa.begin(), mesa.end());

    ll numMesas = 0;
    ll suma = 0;
    vector<pii> relaciones;

    fore(i, 0, k){
        auto it = upper_bound(request.begin(), request.end(), make_pair(make_pair(mesa[i].first, (ll)1000000), (ll)100000));
        it--;
        while (it >= request.begin() && vis[(*it).second]) {
            it--;
        } 

        if (it < request.begin()) continue;
        
        vis[(*it).second] = true;
        suma += (*it).first.second;
        numMesas++;
        relaciones.push_back(make_pair((*it).second+1, mesa[i].second+1));

    }    

    print(numMesas << " " << suma);
    fore(i, 0, relaciones.size()) {
        print(relaciones[i].first << " " << relaciones[i].second);
    }
    return 0;
}