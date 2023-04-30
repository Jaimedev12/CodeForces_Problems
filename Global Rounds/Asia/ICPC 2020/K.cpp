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

int TP = 0, TN = 0, FP = 0, FN = 0;

int main() { _

    int n; cin >> n;
    vector<pair<int, string>> vec(n);
    int temp1; char temp2;

    for (int i = 0; i < n; i++) {
        cin >> temp2 >> temp1;
        vec[i] = make_pair(temp1, temp2);
    }

    //sort(vec.begin(), vec.end()); // O(nlogn)

    /*
    for (int i = 0; i < n; i++) {
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    */

    int theta = calcOptimalTheta();
    
    for () {

    }

    



}   



