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

    int k; cin >> k;
    int counter = 0;
    lli num = 18;

    while (true) {
        lli curNum = num;
        int sum = 0;
        while (curNum) {
            sum += curNum % 10;
            curNum /= 10;
        }

        if (sum == 10) {
            counter++;
        }

        if (counter == k) {
            print(num);
            break;
        }

        num++;
    }

	return 0;
}