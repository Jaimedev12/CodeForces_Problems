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

    int k; cin >> k;
    string s; cin >> s;

    vi vec(26);

    fore(i, 0, s.length()) {
        vec[s[i]-'a']++;
    }

    fore(i, 0, vec.size()) {
        if (vec[i]%k != 0) {
            print(-1);
            return 0;
        }

        vec[i] = vec[i]/k;
    }

    fore(i, 0, k) {
        fore(j, 0, vec.size()) {
            fore(k, 0, vec[j]) {
                cout << char(j+'a');
            }
        }
    }

    cout << endl;

    return 0;

}