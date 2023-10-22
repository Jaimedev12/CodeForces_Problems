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

    int n; cin >> n;
    string s; cin >> s;

    vector<vector<char>> mat(n, vector<char>(n, '#'));
    vector<int> dirI = {-1, 0, 1, 0};
    vector<int> dirJ = {0, 1, 0, -1};

    int ptr, curDir, i, j, maxI, minI, maxJ, minJ;

    ptr = 0;
    curDir = 0;
    i = n/2;
    j = n/2;
    maxI = (n/2)+1;
    minI = (n/2)-1;
    maxJ = (n/2)+1;
    minJ = (n/2)-1;

    while (ptr < sz(s)) {
        mat[i][j] = s[ptr];
        ptr++;

        if (i == maxI) {
            curDir++;
            curDir %= 4;
            maxI++;
        }

        if (i == minI) {
            curDir++;
            curDir %= 4;
            minI--;
        }

        if (j == maxJ) {
            curDir++;
            curDir %= 4;
            maxJ++;
        }

        if (j == minJ) {
            curDir++;
            curDir %= 4;
            minJ--;
        }

        i += dirI[curDir];
        j += dirJ[curDir];
    }

    fore(i, 0, n) {
        fore(j, 0, n) {
            if (mat[i][j] != '#') {
                cout << mat[i][j];
            }
        }
    }

    cout << endl;

    return 0;
}
