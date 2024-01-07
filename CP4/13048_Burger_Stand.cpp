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

bool isValid(string &s, int index) {

    if (s[index] == 'S' || s[index] == 'B' || s[index] == 'D') return 0;

    if (index < s.size()-1 && s[index+1] == 'B') return 0;
    if (index < s.size()-2 && s[index+2] == 'B') return 0; 
    
    if (index < s.size()-1 && s[index+1] == 'S') return 0;
    if (index > 0 && s[index-1] == 'S') return 0;

    return 1;
}

void solve(int caseNum){
    string s;
    cin >> s;

    int ans = 0;
    fore(i, 0, s.size()) {
        ans += isValid(s, i);
    }

    print("Case " << caseNum << ": " << ans);
}

int main() { _

    int t; cin >> t;
    int cnt = 0; 
    while (t--) {
        solve(++cnt);
    }

	return 0;
}