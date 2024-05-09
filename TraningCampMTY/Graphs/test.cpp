#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int lli;
typedef vector<lli> vi;

#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

int main() { _  // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vi letras(5);
    string palabra = "abcabcaca";

    // En vez de 
    // sort(palabra.begin(), palabra.end())
    // Hago
    sort(all(palabra));

    fore(i, 0, palabra.size()) {
        letras[palabra[i]-'a']++;
    }

    fore(i, 0, 5) {
        print(char(i+97) << " = " << letras[i]);
    }

    return 0;
}