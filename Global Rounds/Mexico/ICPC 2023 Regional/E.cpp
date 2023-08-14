// Plantilla de Tsurus Tuneados

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
typedef pair<int, pair<int, int>> intTruple;

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

void printVector(vector<bool> vec) {
    for (auto i: vec) {
        cout << i << " ";
    }

    cout << endl;
}

int remaining(int n, vector<bool>& pieces) {
    int l = 0, r = n;

    while (l < r) {
        if (!pieces[l] && !pieces[r]) {
            if (l != 0) pieces[l] = true;
            pieces[r] = true;
            return 0;
        }
        l++;
        r--;
    }

    for (int i = n; i > 0; i--) {
        if (!pieces[i])  {
            pieces[i] = true;
            return n-i;
        }
    }

    return n;
    
}

int main() { _

    int N, K, E;
    cin >> N >> K >> E;

    int left = E, right = N-K-E;

    vector<bool> pieces(N+1);

    pieces[K] = true;

    // cout << "Left: " << left << endl;
    // cout << "Right: " << right << endl;
    // printVector(pieces);

    int ans = 0;
    int remain1 = remaining(left, pieces);
    ans += remain1;
    // cout << "Remain1: " << remain1 << endl;
    // cout << "Pieces" << endl;
    // printVector(pieces);

    int remain2 = remaining(right, pieces);
    ans += remain2;
    // cout << "Remain2: " << remain2 << endl;
    // cout << "Pieces" << endl;
    // printVector(pieces);


    cout << ans << endl;

    return 0;
      
}   
