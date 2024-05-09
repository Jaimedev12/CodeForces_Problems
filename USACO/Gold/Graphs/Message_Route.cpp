#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<int> vi;

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
    vi dist(n+1, INT_MAX), parent(n+1);
    vector<vi> adjList(n+1);
    fore(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    queue<int> q;
    dist[1] = 1;
    q.push(1);

    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int el : adjList[x]) {
            if (dist[el] == INT_MAX) {
                dist[el] = dist[x] + 1;
                parent[el] = x;
                q.push(el);
            }
        }
    }
    if (dist[n] == INT_MAX) {
        print("IMPOSSIBLE");
        return 0;
    }

    print(dist[n]);
    vi route{n};
    while(route.back() != 1) route.pb(parent[route.back()]);
    reverse(all(route));
    for (int t : route) cout << t << " ";
    cout << endl;
    
	return 0;
}