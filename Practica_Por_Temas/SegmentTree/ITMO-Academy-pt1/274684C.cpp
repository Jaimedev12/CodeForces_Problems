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
    lli arr[41];
    lli prefSum[41];
    lli invers;
    node() {
        fore(i, 0, 41) {
            arr[i] = 0;
        }
        fore(i, 0, 41) {
            prefSum[i] = 0;
        }
        invers = 0;
    }
    node(lli v) {
        fore(i, 0, 41) {
            arr[i] = 0;
        }
        arr[v] = 1;

        fore(i, 0, v) {
            prefSum[i] = 0;
        }
        fore(i, v, 41) {
            prefSum[i] = 1;
        }
        
        invers = 0;
    }
};

node merge(node left, node right) {
    node ans;
    ans.invers = left.invers + right.invers;
    fore(i, 0, 41) {
        lli sumMay = left.prefSum[40] - left.prefSum[i];
        ans.invers += (right.arr[i] * sumMay);
        // fore(j, i+1, 41) {
        //     ans.invers += (left.arr[j]*right.arr[i]);
        // }
    }

    fore(i, 0, 41) {
        ans.arr[i] = left.arr[i]+right.arr[i];
    }

    ans.prefSum[0] = ans.arr[0];
    fore(i, 1, 41) {
        ans.prefSum[i] = ans.prefSum[i-1]+ans.arr[i];
    }

    return ans;
}

#define oper merge
#define NEUT node()
struct STree { // segment tree for min over integers
	vector<node> st;lli n;
	STree(lli n): st(4*n+5,NEUT), n(n) {}
	void init(lli k, lli s, lli e, node *a){
		if(s+1==e){st[k]=a[s];return;}
		lli m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(lli k, lli s, lli e, lli p, lli v){
		if(s+1==e){st[k]=node(v);return;}
		lli m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(lli k, lli s, lli e, lli a, lli b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		lli m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(node *a){init(1,0,n,a);}
	void upd(lli p, lli v){upd(1,0,n,p,v);}
	node query(lli a, lli b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main() { _

    lli n, q;
    cin >> n >> q;

    node arr[n];
    fore(i, 0, n) {
        lli num; cin >> num;
        arr[i] = node(num);
    }

    STree st(n);
    st.init(arr);

    // node ans = st.query(0, 4).invers;
    
    fore(i, 0, q) {
        lli op, a, b;
        cin >> op >> a >> b;

        if (op == 1) {
            node ans = st.query(a-1, b);
            print(ans.invers);
        } else {
            st.upd(a-1, b);
        }
    }

	return 0;
}