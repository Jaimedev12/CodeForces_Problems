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

string s;
vector<int> sums;

void query() {
    int l, r;
    cin >> l >> r;

    if (l == 1) {
        print(sums[r-2]);
        return;
    }

    // print("1: " << sums[r-2]);
    // print("2: " << sums[l-1]);
    // cout << endl;
    print(sums[r-2] - sums[l-2]);
}

int main() { _
    cin >> s;
    sums = vector<int>(s.size());
    if (s[0] == s[1]) {
        sums[0] = 1;
    } else {
        sums[0] = 0;
    }

    fore(i, 1, s.size()-1) {
        sums[i] = sums[i-1];

        if (s[i] == s[i+1]) {
            sums[i]++;
        }
    }
    sums[s.size()-1] = sums[s.size()-2];

    // fore(i, 0, sums.size()) {
    //     cout << sums[i] << " ";
    // } cout << endl;

    int q; cin >> q;
    while (q--) {
        query();
    }

	return 0;
}