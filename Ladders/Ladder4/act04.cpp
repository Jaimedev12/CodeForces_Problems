/*
    Jaime Eduardo López Castro
    A00833173
*/

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

/*
    Complejidad de Tiempo:
    O(n * m)

    Complejidad de Espacio:
    O(n * m)
*/

int main() { _

    int n, m;
    cin >> n >> m;

    int costs[n][m];
    int total[n][m];

    fore(i, 0, n) {
        fore(j, 0, m) {
            cin >> costs[i][j];
        }
    }

    total[0][0] = costs[0][0];

    fore(i, 1, m) {
        total[0][i] = total[0][i-1] + costs[0][i];
    }

    fore(i, 1, n) {
        total[i][0] = total[i-1][0] + costs[i][0];
    }


    fore(i, 1, n) {
        fore(j, 1, m) {
            total[i][j] = min(total[i-1][j], total[i][j-1]) + costs[i][j];
        }
    }

    print(total[n-1][m-1]);

    return 0;

}
