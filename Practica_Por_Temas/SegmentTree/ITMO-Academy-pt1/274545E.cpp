/*
5
5 1 2 2 3 1 3 4 5 4
1 1 1 0 1 0 0 1 0 0

ans:
1 0 0 0 3

1 -> ||
2 -> ||
3 -> |
4 -> ||
5 -> ||
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _                                                                      \
	ios_base::sync_with_stdio(0);                                                \
	cin.tie(0);                                                                  \
	cout.tie(0);

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
#define fore(i, a, b) for (lli i = (a), TT = (b); i < TT; ++i)

lli sum(lli a, lli b) { return a + b; }

#define oper sum
#define NEUT 0
struct STree { // segment tree for min over integers
	vector<lli> st;
	lli n;
	STree(lli n) : st(4 * n + 5, NEUT), n(n) {}
	void init(lli k, lli s, lli e, lli *a) {
		if (s + 1 == e) {
			st[k] = a[s];
			return;
		}
		lli m = (s + e) / 2;
		init(2 * k, s, m, a);
		init(2 * k + 1, m, e, a);
		st[k] = oper(st[2 * k], st[2 * k + 1]);
	}
	void upd(lli k, lli s, lli e, lli p, lli v) {
		if (s + 1 == e) {
			st[k] += v;
			return;
		}
		lli m = (s + e) / 2;
		if (p < m)
			upd(2 * k, s, m, p, v);
		else
			upd(2 * k + 1, m, e, p, v);
		st[k] = oper(st[2 * k], st[2 * k + 1]);
	}
	lli query(lli k, lli s, lli e, lli a, lli b) {

		if (s >= b || e <= a)
			return NEUT;
		if (s >= a && e <= b)
			return st[k];
		lli m = (s + e) / 2;
		return oper(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
	}
	void init(lli *a) { init(1, 0, n, a); }
	void upd(lli p, lli v) { upd(1, 0, n, p, v); }
	lli query(lli a, lli b) { return query(1, 0, n, a, b); }
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() {
	_

	lli n, q;
	cin >> n >> q;

	lli arr[n+1];
	fore(i, 0, n) { arr[i] = 0; }

	STree st(n+1);
	st.init(arr);
	
	fore(i, 0, q)  {
		lli a, b;
		cin >> a >> b;

		if (a == 1) {
			lli c, d;
			cin >> c >> d;
			st.upd(b, d);
			st.upd(c, (-d));
		} else {
			cout << st.query(0, b+1) << endl;
		}
	}
	
	return 0;
}
