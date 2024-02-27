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

void simulate(int h, int w, int x1, int y1, int x2, int y2) {

    int yCasillas = y2-y1-1;
    int winner;
    if (yCasillas % 2 == 0) {
        winner = 1;
    } else {
        winner = 0;
    }

    int turn = 1;
    while (true) {

        if (x1 == x2 && y1 == y2) {
            if (winner == 1) {
                print("Alice");
            } else {
                print("Bob");
            }
            break;
        }

        if (y1 >= y2) {
            print("Draw");
            break;
        }

        if (turn == 1) {
            y1++;
            if (x1 == x2) {
                continue;
            } 

            if (turn == winner) {
                if (x1 > x2) {
                    x1--;
                } else {
                    x1++;
                }
            } else {
                if (x1 > x2) {
                    x1++;
                } else {
                    x1--;
                }
            }
            x1 = min(x1, w);
            x1 = max(x1, 1);
        } else {
            y2--;
            if (x1 == x2) {
                continue;
            } 

            if (turn == winner) {
                if (x1 > x2) {
                    x2++;
                } else {
                    x2--;
                }
            } else {
                if (x1 > x2) {
                    x2--;
                } else {
                    x2++;
                }
            }
            x2 = min(x2, w);
            x2 = max(x2, 1);
        }

        turn++;
        turn %= 2;
    }  
}

void solve() {
    int h, w, x1, y1, x2, y2;
    cin >> h >> w >> y1 >> x1 >> y2 >> x2;
 
    if (y1 >= y2) {
        // print("Already passed");
        print("Draw");
        // print("----------------");
        return;
    }

    simulate(h, w, x1, y1, x2, y2);
    // print("----------------");
}

int main() { _

    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}