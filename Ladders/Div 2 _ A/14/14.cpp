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
    
    string s; cin >> s;
    char c;

    // Erase words at the begginning
    if (s[0] == 'W' && s.size() >= 3) {
        while (s[0] == 'W' && s[1] == 'U' && s[2] == 'B') {
            s.erase(0, 3);
        }
    }

    // Erase words at the end
    int index = s.size() - 1;
    if (s[index] == 'B' && s.size() >= 3) {
        while (s[index] == 'B' && s[index-1] == 'U' && s[index-2] == 'W') {
            s.erase(index-2, index);
        }
    }

    // Check if string has only small words left
    if (s.size() <= 3) {
        cout << s << endl;
        return 0;
    }


    // Eliminate all leftover WUBs
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == 'W' && s.size() > 3) {
            if (s[i+1] == 'U' && s[i+2] == 'B') {
                i += 2;
                cout << ' ';
                continue;
            }
            else {
                cout << s[i];
                continue;
            }
        }

        cout << s[i];

    }
}   
