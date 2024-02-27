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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n+1, -1e10);
    dp[0] = 0;
    for (int i = a; i <= n; i++) dp[i] = max(dp[i], dp[i-a]+1);
    for (int i = b; i <= n; i++) dp[i] = max(dp[i], dp[i-b]+1);
    for (int i = c; i <= n; i++) dp[i] = max(dp[i], dp[i-c]+1);

    print(dp[n]);

	return 0;
}