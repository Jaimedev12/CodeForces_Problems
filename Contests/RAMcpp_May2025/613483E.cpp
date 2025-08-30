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

lli gcd(lli a, lli b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

lli power(lli x, lli y) {
    if (y == 0) return 1;

    lli p = power(x, y / 2) % MOD;
    p = (p * p) % MOD;

    return (y % 2 == 0) ? p : (x * p) % MOD;
}

lli sumMod(lli a, lli b) {
    b += MOD;
    a += MOD;
    return ((a%MOD) + (b%MOD))%MOD;
}

lli multMod(lli a, lli b) {
    return ((a%MOD) * (b%MOD))%MOD;
}

lli modInverse(lli A)
{
    lli g = gcd(A, MOD);
    power(A, MOD - 2);
}


void solve() {
	lli n, x;
    cin >> n >> x;

    vector<vi> dice(n, vi(6));

    fore(i, 0, n) {
        fore(j, 0, 6){
            cin >> dice[i][j];
        }
    }

    unordered_map<lli, lli> groupA;
    fore(i, 0, n/2) {
        if (i == 0) {
            fore(f, 0, 6) {
                groupA[dice[i][f]]++;
            }
            continue;
        }

        unordered_map<lli, lli> tempGroupA = groupA;
        fore(f, 0, 6) {
            lli faceNum = dice[i][f];
            if (faceNum == 1) continue;
            for (auto it = groupA.begin(); it != groupA.end(); it++) {
                lli prod = multMod(faceNum, (*it).first);
                // print(faceNum << " * " << (*it).first << " = " << prod);
                tempGroupA[prod] = sumMod(tempGroupA[prod], (*it).second);
            }
        }
        groupA = tempGroupA;
        // for (auto it = groupA.begin(); it != groupA.end(); it++) {
        //     print((*it).first << ": " << (*it).second);
        // }

    }

    unordered_map<lli, lli> groupB;
    fore(i, n/2, n) {
        if (i == n/2) {
            fore(f, 0, 6) {
                groupB[dice[i][f]]++;

            }
            continue;
        }

        unordered_map<lli, lli> tempGroupB = groupB;
        fore(f, 0, 6) {
            lli faceNum = dice[i][f];
            if (faceNum == 1) continue;
            for (auto it = groupB.begin(); it != groupB.end(); it++) {
                lli prod = multMod(faceNum, (*it).first);
                // print(faceNum << " * " << (*it).first << " = " << prod);
                tempGroupB[prod] = sumMod(tempGroupB[prod], (*it).second);
            }
        }
        groupB = tempGroupB;
    }
    
    lli ans = 0;
    for (auto it = groupA.begin(); it != groupA.end(); it++) {
        if (x % (*it).first != 0) continue;
        // lli lookingFor = x/(*it).first;
        lli lookingFor = multMod(x, modInverse((*it).first));
        // print("ProdA: " << (*it).first << ", " << (*it).second);
        // print("LookingFor: " << lookingFor << " GroupB: " << groupB[lookingFor]);
        ans = sumMod(ans, multMod((*it).second, groupB[lookingFor]));
    }
    print(ans);

}

int main() { _

    int t; cin >> t;
    //int t = 1;

    while (t--) {
        solve();
    }

	return 0;
}