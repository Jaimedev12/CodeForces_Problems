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
    string pos;
    cin >> pos;

    char letter = pos[0];
    int num = pos[1]-'0';

    // print("Letter: " << letter);
    // print("Number: " << num);

    for (int i = 1; i <= 8; i++) {
        if (i == num) continue;
        print(letter << i);
    }

    for (int i = 0; i < 8; i++) {
        if (i == letter-'a') continue;
        print(char('a'+i) << num);
    }
}

int main() { _
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

	return 0;
}