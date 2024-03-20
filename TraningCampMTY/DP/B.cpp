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
    vector<pii> trees(n);

    fore(i, 0, n) {
        cin >> trees[i].first >> trees[i].second;
    }

    int ans = 1;
    fore(i, 1, n) {
        int coord = trees[i].first;
        int height = trees[i].second;

        if (coord-height > trees[i-1].first) {
            ans++;
            continue;
        }

        if (i == n-1) {
            ans++;
            continue;
        }

        if (coord+height < trees[i+1].first) {
            ans++;
            trees[i].first = coord+height;
            continue;
        }
    }

    print(ans);

	return 0;
}