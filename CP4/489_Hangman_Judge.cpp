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

int curRound;

void solve() {
    print("Round " << curRound);

    string word, guess;
    cin >> word >> guess;

    int failsLeft = 7;

    int lettersLeft = 0;
    vector<bool> lettersVec(30);
    vector<bool> alreadyGuessed(30);
    fore(i, 0, word.size()) {
        if (lettersVec[word[i]-'a'] == false) lettersLeft++;
        lettersVec[word[i]-'a'] = true;
    }

    fore(i, 0, guess.size()) {
        int letterIndx = guess[i]-'a';

        if (alreadyGuessed[letterIndx]) {
            continue;
        }

        if (lettersVec[letterIndx] == true) {
            lettersVec[letterIndx] = false;
            lettersLeft--;
            if (lettersLeft == 0) {
                break;
            }
        } else {
            failsLeft--;
            if (failsLeft == 0) {
                break;
            }
        }

        alreadyGuessed[letterIndx] = true;
    }

    if (failsLeft == 0) {
        print("You lose.");
        return;
    }

    if (lettersLeft == 0) {
        print("You win.");
        return;
    }

    print("You chickened out.");
}

int main() { _

    while (cin >> curRound, curRound != -1) {
        solve();
    }

	return 0;
}