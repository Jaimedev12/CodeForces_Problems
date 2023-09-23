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


vector<vector<int>> adjList;
vector<int> likes;
vector<int> ansF;


vector<int> getLIS(vector<int> ans, int num)
{

    int l = likes[num];

    if  (ans.size() == 0) 
    {
        ans.pb(l);
    }
    else if (l > ans.back()) 
    {
        ans.push_back(l);
    } 
    else 
    {
        int low = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
        ans[low] = l;
    }
	
    ansF[num] = ans.size();
	return ans;
}

void solveRecursive(int num, vector<int> ans) {
    ans = getLIS(ans, num);

    fore(i, 0, adjList[num].size()) {
        solveRecursive(adjList[num][i], ans);
    }
}


int main() { _

    int n; cin >> n;
    adjList = vector<vector<int>>(n+1);
    ansF = vector<int>(n+1, 1);
    likes = vector<int>(n+1);

    fore(i, 1, n) {
        int temp; cin >> temp;
        adjList[temp].pb(i+1);
    }

    fore(i, 1, n+1) {
        int temp; cin >> temp;
        likes[i] = temp;
    }

    solveRecursive(1, vector<int>());

    fore(i, 2, n) {
        cout << ansF[i] << " ";
    }
    cout << ansF[n] << endl;
    //cout << endl;

	return 0;
}