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

    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() != s2.length()) {
        print("NO");
        return 0;
    }

    vi vec1(30, 0);
    vi vec2(30, 0);

    int numDifs = 0;

    fore(i, 0, s1.length()) {
        if (s1[i] != s2[i]) {
            numDifs++;
            if (numDifs > 2) {
                print("NO");
                return 0;
            }
        }
        vec1[s1[i]-'a']++;
        vec2[s2[i]-'a']++;
    }

    fore(i, 0, 30) {
        if (vec1[i] != vec2[i]) {
            print("NO");
            return 0;
        }
    }

    print("YES");
    return 0;
}