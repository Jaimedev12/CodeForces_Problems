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

/*
5 3
1 2
1 3
4 5
*/

int main() { _

	int n,m, a, b;
	cin>>n>>m;

    vector<vector<int>> adjList(n+1);

	fore(i,0,m){
		cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
	}
	
	queue<int> q;
    vector<bool> visited(n+1);
    vector<int> distance(n+1);

    fore(i, 1, n+1) {
        if (visited[i]) continue;
        visited[i] = true;
        distance[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            // process node s
            for (auto u : adjList[s]) {
                if (visited[u]) {
                    if (distance[u]%2 != (distance[s]+1)%2) {
                        print("IMPOSSIBLE");
                        return 0;
                    }
                    continue;
                };
                visited[u] = true;
                distance[u] = distance[s]+1;
                q.push(u);
            }
        }
    }
	
    fore(i, 1, n+1) {
        cout << (distance[i]%2)+1 << " ";
    }
    cout << endl;

    return 0;
}