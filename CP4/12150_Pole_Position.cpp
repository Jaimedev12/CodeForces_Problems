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

int n;

bool canSwap(vector<pair<int, int>> &position, int i, int target) {
    if (target < 0 || target >= position.size() || position[target].second == 0) {
        return 0;
    }

    return true;
}

void solve() {
    vector<pair<int, int>> positions(n);

    fore(i, 0, n) {
        cin >> positions[i].first >> positions[i].second;
    }

    fore(i, 0, n) {
        int target = i+(positions[i].second);

        if (target == i) continue;

        if (canSwap(positions, i, target)) {
            positions[i].second -= target-i;
            positions[target].second += target-i;
            swap(positions[i], positions[target]);
            i = min(i-1, (lli)target-1);
        } else {
            print(-1);
            return;
        }
    }

    fore(i, 0, n-1) {
        cout << positions[i].first << " ";
    }
    cout << positions[n-1].first << endl;
}

int main() { _

    while (cin >> n, n) {
        solve();        
    }

	return 0;
}