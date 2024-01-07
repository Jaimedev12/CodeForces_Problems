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

    int n;
    cin >> n;
    vector<lli> freq(100010);
    vector<lli> dp(100010);

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        freq[num]++;
    }

    dp[1] = freq[1];

    for (int i = 2; i <= 100010; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + freq[i] * i);
    }

    print(dp[100010]);

	return 0;
}