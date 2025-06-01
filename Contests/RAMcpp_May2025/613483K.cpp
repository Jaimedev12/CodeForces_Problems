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

vi facts(21);

void solve() {
	lli n; cin >> n;
    string s; cin >> s;

    if (s.length() == 1) {
        print(1);
        return;
    }

    vi letters(30);
    fore(i, 0, n) {
        letters[s[i]-'a']++;
    }

    bool foundOdd = 0;
    lli up = facts[n/2];
    lli down = 1;

    fore(i, 0, 30) {
        bool isOdd = letters[i] % 2 != 0;
        if (isOdd) {
            if (foundOdd) {
                print(0);
                return;
            }

            foundOdd = 1;
            // up--;
            // letters[i]--;
            down *= max(facts[letters[i]/2], 1LL);
            continue;
        }

        down *= max(facts[letters[i]/2], 1LL);
    }
    
    // print("Up: " << up);
    // print("Down: " << down);
    // cout << endl;
    print(up/down);
}

int main() { _

    int t; cin >> t;
    facts[1] = 1;

    fore(i, 2, 20) {
        facts[i] = i*facts[i-1];
    }
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}