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

   4 -> 1
   7 -> 2
   44 -> 3 
   47 -> 4
   74 -> 
   77 -> 5
   444 -> 7
   447 -> 8
   474
   477
   744
   747
   774
   777
*/

int main() { _

    string n; cin >> n;

    lli binNum = 0;

    fore(i, 0, n.size()) {
        binNum = binNum << 1;
        if (n[i] == '7') {
            binNum++;
        } 
    }

    lli prevNums = 1;
    prevNums = prevNums << (n.size());
    prevNums -= 2;

    lli ans = prevNums + binNum +1;
    print(ans);


	return 0;
}