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

int n;
int numGame = 0;

void solve() {
    print("Game " << numGame << ":");

    vector<int> code(n);
    vector<int> guess(n);
    vector<int> numCnt(10);

    fore(i, 0, n) {
        cin >> code[i];
        numCnt[code[i]]++;
    }

    while (true) {

        vector<int> cntCopy = numCnt;
        int a = 0, b = 0;

        fore(i, 0, n) {
            cin >> guess[i];
        }

        if (guess[0] == 0) break;

        fore(i, 0, n) {
            if (code[i] == guess[i]) {
                cntCopy[code[i]]--;
                a++;
            } 
        }

        fore(i, 0, n) {
            if (code[i] != guess[i] && cntCopy[guess[i]] != 0) {
                cntCopy[guess[i]]--;
                b++;
            }
        }

        print("    (" << a << "," << b << ")");
    }

    return;   
}

int main() { _

    while (cin >> n, n) {
        numGame++;
        solve();
    }

	return 0;
}