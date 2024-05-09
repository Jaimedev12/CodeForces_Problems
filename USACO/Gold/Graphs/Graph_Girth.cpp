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

int main() { _
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1, INT_MAX);
    fore(i, 0, m) {
        int a, b;
        cin >> a >> b,
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;
    int ans = INT_MAX;
    
    fore(i, 1, n+1) {
        if (dist[i] != INT_MAX) continue;
        q.push(i);
        dist[i] = 0;
        int prev;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto t : adj[x]) {
                if (dist[t] != INT_MAX) {
                    cout << x << ": " << dist[x] << "   " << t << ": " << dist[t] << endl;
                    ans = min(ans, (dist[x]-dist[t]));
                    continue;
                }
                dist[t] = dist[x]+1;
                q.push(t);
            }
        }
    }

    print(ans);

    fore(i, 1, n+1) {
        if (dist[i] == INT_MAX) {
            cout << "- ";
            continue;
        } 

        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}