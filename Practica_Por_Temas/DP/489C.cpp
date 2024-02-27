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

int l, sum;

string getMin() {
    string ans = "1";
    int curSum = 1;
    fore(i, 1, l) {
        ans.push_back('0');
    }

    for (int i = l-1; i >= 0; i--) {

        while (ans[i] != '9') {
            if (curSum == sum) {
                return ans;
            }

            ans[i]++;
            curSum++;
        }
    }

    if (curSum < sum) return "-1";
    return ans;
}

string getMax() {
    string ans = "1";
    int curSum = 1;
    fore(i, 1, l) {
        ans.push_back('0');
    }

    for (int i = 0; i < l; i++) {

        while (ans[i] != '9') {
            if (curSum == sum) {
                return ans;
            }

            ans[i]++;
            curSum++;
        }
    }

    if (curSum < sum) return "-1";
    return ans;
}

int main() { _
    
    cin >> l >> sum;

    if (l > 1 && sum == 0) {
        print(-1 << " " << -1);
        return 0;
    }

    if (l == 1 && sum == 0) {
        print(0 << " " << 0);
        return 0;
    }

    print(getMin() << " " << getMax());

	return 0;
}