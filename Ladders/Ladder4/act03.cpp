/*
    Jaime Eduardo López Castro
    A00833173

    DUDA:
    ¿Solamente es un rango por cada test case?

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
    Complejidad Temporal:
    O(t * n)
    t = número de casos
    n = cantidad de días por caso
*/

int main() { _

    int t; cin >> t;

    while (t--) { // O(t)
        int n; cin >> n;
        int maxDif = 0; 
        int minNum = INT_MAX; 
        int rptr = 0;
        int lptr = 0;
        
        fore(i, 0, n) { //O(n)
            int num; cin >> num;

            if (num < minNum) {
                minNum = num;
                lptr = i+1;
            }

            if (num-minNum > maxDif) {
                maxDif = num-minNum;
                rptr = i+1;
            }
        }

        cout << "Buy in " << lptr << ", sell in " << rptr << endl;

    }

    return 0;

}