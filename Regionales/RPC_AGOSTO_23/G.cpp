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

    string n; cin >> n;

    if (n.length() == 1) {
        print(n[0]+1-'0');
        return 0;
    }

    int ans = (n.length()-1)*10;
    ans += n[0]-'0';

    fore(i, 1, n.length()) {

        if (n[i] == n[0]) continue;

        if (n[i] > n[0]) {
            break;
        }

        print(ans-1);
        return 0;

    }

    print(ans);

	return 0;
}