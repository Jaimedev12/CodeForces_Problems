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
typedef vector<vi> vvi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

/*
    Complejidad Temporal:
    O(n * m)

    Complejidad de Espacio: 
    O(n * m)

    n = longitud del primer string
    m = longitud del segundo string
*/

int main() { _

    int t; cin >> t;
    int curT = 1;

    while (curT <= t) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.length();
        int n2 = s2.length();

        vvi mat(n1+1, vi(n2+1, 0));

        lli ans = 0;

        fore(i, 1, n1+1) {
            fore(j, 1, n2+1) {
                if (s1[i-1] == s2[j-1]) {
                    mat[i][j] = mat[i-1][j-1]+1;
                    ans = max(ans, mat[i][j]);
                } else {
                    mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
                }
            }
        }      

        print("Case " << curT << ": " << ans);

        curT++;
    }

    return 0;

}