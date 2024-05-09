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

struct STree { // example: range sum with range addition
	vector<lli> st,lazy;lli n;
	STree(lli n): st(4*n+5,0), lazy(4*n+5,-1), n(n) {}
	void init(lli k, lli s, lli e, lli *a){
		lazy[k]=-1;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		lli m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push_sum(lli k, lli s, lli e){
		if(lazy[k] == -1)return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
    void push_set(lli k, lli s, lli e){
		if(lazy[k] == -1)return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd_set(lli k, lli s, lli e, lli a, lli b, lli v){
		push_set(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push_set(k,s,e);return;
		}
		lli m=(s+e)/2;
		upd_set(2*k,s,m,a,b,v);upd_set(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
    void upd_sum(lli k, lli s, lli e, lli a, lli b, lli v){
		push_sum(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push_sum(k,s,e);return;
		}
		lli m=(s+e)/2;
		upd_sum(2*k,s,m,a,b,v);upd_sum(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	lli query(lli k, lli s, lli e, lli a, lli b){
		if(s>=b||e<=a)return 0; // operation neutral
		push_sum(k,s,e);
		if(s>=a&&e<=b)return st[k];
		lli m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(lli *a){init(1,0,n,a);}
	void upd_sum(lli a, lli b, lli v){upd_sum(1,0,n,a,b,v);}
    void upd_set(lli a, lli b, lli v){upd_set(1,0,n,a,b,v);}
	lli query(lli a, lli b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main() { _

    lli n, q;
    cin >> n >> q;

    STree st(n);

    fore(i, 0, q) {
        int op; cin >> op;

        if (op == 1) {
            lli l, r, v;
            cin >> l >> r >> v;
            st.upd_set(l, r, v);

        } else if (op == 2) {
            lli l, r, v;
            cin >> l >> r >> v;
            st.upd_sum(l, r, v);

        } else {
            lli l, r;
            cin >> l >> r;
            print(st.query(l, r));
        }

    }

	return 0;
}