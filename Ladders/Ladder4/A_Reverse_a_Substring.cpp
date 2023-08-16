#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
typedef vector<vi> vvi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

int main() { _

    int n; cin >> n;
    string s; cin >> s;

    int l = 0, r = 0;
    char curMax = s[0];
    //print(curMax);

    while(r < n) {
        //print("r: " << r << " l: " << l);
        if (s[l] > s[r]) {
            print("YES");
            print(l+1 << " " << r+1);
            return 0;
        }

        if (s[r] > curMax) {
            l = r;
            curMax = s[r];
        }

        r++;
    }

    print("NO");

    return 0;

}