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

// 1 2 3 5 7 8 9 15
// 2 3 4 6 10 11

// 4 6 10 11
// 1 5 7 8 9 15

int n, m;

void solve() {

    // print("n: " << n << " m: " << m);

    vector<int> a(n);
    vector<int> b(m);
    unordered_map<int, int> aMap;
    unordered_map<int, int> bMap;
    fore(i, 0, n) {
        cin >> a[i];
        //print(a[i]);
        aMap[a[i]]++;
    }
    //print("");
    fore(i, 0, m) {
        cin >> b[i];
        //print(b[i]);
        bMap[b[i]]++;
    }
    //print("");

    int aNotHave = 0;
    int bNotHave = 0;

    fore(i, 0, n) {
        if (i != 0 && (a[i] == a[i-1])) continue;
        if (bMap[a[i]] == 0) bNotHave++;
    }

    fore(i, 0, m) {
        if (i != 0 && (b[i] == b[i-1])) continue;
        if (aMap[b[i]] == 0) aNotHave++;
    }

    print(min(aNotHave, bNotHave));
}

int main() { _

    cin >> n >> m;

    while(n+m != 0) {
        solve();
        cin >> n >> m;
    }

	return 0;
}