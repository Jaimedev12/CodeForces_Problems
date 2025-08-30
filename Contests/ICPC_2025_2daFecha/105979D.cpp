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

const lli MOD = 1e9 + 7;

lli sumMod(lli a, lli b) {
    return ((a%MOD) + (b%MOD))%MOD;
}

lli multMod(lli a, lli b) {
    return ((a%MOD) * (b%MOD))%MOD;
}


lli find_set(lli v, vi &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(lli a, lli b, vi &parent, vi &size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        parent[b] = a;
        size[a] += size[b];
        // size[b] = size[a];
    }
}


void solve() {
	lli n, e;
    cin >> n >> e;

    map<lli, vi> energyIndex;

    vi energy(n+1);
    fore(i, 1, n+1) {
        cin >> energy[i];
        energyIndex[energy[i]].push_back(i);
    }

    vector<vi> adjList(n+1);
    fore(i, 0, e) {
        lli a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vi parent(n+1);
    fore(i, 1, n+1) {
        parent[i] = i;
    }

    vi size(n+1, 1);
    vi ans(n+1);

    for (auto it = energyIndex.begin(); it != energyIndex.end(); it++) {
        fore(i, 0, (*it).second.size()) {
            lli el = (*it).second[i];
            for (lli adj : adjList[el]) {
                if (energy[adj] <= energy[el]) {
                    union_sets(el, adj, parent, size);
                }
            }
        }
        fore(i, 0, (*it).second.size()) {
            lli el = (*it).second[i];
            ans[el] = size[find_set(el, parent)];
        }

        // print((*it).first << " ");
        // fore(i, 1, n+1) {
        //     cout << parent[i] << " ";
        // }
        // cout << endl;

        // fore(i, 1, n+1) {
        //     cout << size[i] << " ";
        // }
        // cout << endl << endl;

    }

    

    fore(i, 1, n+1) {
        print(ans[i]);
    }

}

int main() { _

    // int t; cin >> t;
    int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}