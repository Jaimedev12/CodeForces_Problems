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

int merge (int a, int b){
    return a+b;
}

#define oper merge
#define NEUT 0
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p){
		if(s+1==e){st[k]=!st[k];return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p);
		else upd(2*k+1,m,e,p);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void query(int k, int s, int e, int &accum, int &ans){
        
        
        if (ans != -1) return;

        if (st[k] != 0 && s+1 == e) {
            ans = s;
            return;
        }

        int m=(s+e)/2;
        if (st[2*k] < accum) {
            accum -= st[2*k];
            query(2*k+1,m,e,accum,ans);
        } else {
            if (st[2*k+1] != 0 && s+1 == e) ans = s;
            query(2*k,s,m,accum,ans);
        }
	
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p){upd(1,0,n,p);}
	int query(int pos){
        int ans = -1;
        int accum = pos+1;
        query(1,0,n,accum,ans);
        return ans;
    }
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

void printST(STree st) {
    int mult = 1;
    int prints = 0;
    fore(i, 1, st.st.size()){
        cout << st.st[i] << " ";
        prints++;
        if (prints == mult) {
            mult*=2;
            prints = 0;
            cout << endl;
        }
    }
    cout << endl;
}

int main() { _

    int n, q;
    cin >> n >> q;

    int arr[n];
    fore(i, 0, n) {
        cin >> arr[i];
    }

    STree st(n);
    st.init(arr);

    fore(i, 0, q) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            st.upd(b);
        } else {
            print(st.query(b));
        }
    }

	return 0;
}