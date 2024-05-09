#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio (0);cin.tie(0);cout.tie(0);

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
    string s1 = "10001012210110002001010202102011212101210110011100011111111111021211102212020010211112210010111220101010112201001111021012111021101001101000002201020111020120201000111021";
    string s2 = "100010122101100020010102021020112121012101100111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";

    fore(i, 0, s1.size()) {
        if (s1[i] != s2[i]) {
            print(i);
            break;
        }
    }
}