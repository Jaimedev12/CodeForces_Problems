#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) write << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

int main() { 

    ifstream read("blocks.in");
    ofstream write("blocks.out");

    int n; read >> n;
    vector<int> cntFinal(26, 0);

    // por cada par de palabrazs
        // Crear conteo por palabra
        // Crear el conteo combinado
            // Añadir el conteo combinado al conteo final

    fore(i, 0, n) {
        vector<int> cntComb(26, 0);
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        string s1, s2;
        read >> s1 >> s2;

        fore(j, 0, s1.length()) {
            cnt1[s1[j]-'a']++;
        }

        fore(j, 0, s2.length()) {
            cnt2[s2[j]-'a']++;
        }

        // Conteo combinado
        fore(j, 0, 26) {
            cntComb[j] = max(cnt1[j], cnt2[j]);
            cntFinal[j] += cntComb[j];
        }

    }

    fore(i, 0, 26) {
        print(cntFinal[i]);
    }


	return 0;
}