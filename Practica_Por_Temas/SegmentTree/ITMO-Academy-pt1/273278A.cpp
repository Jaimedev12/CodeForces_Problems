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
    lli seg, pref, suf, sum;
};

node merge(node &a, node &b) {
    node ans;

    ans.seg = max(max(a.seg, b.seg), a.suf+b.pref);
    ans.pref = max(a.pref, a.sum+b.pref);
    ans.suf = max(b.suf, b.sum+a.suf);
    ans.sum = a.sum+b.sum;

    return ans;
}

node single(lli v) {
    return {v, v, v, v};
}

#define oper merge
#define NEUT 1e9+7
struct STree { // segment tree for min over lliegers
	vector<node> st;lli n;
	STree(lli n): st(4*n+5), n(n) {}
	void init(lli k, lli s, lli e, lli *a){
		if(s+1==e){st[k]=single(a[s]);return;}
		lli m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(lli k, lli s, lli e, lli p, lli v){
		if(s+1==e){st[k]=single(v);return;}
		lli m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(lli k, lli s, lli e, lli a, lli b){
		if(s>=b||e<=a)return single(INT_MIN);
		if(s>=a&&e<=b)return st[k];
		lli m=(s+e)/2;
        node nodeLeft = query(2*k,s,m,a,b);
        node nodeRight = query(2*k+1,m,e,a,b);
		return oper(nodeLeft, nodeRight);
	}
	void init(lli *a){init(1,0,n,a);}
	void upd(lli p, lli v){upd(1,0,n,p,v);}
	node query(lli a, lli b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() { _

    lli n, q;
    cin >> n >> q;

    lli arr[n];
    fore(i, 0, n) {
        cin >> arr[i];
    }

    STree st(n);
    st.init(arr);

    print(max(st.query(0, n).seg, lli(0)));

    fore(i, 0, q) {
        lli a, b;
        cin >> a >> b;
        st.upd(a, b);
        print(max(st.query(0, n).seg, lli(0)));
    }

	return 0;
}