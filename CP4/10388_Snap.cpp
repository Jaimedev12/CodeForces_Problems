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

void solve() {
    string jane, john;
    cin >> jane >> john;

    int janeIndx = 0;
    int johnIndx = 0;

    string janeFaceUp = "";
    string johnFaceUp = "";

    fore(i, 0, 1000) {

        janeFaceUp += jane[janeIndx];
        johnFaceUp += john[johnIndx];

        if (johnFaceUp[sz(johnFaceUp)-1] == janeFaceUp[sz(janeFaceUp)-1]) {
            int whoWins = rand()/141%2;

            if (whoWins == 0) { // Jane
                janeFaceUp += johnFaceUp;
                johnFaceUp = "";

                string temp = janeFaceUp;
                reverse(all(temp));

                print("Snap! for Jane: " << temp);
            } else { // John
                johnFaceUp += janeFaceUp;
                janeFaceUp = "";

                string temp = johnFaceUp;
                reverse(all(temp)); 

                print("Snap! for John: " << temp);
            }
        }

        janeIndx++;
        johnIndx++;

        if (janeIndx == jane.size()) {
            reverse(all(janeFaceUp));
            jane = janeFaceUp;
            janeFaceUp = "";
            janeIndx = 0;
        }

        if (johnIndx == john.size()) {
            reverse(all(johnFaceUp));
            john = johnFaceUp;
            johnFaceUp = "";
            johnIndx = 0;
        }

        if (john == "") {
            print("Jane wins.");
            return;
        }

        if (jane == "") {
            print("John wins.");
            return;
        }

    }

    print("Keeps going and going ...");
}

int main() { _

    int t; cin >> t;
    bool first = true;
    while(t--) {

        if (!first) {
            print("");
        }

        first = false;

        solve();
    }

	return 0;
}