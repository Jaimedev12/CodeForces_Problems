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

#define MAXN 2505
#define INF (LLONG_MAX / 3)

int n;
vector<pair<int, int>> g[MAXN]; // u->[(v,cost)]
ll dist[MAXN];
int parent[MAXN];
bool isCycle[MAXN];

void push(int i) {
    isCycle[i] = true;
    for (auto t : g[i]) {
        if (isCycle[t.first])
            continue;
        push(t.first);
    }
}

void bford(int src) { // O(nm)
    fill(dist, dist + n + 1, -INF);
    fill(isCycle, isCycle + n + 1, false);
    dist[src] = 0;
    fore(k, 1, n + 1)
        fore(x, 1, n + 1) if (dist[x] != -INF) for (auto t : g[x]) {
            dist[t.first] = max(dist[t.first], dist[x] + t.second);
        }

    fore(x, 1, n + 1) if (dist[x] != -INF) for (auto t : g[x]) {
        if (dist[t.first] < dist[x] + t.second) {
            push(x);
        }
    }
}

int main()
{
    _

        int m;
    cin >> n >> m;

    fore(i, 1, n + 1)
    {
        parent[i] = 0;
    }

    fore(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        parent[b] = a;
    }

    bford(1);

    if (isCycle[n])
    {
        print(-1);
    }
    else
    {
        print(dist[n]);
    }

    // fore(i, 1, n+1) {
    //     cout << "Parent de " << i << " es " << parent[i] << endl;
    // }

    // cout << endl;
    // for(int i = 1; i <= n; i++) {
    //     cout << "Longest distance from 1 to " << i << ": " << dist[i] << "\n";
    // }

    // fore(i, 1, n+1) {
    //     print(i << " isCycle?: " << isCycle[i]);
    // }

    return 0;
}