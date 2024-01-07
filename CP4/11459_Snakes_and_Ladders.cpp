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

void solve() {
    int p, s, d;
    cin >> p >> s >> d;

    vector<int> board(101);
    fore(i, 0, 101) {
        board[i] = i;
    }

    vector<int> positions(p, 1);

    int a, b;
    fore(i, 0, s) {
        cin >> a >> b;
        board[a] = b;
    }

    bool gameover = 0;
    fore(i, 0, d) {
        int tirada;
        cin >> tirada;
        
        if (gameover) continue;

        int index = i%p;
        positions[index] += tirada;
        positions[index] = min(positions[index], 100);
        positions[index] = board[positions[index]];
        positions[index] = min(positions[index], 100);
        
        if (positions[index] == 100) gameover = true;
    }

    fore(i, 0, p) {
        print("Position of player " << i+1 << " is " << positions[i] << ".");
    }

    return;
}

int main() { _
    int t; cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}