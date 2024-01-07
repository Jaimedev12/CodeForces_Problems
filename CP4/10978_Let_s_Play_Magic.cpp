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

int n;
int numFilledTiles;

void placeCard(vector<string> &vec, vector<bool> &filled, string card, string word, int &index) {
    int placesToTrav = word.size()-1;
    // print("Start: " << index);

    while (placesToTrav--) {
        // Next empty spot
        index++;
        index %= n;
        while (filled[index]) {
            index++;
            index %= n;   
        }
    }

    // print("End: " << index);
    // print(vec[10]);
    // print(filled[10]);
    // cout << endl;
    vec[index] = card;
    filled[index] = true;
    numFilledTiles--;

    // fore(i, 0, n) {
    //     cout << filled[i] << " ";
    // }cout << endl;

    // Next empty spot
    index++;
    index %= n;
    while (filled[index] && numFilledTiles) {
        index++;
        index %= n;   
    }
}

void solve() {
    vector<string> ansVec(n);
    vector<bool> filled(n, 0);
    int index = 0;
    numFilledTiles = n;

    fore(i, 0, n) {
        string card, word;
        cin >> card >> word;
        placeCard(ansVec, filled, card, word, index);
    }

    fore(i, 0, n-1){
        cout << ansVec[i] << " ";
    } print(ansVec[n-1]);
}

int main() { _

    while (cin>>n, n) {
        solve();
    }

	return 0;
}