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

string stringCompression(string s1) {

    if (s1.length() == 0) {
        return s1;
    }

    string posSolution = "";
    posSolution.reserve(s1.length() * 2);
    char curChar = s1[0];
    int curCnt = 0;

    for (int i = 0; i < s1.length(); i++) {

        if (s1[i] == curChar) {
            curCnt++;
        } else {
            posSolution = posSolution + curChar + to_string(curCnt);
            curChar = s1[i];
            curCnt = 1;
        }
    }

    posSolution = posSolution + curChar + to_string(curCnt);

    if (posSolution.length() < s1.length()) {
        return posSolution;
    } else {
        return s1;
    }

}

int main() { _

    string string1;
    cin >> string1;
    cout << stringCompression(string1);

}   