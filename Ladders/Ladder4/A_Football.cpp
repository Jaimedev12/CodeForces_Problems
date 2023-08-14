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

    string s; cin >> s;

    int cnt1 = 0;
    int cnt0 = 0;

    fore(i, 0, s.length()) {
        if (s[i] == '1') {
            cnt1++;
            cnt0 = 0;
        } else {
            cnt0++;
            cnt1 = 0;
        }

        if (cnt1 >= 7 || cnt0 >= 7) {
            print("YES");
            return 0;
        }
    }

    print("NO");

    return 0;

}