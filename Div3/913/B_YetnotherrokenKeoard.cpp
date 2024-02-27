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
    string s;
    cin >> s;

    stack<int> lower;
    stack<int> upper;

    fore (i, 0, s.size()) {

        if (s[i] == 'b') {
            if (lower.empty()) continue;
            lower.pop();
            continue;
        }

        if (s[i] == 'B') {
            if (upper.empty()) continue;
            upper.pop();
            continue;
        }

        if (islower(s[i])){
            lower.push(i);
        } else {
            upper.push(i);
        }
    }

    // print("Lower: " << lower.size());
    // print("Upper: " << upper.size());

    string ans = "";

    while (!lower.empty() || !upper.empty()) {
        while (upper.empty() && !lower.empty()) {
            ans += s[lower.top()];
            lower.pop();
        }

        while (lower.empty() && !upper.empty()) {
            ans += s[upper.top()];
            upper.pop();
        }

        if (lower.empty() && upper.empty()) {
            break;
        }

        if (lower.top() > upper.top()) {
            ans += s[lower.top()];
            lower.pop();
        } else {
            ans += s[upper.top()];
            upper.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    print(ans);
}

int main() { _

    int t;
    cin >> t;

    while (t--) {
        solve();
        // print(t);
    }

	return 0;
}