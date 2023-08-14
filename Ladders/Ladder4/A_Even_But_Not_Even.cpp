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

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int oddCnt = 0;
        fore(i, 0, s.length()) {
            if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') {
                oddCnt++;
            }
        }

        if (oddCnt <= 1) {
            cout << -1;
        }

        int j = 1;
        fore(i, 0, s.length()) {
            if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') {
                if (j <= 2) {
                    cout << s[i];
                    j++;
                } else {
                    break;
                }
            }
        }

        cout << endl;
    }

    return 0;

}