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
#define NEUT 1e9+7
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}

	void eq(int k, int s, int e, int a, int b, int p, int &dest){
		if(s>=b||e<=a)return;
		if (s+1 == e && st[k] <= p ) {
			upd(s, NEUT);
			dest++;
			return;
		}
		int m=(s+e)/2;
		if (st[k*2] <= p) eq(2*k, s, m, a, b, p, dest);
		if (st[k*2+1] <= p) eq(2*k+1, m, e, a, b, p, dest);
	}
	int eq(int a, int b, int p){
		int ans = 0;
		eq(1, 0, n, a, b, p, ans);
		return ans;
	}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() { _
    int n, q;
    cin >> n >> q;

    int array[n];
    fore(i, 0, n) {
		array[i] = 1e9+7;
    }

    STree st(n);
    st.init(array);

    fore(i, 0, q) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            st.upd(b, c);
        } else {
			int p; cin >> p;
            print(st.eq(b, c, p));
        }
    }

	return 0;
}