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

vector<lli> dests;
string a, b;

void solve(lli pos, lli index) {
    if (index == b.size()) {
        dests.push_back(pos);
        return;
    }

    if (b[index] == '?') {
        solve(pos-1, index+1);
        solve(pos+1, index+1);
        return;
    }
    
    if (b[index] == '+') {
        solve(pos+1, index+1);
    } else {
        solve(pos-1, index+1);
    }
}

int main() { _
    cin >> a >> b;

    lli target = 0;
    fore(i, 0, a.size()) {
        if (a[i] == '+') {
            target++;
        } else {
            target--;
        }
    }

    solve(0, 0);

    lli numerator = 0;

    fore(i, 0, dests.size()) {
        if (dests[i] == target) numerator++;
    }
    cout << endl;

    // cout << "Numerator: " << numerator << endl;
    // cout << "Denominator: " << dests.size() << endl;

    double ans = ((double)numerator/dests.size());

    cout << setprecision(12) << fixed << ans << endl;

	return 0;
}