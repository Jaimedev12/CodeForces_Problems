#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

int n;
vector<vector<int>> adj;
vector<vector<int>> dp;

int solve(int curNode, int prevNode) {
    int curDist = 0;
    if (dp[curNode][prevNode] != -1) return dp[curNode][prevNode];
    for(auto nextNode : adj[curNode]) {
        if (nextNode == prevNode) continue;
        curDist = max(curDist, 1 + solve(nextNode, curNode));
    }
    return dp[curNode][prevNode] = curDist;
}

int main() { _

    cin >> n;
    adj.resize(n);
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    int from, to;
    fore(i, 0, n-1) {
        cin >> from >> to;
        from--;
        to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int ans = 0;

    fore(i, 0, n) {
        ans = max(ans, solve(i, i));
    }
    print(ans);
    return 0;
}