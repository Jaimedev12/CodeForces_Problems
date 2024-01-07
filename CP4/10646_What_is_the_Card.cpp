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

int getValue(string c) {
	if (c[0]-'0' < 17) return c[0]-'0';
	return 10;
}

string solve() {
	vector<string> cards(52);
	fore(i, 0, 52) {
		cin >> cards[i];
	}

	int pileTopIndx = 26;
	int y = 0;
	fore(i, 0, 3) {
		int value = getValue(cards[pileTopIndx]);
		y += value;
		pileTopIndx -= 1+(10-value);
	}

	// print("FinalTopIndx: " << pileTopIndx);
	// print("TopCard: " << cards[pileTopIndx]);
	// print("Y: " << y);
	// print("Cards[26]: " << cards[27]);

	if (y-1 <= pileTopIndx) {
		return cards[y-1];
	} else {
		y -= pileTopIndx+1;
		return cards[y+26];
	}

}

int main() { _

	int t; cin >> t;
	int cnt = 0;

	while (t--) {
		cnt++;
		print("Case " << cnt << ": " << solve());
	}

	return 0;
}