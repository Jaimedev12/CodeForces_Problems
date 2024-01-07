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

vector<int> her(3), him(2);
vector<bool> available(53);

void solve() {
    fill(all(available), true);
    available[her[0]] = available[her[1]] = available[her[2]] = 0;
    available[him[0]] = available[him[1]] = 0;

    sort(all(her));
    sort(all(him));

    int card = 53;
    
    // Two cards that are greater:
    if (him[0] > her[2]) {
        fore(i, 1, 53) {
            if (available[i] && i < card) {
                card = i;
            }
        }
    }

    if (him[1] > her[2]) {
        fore(i, her[2]+1, 53) {
            if (available[i] && i < card) {
                card = i;
            }
        }
    }

    // Three cards greater than 2 of her cards:
    if (him[0] > her[1]) {
        fore(i, her[1]+1, 53) {
            if (available[i] && i < card) {
                card = i;
            }
        }
    }

    print((card == 53 ? -1 : card));
}

int main() { _

    while (cin >> her[0] >> her[1] >> her[2] >> him[0] >> him[1], her[0]) {
        solve();
    }

	return 0;
}