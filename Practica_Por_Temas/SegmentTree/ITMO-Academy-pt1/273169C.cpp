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
    int val, cnt;
};

node merge(node &a, node &b) {
    node ans;

    if (a.val < b.val) {
        ans.val = a.val;
        ans.cnt = a.cnt;
    } 
    else if (a.val > b.val) {
        ans.val = b.val;
        ans.cnt = b.cnt;
    } 
    else {
        ans.val = a.val;
        ans.cnt = a.cnt+b.cnt;
    }

    return ans;
}

#define INF 1000000007
#define oper merge
#define NEUT 1e9+7
struct STree { // segment tree for min over integers
	vector<node> st;int n;
	STree(int n): st(4*n+5), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k].val=a[s]; st[k].cnt = 1;return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k].val=v; st[k].cnt=1;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return {INF, INF};
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
        node node1 = query(2*k,s,m,a,b);
        node node2 = query(2*k+1,m,e,a,b);
		return oper(node1, node2);
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() { _
    int n, q;
    cin >> n >> q;

    int array[n];
    fore(i, 0, n) {
        cin >> array[i];
    }

    STree st(n);
    st.init(array);

    fore(i, 0, q) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            st.upd(b, c);
        } else {
            node ans = st.query(b, c);
            print(ans.val << " " << ans.cnt);
        }
    }

	return 0;
}