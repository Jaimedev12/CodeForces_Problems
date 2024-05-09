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
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]*st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(lazy[k] == 0)return; // if neutral, nothing to do
		st[k]+=(e-s) * lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			int newValue = 1;
			fore(i, s, e) {
				newValue *= v;
			}
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]*st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 1; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b){return st[k];};
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)*query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

void printST(STree &st) {
	print("--- st ---");

	int mult = 1;
	int prints = 0;

	for (int i = 1; i < st.st.size(); i++) {
		cout << st.st[i] << " ";
		prints++;

		if (prints == mult) {
			cout << endl;
			mult *= 2;
			prints = 0;
		}
		
	}	
	cout << endl;

	print("--- lazy ---");

	mult = 1;
	prints = 0;

	for (int i = 1; i < st.lazy.size(); i++) {
		cout << st.lazy[i] << " ";
		prints++;

		if (prints == mult) {
			cout << endl;
			mult *= 2;
			prints = 0;
		}
		
	}	
	cout << endl;
}

int main() { _

    // int arr[] = {5, 5, 10, 5, 5, 5, 0};
	int arr[] = {0, 0, 0, 0, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    STree st(n); // Initialize the segment tree with size n
    st.init(arr); // Build the segment tree with array arr

	printST(st);

    st.upd(0, 3, 5);
	// printST(st);
	cout << endl;
    st.upd(2, 7, 5);
	// printST(st);
	cout << endl;

	// 5 5 10 5 5 5 0
	cout << st.query(0, 1) << endl;
	cout << st.query(0, 2) << endl;
	cout << st.query(0, 3) << endl;
	cout << st.query(0, 4) << endl;
	cout << st.query(0, 5) << endl;
	cout << st.query(0, 6) << endl;
	// printST(st);

	cout << st.query(0, 6) << endl;

    // fore(i, 0, n) {
    //     cout << st.query(i, i+1) << " ";
    // }cout << endl << endl;
	printST(st);

    return 0;

}