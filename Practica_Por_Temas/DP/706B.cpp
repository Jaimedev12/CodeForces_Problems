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
    vector<int> prices(n);
    fore(i, 0, n){
        cin >> prices[i];
    }
    sort(all(prices));

    int q; cin >> q;
    int num;
    fore(i, 0, q) {
        cin >> num;

        auto iter = upper_bound(all(prices), num);
        if (iter == prices.end()) {
            print(n);
            continue;
        }

        int index = (iter - prices.begin());
        print(index);
    }

	return 0;
}