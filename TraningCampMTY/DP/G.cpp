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

int n, x;
vector<bool> picked;
vector<int> h;
vector<int> s;
int ans = 0;

int mochila (int index, int p) {

    if (index == n || p > x) {
        return 0;
    }

    ans = max(ans, curValue);

    picked[objectIndex] = true;
    int newWeight = curWeight+h[objectIndex];
    int newValue = curValue+s[objectIndex];
    mochila(newWeight, newValue, objectIndex+1);
    picked[objectIndex] = false;

    mochila(curWeight, curValue, objectIndex+1);
}

int main() { _
    cin >> n >> x;

    picked =  vector<bool>(n);
    h = vector<int>(n);
    s = vector<int>(n);

    fore(i, 0, n) {
        cin >> h[i];
    }
    fore(i, 0, n) {
        cin >> s[i];
    }

    mochila(0, 0);
    print(ans);
	return 0;
}