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
#define MAXN 505
#define INF (LLONG_MAX / 3)

// fill manually:
// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0
/*
fore(i, 0, n + 1) {
    fore(j, 1, n + 1) {
        g[i][j] = INF;
    }
    g[i][i] = 0;
}
*/
ll g[MAXN][MAXN];
int n;
void floyd() { // O(n^3) . Replaces g with min distances
    fore(k, 1, n + 1) {
        fore(i, 1, n + 1) {
            if (g[i][k] < INF) {
                fore(j, 1, n + 1) {
                    if (g[k][j] < INF) {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
    }
}
bool inNegCycle(int v) { return g[v][v] < 0; }
bool hasNegCycle(int a, int b)
{ // true iff there's neg cycle in between
    fore(i, 0, n) if (g[a][i] < INF && g[i][b] < INF && g[i][i] < 0) return true;
    return false;
}

int main()
{
    _

        int m,
        q;
    cin >> n >> m >> q;

    fore(i, 0, n + 1) {
        fore(j, 1, n + 1) {
            g[i][j] = INF;
        }
        g[i][i] = 0;
    }

    fore(i, 0, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }

    floyd();

    fore(i, 0, q)
    {
        int a, b;
        cin >> a >> b;

        if (g[a][b] == INF && g[b][a] == INF)
        {
            print("-1");
        }
        else
        {
            // print(min(g[a][b], g[b][a]));
            print(g[a][b]);
        }
    }

    return 0;
}
