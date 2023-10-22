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

    string numStr;
    cin >> numStr;
    bool has7;
    bool isDivisible;

    fore(i, 0, numStr.length()) {
        if (numStr[i] == '7') {
            has7 = true;
            break;
        }
    }

    lli num;
    num = stoi(numStr);
    isDivisible = (num%7 == 0 ? 1 : 0);

    if (!has7 && !isDivisible) {
        print(0);
        return 0;
    }

    if (!has7 && isDivisible) {
        print(1);
        return 0;
    }

    if (has7 && !isDivisible) {
        print(2);
        return 0;
    }

    print(3);
    return 0;
}
