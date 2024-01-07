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

int n, m;
vector<string> board;
int numField = 0;

int getCount (int i, int j) {
    vector<int> vecI = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> vecJ = {-1, 0, 1, -1, 1, -1, 0, 1};
    int cnt = 0;

    fore(a, 0, 8) {
        int newI = i+vecI[a];
        int newJ = j+vecJ[a];

        bool isInside = newI >= 0 && newI < n && newJ >= 0 && newJ < m;

        if (isInside && board[newI][newJ] == '*') {
            cnt++;
        }
    }

    return cnt;
}

void solve() {
    if (numField != 1) {
        cout << endl;
    }
    print("Field #" << numField << ":");

    board = vector<string>(n);

    fore(i, 0, n) {
        cin >> board[i];
    }
    
    fore(i, 0, n) {
        fore(j, 0, m) {
            //cout << "aver ";
            //cout << getCount(i, j);
            if (board[i][j] == '*') {
                cout << '*';
            } else {
                cout << getCount(i, j);
            }
        } cout << endl;
    }
}

int main() { _

    while (cin >> n >> m, n+m) {
        numField++;
        solve();
    }

	return 0;
}