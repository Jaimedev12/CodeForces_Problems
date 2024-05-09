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
#define INF 1e8

int n; 
string goal;
unordered_map<string, vector<int>> dp;

void fillDp() {
    dp = {
        {"", vector<int>(n, -1)},
        {"p", vector<int>(n, -1)},
        {"pi", vector<int>(n, -1)},
        {"m", vector<int>(n, -1)},
        {"ma", vector<int>(n, -1)},
    };
}

bool wouldBeValid(string prev, char c) {
    if (prev+c == "map" || prev+c == "pie") {
        return false;
    }
    return true;
}

int solve(string prev, int index, int curAns) {
    while (prev != "" && prev != "p" && prev != "pi" && prev != "m" && prev != "ma") {
        prev = prev.substr(prev.size()-prev.size()+1, prev.size());
    }

    if (index == n) {
        return curAns;
    }

    if (dp[prev][index] != -1) {
        return dp[prev][index];
    }

    int ans = curAns;
    if (wouldBeValid(prev, goal[index])) {
        ans = max(ans, solve(prev+goal[index], index+1, curAns+1));
        // return max(solve(prev+goal[index], index+1, curAns+1), solve(prev, index+1, curAns));
    }

    ans = max(ans, solve(prev, index+1, curAns));

    return dp[prev][index] = ans;

    // return max(curAns, solve(prev, index+1, curAns));
}

int main() { _

    int t; cin >> t;
    while (t--) {
        cin >> n;
        cin >> goal;
        fillDp();
        print(n-solve("", 0, 0));
        // cout << endl;
    }

	return 0;
}