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

    int n, k;
    cin >> n >> k;
    vi cnts(101, 0);
    string pass;

    fore(i, 0, n){
        string s; cin >> s;
        cnts[s.length()]++;
    }
    cin >> pass;

    int minCnt = 0, maxCnt = 0;
    fore(i, 1, pass.length()) {
        minCnt += cnts[i];
        maxCnt += cnts[i];
    }

    maxCnt += cnts[pass.length()];

    cout << 1+minCnt+(minCnt/k)*5 << " " << (maxCnt)+((maxCnt-1)/k)*5 << endl;

    return 0;

}