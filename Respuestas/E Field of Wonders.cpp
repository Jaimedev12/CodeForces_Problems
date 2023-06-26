// Plantilla de Tsurus Tuneados

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


///-------------------------------------------------------------------------
///-------------------------------------------------------------------------

const lli MOD = 1e9 + 7;

///-------------------------------------------------------------------------

lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}

int main() { _

    int n; cin >> n;
    string s; cin >> s;

    int m; cin >> m;
    vector<string> known(m);

    for (int i = 0; i < m; i++) {
        cin >> known[i];
    }

    vector<bool> presentLetters(26);

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') continue;

        presentLetters[s[i] - 'a'] = true;
    }
    
    int ans = 0;

    // curLetter (a, b, c ...)
    for (int i = 0; i < 26; i++) {
        if (presentLetters[i]) continue;

        // cur missing letter in s
        bool allFound = 1;
        for (int j = 0; j < n; j++) {
            if (s[j] != '*') continue;


            // cur known word
            bool found = 0;
            bool foundIn = 0;
            for (int k = 0; k < m; k++) {
                foundIn = 0;
                if (known[k][j] - 'a' == i) {
                    found = true;
                }

                for (char c : known[k]) {
                    if (c - 'a' != i) continue;

                    foundIn = 1;
                }

                if (!foundIn) {
                    break;
                }
            }

            allFound &= found;
            allFound &= foundIn;

            if (allFound == false) {
                break;
            }

        }

        if (allFound) {
            cout << i << endl;
            ans++;
        }

    }

    cout << endl;
    cout << ans << endl;


    
}   
