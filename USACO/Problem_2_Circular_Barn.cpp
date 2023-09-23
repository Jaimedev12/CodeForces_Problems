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
#define print(s) write << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

int main() { _

    ifstream read("cbarn.in");
    ofstream write("cbarn.out");

    int n; read >> n;
    vector<int> vec(n);
    fore(i, 0, n) {
        read >> vec[i];
    }
    int ans = INT_MAX;

    fore(i, 0, n) {
        int curSum = 0;

        fore(j, 1, n) {
            curSum += vec[(i+j)%n]*j;
        }

        ans = min(ans, curSum);
    }

    print(ans);

	return 0;
}