// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics

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

/*
              .
    1 2 3 4 5 4 3 2 1

*/

lli valueOfPos(lli pos, lli k) {

    if (pos <= k) {
        return (pos*(pos+1))/2;
    } else {
        lli sum = (k*(k+1))/2;
        sum += ((k-1)*(k))/2;
        lli sobrante = pos-k;
        sum -= ((k-1-sobrante)*(k-sobrante))/2;
        return sum;
    }
}

void solve() {
    lli k, x;
    cin >> k >> x;

    lli l = 1;
    lli r = k+(k-1);
    lli ans = 1;

    int cnt = 10;
    while (l < r) {
        lli mid = (l + r)/2;
        print("l: " << l << "    r: " << r);
        print("mid: " << mid);
        print("value: " << valueOfPos(mid, k));
        cout << endl;

        if (valueOfPos(mid, k) >= x && valueOfPos(mid-1, k) < x) {
            if (mid == l) {
                l++;
                ans = l;
                continue;
            }
            l = mid;
            ans = mid;        
        }
        else if (valueOfPos(mid, k) < x) {
            if (mid == l) {
                l++;
                ans = l;
                continue;
            }
            l = mid;
            ans = mid;
        } else {
            r = mid;
        }
    }

    // cout << endl;
    print(ans);

}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}