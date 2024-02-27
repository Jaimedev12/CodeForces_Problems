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

    // int n = 1;
    // fore(i, 0, 10) {
    //     n = n << 1;
    //     print(n);
    // }


    int n; cin >> n;
    vector<int> turns(n);

    fore(i, 0, n) {
        cin >> turns[i];
    }

    int ceiling = 1;
    fore(i, 0, 16) {
        ceiling *= 2;
    }
    ceiling--;

    fore(i, 0, ceiling) {
        int curPos = 0;

        int num = 1;
        for (int j = n-1; j >= 0; j--) {
            if ((i & num) > 0) {
                curPos += turns[j];
            } else {
                curPos -= turns[j];
            }
            num = (num << 1);
        }

        // print(curPos);
        if (curPos % 360 == 0) {
            print("YES");
            return 0;
        }
    }

    print("NO");
	return 0;
}