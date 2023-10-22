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

void solveCase() {
	int n; cin >> n;

	int ans;
	cin >> ans;

	if (n == 1) {
		print(ans);
		return;
	}

	vi vec(n-1);

	fore(i, 0, n-1) {
		cin >> vec[i];
	}

	int i = 0;
	int j = 0;
	int numOnes = 0;

	while (j < n) {

		if (vec[i] == 0) {
			i++; j++;
			continue;
		}

		j++;
		numOnes++;

		if (vec[j] == 0 || j == n-1) {
			ans += numOnes/3;
			numOnes = 0;
			i = j;
			continue;
		}
	}

	print(ans);
	return;
}

int main() { _

    int t;
	cin >> t;

	while (t--) {
		solveCase();
	}

	return 0;
}