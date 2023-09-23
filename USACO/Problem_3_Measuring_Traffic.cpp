//#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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
#define forei(i, a, b) for(lli i = (a), TT = (b); i >= TT; --i)

#define N 1e9

int main() { _

	ifstream read("traffic.in");
	ofstream write("traffic.out");

	int n; read >> n;
	int low, high;
	vector<string> segType(n);
	vector<int> mins(n);
	vector<int> maxs(n);

	fore(i, 0, n) {
		read >> segType[i] >> mins[i] >> maxs[i];
		//cout << segType[i] << " " << mins[i] << " " << maxs[i] << endl;
	}

	low = -N;
	high = N;

	forei(i, n-1, 0) {

		if (segType[i] == "none") {
			low = max(low, mins[i]);
			high = min(high, maxs[i]);
		} else if (segType[i] == "on") {
			low -= maxs[i];
			high -= mins[i];
			low = max(0, low);
		} else {
			low += mins[i];
			high += maxs[i];
		}

	}

	write << low << " " << high << endl;

	low = -N;
	high = N;

	fore(i, 0, n) {

		if (segType[i] == "none") {
			low = max(low, mins[i]);
			high = min(high, maxs[i]);
		} else if (segType[i] == "on") {
			low += mins[i];
			high += maxs[i];
		} else {
			low -= maxs[i];
			high -= mins[i];
			low = max(0, low);
		}

	}

	write << low << " " << high << endl;

	return 0;
}