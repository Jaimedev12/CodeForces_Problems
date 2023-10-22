// Jaime Eduardo López Castro
// A00833173

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

    int n, k; cin >> n >> k;

    vector<int> process(n);
    vector<bool> visited(n, 0);

    fore(i, 0, n) {
        cin >> process[i];
    }

    vector<int> core(k, INT_MAX);

    fore(i, 0, n) {
        cin >> core[i];
    }

    // Asigna trabajo
    int unemployedCores = k;
    fore (i, 0, n) {
        if (unemployedCores == 0) break;
        if (visited[i]) continue;
    
        visited[i] = true;
        core[k-unemployedCores] = process[i];
        unemployedCores--;
    }


    int maxTime = 0;

    while (unemployedCores < k) {
        // Recorre una iteración
        // Actualiza el máximo
        int  minChamba = INT_MAX;
        fore(i, 0, k) {
            minChamba =  min(minChamba, core[i]);
        } 

        maxTime = max(maxTime, minChamba);

        fore(i, 0, k) {
            if (core[i] != minChamba) {
                core[i] -= minChamba;
                continue;
            }

            int searchIndex = lower_bound(all(visited), 0, greater<bool>()) - visited.begin();

            if (searchIndex == n) {
                unemployedCores++;
                core[i] = INT_MAX;
                continue;
            }

            visited[searchIndex] = true;
            core[i] = process[searchIndex];
        }
    }

    print(maxTime);

    return 0;    

}
