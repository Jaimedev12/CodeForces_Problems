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

#define oper min
#define NEUT 0
struct STree {
	vector<lli> st;lli n;
	STree(lli n): st(4*n+5,NEUT), n(n) {}
	void init(lli k, lli s, lli e, lli *a){
		if(s+1==e){st[k]=a[s];return;}
		lli m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
        st[k]=st[2*k]+st[2*k+1];
	}
	void upd(lli k, lli s, lli e, lli p, lli v){
		if(s+1==e){st[k]=v;return;}
		lli m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=st[2*k]+st[2*k+1];
	}
	lli query(lli k, lli s, lli e, lli a, lli b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		lli m=(s+e)/2;
        return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void init(lli *a){init(1,0,n,a);}
	void upd(lli p, lli v){upd(1,0,n,p,v);}
	lli query(lli a, lli b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() { _
    lli n, q;
    cin >> n >> q;

    lli array[n];

    fore(i, 0, n) {
        cin >> array[i];
    }

    STree st(n);
    st.init(array);

    fore(i, 0, q) {
        lli a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            st.upd(b, c);
        } else {
            cout << st.query(b, c) << endl;
        }
    }

	return 0;
}