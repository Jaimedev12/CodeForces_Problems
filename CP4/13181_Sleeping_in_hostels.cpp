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

void solve() {
    vector<int> count(s.size(), INT_MAX);

    int index = 0;
    fore(i, 0, s.size()) {
        if (s[i] == 'X') {
            index = i;
            break;
        }
    }

    int curCount = -1;
    fore(i, index, s.size()) {
        if (s[i] == 'X') curCount = -1;
        else curCount++;
        count[i] = min(count[i], curCount);
    }

    index = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'X') {
            index = i;
            break;
        }
    }

    curCount = -1;
    for (int i = index; i >= 0; i--) {
        if (s[i] == 'X') curCount = -1;
        else curCount++;

        count[i] = min(count[i], curCount);
    }

    // fore(i, 0, s.size()) {
    //     cout << count[i] << " ";
    // } cout << endl;

    int ans = 0;
    fore(i, 0, s.size()) {
        ans = max(ans, count[i]);
    }

    print(ans);

}

int main() { _

    while (getline(cin, s)){
        solve();
    }

	return 0;
}