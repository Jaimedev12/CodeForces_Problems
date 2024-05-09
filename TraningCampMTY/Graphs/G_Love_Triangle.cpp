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
    vector<vector<int>> leGusto(n);
    vector<int> meGusta(n);

    int plane;
    fore(i, 0, n) {
        cin >> plane;
        plane--;
        meGusta[i] = plane;
        leGusto[plane].push_back(i);
    }

    fore(i, 0, n) {
        int crush = meGusta[i];
        int crushOfCrush = meGusta[crush];
        
        for(auto pretendiente: leGusto[i]) {
            if (pretendiente == crushOfCrush) {
                print("YES");
                return 0;
            }
        }

    }

    print("NO");
	return 0;
}