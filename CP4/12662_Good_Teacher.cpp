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

void query(vector<pair<pair<string, int>, pair<string, int>>> &dp, int pos) {

    bool isKnown = dp[pos-1].first.second == 0;
    if (isKnown) {
        print(dp[pos-1].first.first);
        return;
    }

    bool isInMiddle = (dp[pos-1].first.second == dp[pos-1].second.second);

    if (isInMiddle) {
        cout << "middle of " << dp[pos-1].first.first << " and " << dp[pos-1].second.first << endl; 
        return;
    }

    bool isClosestToTheLeft = dp[pos-1].first.second < dp[pos-1].second.second;

    // print(isClosestToTheLeft);

    if (isClosestToTheLeft) { 
        int distance = dp[pos-1].first.second;
        fore(i, 0, distance) {
            cout << "right of ";
        }

        string name = dp[pos-1].first.first;
        cout << name << endl;
    } 
    else {
        int distance = dp[pos-1].second.second;
        fore(i, 0, distance) {
            cout << "left of ";
        }

        string name = dp[pos-1].second.first;
        cout << name << endl;
    }

    return;
}

int main() { _

    int n; cin >> n;
    vector<string> names(n);
    fore(i, 0, n) {
        cin >> names[i];
    }

    vector<pair<pair<string, int>, pair<string, int>>> dp(n, {{"", 0}, {"", 0}});

    // Fill from left to right ----------------------
    string curName = names[0];
    int curDistance = INT_MAX;
    fore(i, 0, n) {
        if (names[i] != "?") {
            curName = names[i];
            curDistance = 0;
        } 
        
        dp[i].first.first = curName;
        dp[i].first.second = curDistance;
        if (curDistance != INT_MAX){
            curDistance++;
        }
    }


    // Fill from right to left ----------------------
    curName = names[n-1];
    curDistance = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (names[i] != "?") {
            curName = names[i];
            curDistance = 0;
        } 
        
        dp[i].second.first = curName;
        dp[i].second.second = curDistance;
        if (curDistance != INT_MAX){
            curDistance++;
        }
        
    }


    // fore(i, 0, n) {
    //     print(dp[i].first.first << "   " << dp[i].first.second << "      " << dp[i].second.first << "   " << dp[i].second.second);
    // }
    
    // Read Queries
    int q; cin >> q;

    fore(i, 0, q) {
        int pos; cin >> pos;
        query(dp, pos);
    }


	return 0;
}