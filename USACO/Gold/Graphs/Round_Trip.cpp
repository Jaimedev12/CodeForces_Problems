#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

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
#define fore(i, a, b) for (lli i = (a), TT = (b); i < TT; ++i)

int main()
{
    _

        lli n,
        m;
    cin >> n >> m;

    vector<vector<lli>> adj(n + 1);

    fore(i, 0, m)
    {
        lli a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<lli> visited(n + 5);
    vector<lli> parents(n + 5);
    vector<lli> dist(n + 5);

    vector<lli> ida;
    vector<lli> vuelta;

    queue<lli> q;

    // visited[1] = 1;
    // parents[1] = 0;

    // q.push(1);

    fore(i, 1, n + 1)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        parents[i] = 0;
        q.push(i);
        while (!q.empty())
        {
            lli x = q.front();
            q.pop();
            for (lli node : adj[x])
            {
                if (node == parents[x])
                    continue;
                if (visited[node])
                {
                    while (parents[node])
                    {
                        ida.push_back(node);
                        node = parents[node];
                    }
                    ida.push_back(i);

                    while (parents[x])
                    {
                        vuelta.push_back(x);
                        x = parents[x];
                    }
                    vuelta.push_back(i);
					
                    int idaIndex = ida.size()-1;
                    int vueltaIndex = vuelta.size()-1;
                    int borrados = 0;

                    for (; idaIndex > 0 && vueltaIndex > 0; idaIndex--, vueltaIndex--) {
                        if (ida[idaIndex] == vuelta[vueltaIndex] && ida[idaIndex-1] == vuelta[vueltaIndex-1]) {
                            ida[idaIndex] = -1;
                            vuelta[vueltaIndex] = -1;
                            borrados += 2;
                        }
                    }

                    print(ida.size() + vuelta.size() - borrados);

                    for (int i = ida.size() - 1; i >= 0; i--)
                    {
                        if (ida[i] == -1) continue;
                        cout << ida[i] << " ";
                    }

                    fore(i, 0, vuelta.size())
                    {
                        if (vuelta[i] == -1) continue;
                        cout << vuelta[i] << " ";
                    }
                    cout << endl;

                    // fore(i, 0, ida.size()) {
                    //     cout << ida[i] << " ";
                    // }
                    // cout << endl;

                    // fore(i, 0, vuelta.size()) {
                    //     cout << vuelta[i] << " ";
                    // } cout << endl;
                    return 0;
                }
                visited[node] = 1;
                parents[node] = x;
                q.push(node);
            }
        }
    }

    print("IMPOSSIBLE");

    return 0;
}