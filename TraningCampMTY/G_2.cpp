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
  
typedef pair<lli, lli> iPair; 
  
class Graph { 
    lli V; 
    list<pair<lli, lli> >* adj; 
  
public: 
    Graph(lli V);
  
    void addEdge(lli u, lli v, lli w); 
  
    void shortestPath(lli s); 
}; 
  
Graph::Graph(lli V) { 
    this->V = V; 
    adj = new list<iPair>[V]; 
} 
  
void Graph::addEdge(lli u, lli v, lli w) { 
    adj[u].push_back(make_pair(v, w)); 
} 
  
void Graph::shortestPath(lli src) { 
    priority_queue<iPair, vector<iPair>, greater<iPair> > 
        pq; 
  
    vector<lli> dist(V, LONG_LONG_MAX); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) { 
        lli u = pq.top().second; 
        pq.pop(); 
  
        list<pair<lli, lli> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
            lli v = (*i).first; 
            lli weight = (*i).second; 
  
            if (dist[v] > dist[u] + weight) { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    for (lli i = 0; i < V; ++i) 
        printf("%lld%c", dist[i], " \n"[i==V-1]); 
} 
  
int main() { 
    lli n, m; 
    cin >> n >> m;
    Graph g(n);

    fore(i, 0, m) {
        lli a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a-1, b-1, c);
    }
  
    g.shortestPath(0);
    return 0; 
}