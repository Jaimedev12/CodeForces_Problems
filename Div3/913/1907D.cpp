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
vector<int> l(n);
vector<int> r(n);

bool isValidK(int k) {

    int x1 = 0;
    int x2 = 0;

    fore(i, 0, n) {
        x1 = max(l[i], x1-k);
        x2 = min(r[i], x2+k);
        if (x2 < x1) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    l = vector<int>(n);
    r = vector<int>(n);

    fore(i, 0, n) {
        cin >> l[i] >> r[i];
    }

    int low = 1;
    int high = 10e9;

    while (low+1 < high) {
        int mid = (low + high) / 2;
        if (isValidK(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    print(high);

    return;
}

int main() { _
    int t; cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}