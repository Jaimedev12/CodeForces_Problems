// Jaime Eduardo López Castro
// A00833173

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

    int n; cin >> n;

    vector<lli> first(n);
    vector<lli> second(n);

    vector<int> greaterFir(n, 0);
    vector<int> greaterSec(n, 0);

    fore(i, 0, n) {
        cin >> first[i];
    }

    fore(i, 0, n) {
        cin >> second[i];
    }

    fore (i, 0, n){
        fore(j, 0, n) {
            if (first[i] > second[j]) {
                greaterFir[i]++;
            } else if (first[i] < second[j]) {
                greaterSec[j]++;
            }
        }
    }

    lli sumFir = 0;
    lli sumSec = 0;

    fore(i, 0, n) {
        sumFir += greaterFir[i];
        sumSec += greaterSec[i];
    }

    if (sumFir == sumSec) {
        print("tie");
    } else if (sumFir > sumSec) {
        print("first");
    } else {
        print("second");
    }

    return 0;    

}
