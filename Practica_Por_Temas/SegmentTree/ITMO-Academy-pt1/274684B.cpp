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


struct node {
    lli a, b, c, d;
};

lli modMult (lli a, lli b, lli mod) {
    return ((a%mod)*(b%mod))%mod;
}

lli modSum (lli a, lli b, lli mod) {
    return ((a%mod)+(b%mod))%mod;
}

node merge (node a, node b, lli r) {
    node ans;

    ans.a = modSum(modMult(a.a, b.a, r), modMult(a.b, b.c, r), r);
    ans.b = modSum(modMult(a.a, b.b, r), modMult(a.b, b.d, r), r);
    ans.c = modSum(modMult(a.c, b.a, r), modMult(a.d, b.c, r), r);
    ans.d = modSum(modMult(a.c, b.b, r), modMult(a.d, b.d, r), r);

    return ans;
}

void printMat(node mat) {
    print(mat.a << " " << mat.b);
    print(mat.c << " " << mat.d);
}

#define oper merge
#define NEUT {1, 0, 0, 1}
struct STree { // segment tree for min over integers
	vector<node> st;
	lli n;
    lli r;
	STree(lli n, lli r) : st(4 * n + 5, NEUT), n(n), r(r) {}
	void init(lli k, lli s, lli e, node *a) {
		if (s + 1 == e) {
			st[k] = a[s];
			return;
		}
		lli m = (s + e) / 2;
		init(2 * k, s, m, a);
		init(2 * k + 1, m, e, a);
		st[k] = oper(st[2 * k], st[2 * k + 1], r);
	}
	node query(lli k, lli s, lli e, lli a, lli b) {

		if (s >= b || e <= a)
			return NEUT;
		if (s >= a && e <= b)
			return st[k];
		lli m = (s + e) / 2;
        node nodeLeft = query(2 * k, s, m, a, b);
        node nodeRight = query(2 * k + 1, m, e, a, b);

        node mergedMat = oper(nodeLeft, nodeRight, r);
		return mergedMat;
	}
    void printST(lli k, lli s, lli e) {
		if (s+1 == e){
            printMat(st[k]);
            cout << endl;
            return;
        }
		
        lli m = (s+e)/2;
        printST(2 * k, s, m);
        printST(2 * k + 1, m, e);
    }
    void printST() {printST(1, 0, n); };
	void init(node *a) { init(1, 0, n, a); }
	node query(lli a, lli b) { 
        node ans = query(1, 0, n, a, b);
        return ans; 
    }
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() { _

    lli r, n, q;
    cin >> r >> n >> q;

    node arr[n];
    fore(i, 0, n) {
        lli a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = {a, b, c, d};
        // print("a: " << arr[i].a << "  b: " << arr[i].b << "  c: " << arr[i].c << "  d: " << arr[i].d);
    }

    STree st(n, r);
    st.init(arr);

    fore(i, 0, q) {
        lli a, b;
        cin >> a >> b;

        node ans = st.query(a-1, b);

        print(ans.a << " " << ans.b);
        print(ans.c << " " << ans.d);
        cout << endl;
    }

	return 0;
}