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

const lli MOD = 1e9 + 7;

lli sumMod(lli a, lli b) {
    return ((a%MOD) + (b%MOD))%MOD;
}

lli multMod(lli a, lli b) {
    return ((a%MOD) * (b%MOD))%MOD;
}


void solve() {
	lli n, q;
    cin >> n >> q;

    string s; cin >> s;

    vector<vi> prefs(n+1, vi(30));
    prefs[0][s[0]-'a'] = 1;
    

    fore(i, 1, n) {
        prefs[i][s[i]-'a']++;
        fore(j, 0, 30) {
            prefs[i][j] += prefs[i-1][j];
        }
    }

    // fore(i, 0, n) {
    //     fore(j, 0, 30) {
    //         cout << prefs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    fore(i, 0, q) {
        lli start, end; cin >> start >> end;
        start--;
        end--;
        char c; cin >> c;
        lli cNum = c-'a';

        lli ans = 0;

        // print("Start y end: " << start << " " << end << " " << cNum);

        // Trasladar
        lli origDif = end-start;
        start %= n;
        // if (start == 0) start = 1;
        end = start + origDif;

        // print("Start y end: " << start << " " << end << " " << cNum);

        // 1 a start
        // ans += prefs[end][cNum];

        // start a n
        if (n-1 > end) {
            if (start == 0) {
                ans += prefs[end][cNum];
            } else {
                ans += prefs[end][cNum] - prefs[start-1][cNum];
            }
        } else {
            if (start == 0) {
                ans += prefs[n-1][cNum];
            } else {
                ans += prefs[n-1][cNum] - prefs[start-1][cNum];
            }
        }

        // print("Ans1: " << ans);
        

        if (end < n) {
            print(ans);
            continue;
        }

        // // Secciones enteras
        ans += ((end-n)/n) * prefs[n-1][cNum];
        // print("Ans2: " << ans);

        // // Parte final
        end %= n;
        ans += prefs[end][cNum];
        // print("Ans3: " << ans);

        print(ans);
    }
}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}