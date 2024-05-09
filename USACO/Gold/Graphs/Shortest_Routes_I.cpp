#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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
#define fore(i, a, b) for(ll i = (a), TT = (b); i < TT; ++i)

#define MAXN 100005

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().second;ll c=-q.top().first;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].first; ll c=g[x][i].second;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

int main() { _

    int n, m;
    cin >> n >> m;

    fore(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
    }

    dijkstra(1);

    fore(i, 1, n+1) {
        cout << dist[i] << " ";
    }
    cout << endl;

	return 0;
}