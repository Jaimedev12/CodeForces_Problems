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

lli n, m, k, x, y;
lli a, b, c;

void countBottom() {
    lli pregQueFaltan = k%(n*m);
    // print("pregQueFaltan: " << pregQueFaltan);
    lli filasQueSePreguntan = pregQueFaltan/m;
    // print("filasQueSePreguntan: " << filasQueSePreguntan);
    if (x <= filasQueSePreguntan) return;

    pregQueFaltan -= filasQueSePreguntan*m;
    // print("pregQueFaltan: " << pregQueFaltan);
    if (x % 2 == 0) {
        if (x < (m-pregQueFaltan)) return;
    } else {
        if (x > pregQueFaltan) return;
    }

    c++;
}

void countUp() {
    lli pregQueFaltan = k%(n*m);
    lli filasQueSePreguntan = pregQueFaltan/m;
    if (x >= (m-filasQueSePreguntan)) return;

    pregQueFaltan -= filasQueSePreguntan*m;
    if (x % 2 != 0) {
        if (x < (m-pregQueFaltan)) return;
    } else {
        if (x > pregQueFaltan) return;
    }

    c++;
}

int main() { _
    
    cin >> n >> m >> k >> x >> y;

    lli numFilas = k/m;
    lli numReinicios = numFilas/n;
    lli ans = numReinicios;
    a = ans;
    b = ans;
    if (numReinicios*n*m < k) {
        a++;
    }
    c = b;
    if (a == b) {
        print(a << " " << b << " " << c);
        return 0;
    }

    // print("numFilas: " << numFilas);
    // print("numReinicios: " << numReinicios);

    if (numReinicios % 2 == 0) {
        countBottom();
    } else {
        countUp();
    }

    print(a << " " << b << " " << c);

}