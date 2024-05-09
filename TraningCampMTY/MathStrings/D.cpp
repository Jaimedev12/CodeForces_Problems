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

const lli MOD = 1e9+9;

lli modSum(lli a, lli b) {
    return ((a%MOD) + (b%MOD))%MOD;
}

lli modMult(lli a, lli b) {
    return ((a%MOD) * (b%MOD))%MOD;
}

lli modSubs(lli a, lli b) {
    return ((a%MOD) - (b%MOD))%MOD;
}

int main() { _
    
    lli n, m, k;
    cin >> n >> m >> k;

    lli mess = min(n/k, modSubs(n, m));

    print("mess: " << mess);
    lli gastadas = modMult(mess, modSubs(k,1));
    print("gastadas: " << gastadas);
    lli consecs = modSubs(m, gastadas);
    print("consecs: " << consecs);
    lli dups = consecs/k;
    print("dups: " << dups);
    
    lli curScore = 0;

    fore(i, 0, dups) {
        curScore = modSum(curScore, modMult(modSum(curScore, k), 2));
    }

    gastadas = modSum(gastadas, consecs%k);
    curScore = modSum(curScore, gastadas);

    print(curScore);
}

/*

    lli n, m, k;
    cin >> n >> m >> k;

    lli mess = n-m;
    lli gastadas = mess*(k-1);
    lli consecs = m-gastadas;
    lli dups = consecs/k;
    
    lli curScore = 0;

    fore(i, 0, dups) {
        curScore += (curScore+k)*2;
    }

    gastadas += consecs%k;
    curScore += gastadas;


*/