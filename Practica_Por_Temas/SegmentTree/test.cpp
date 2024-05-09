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

struct STree { // range multiplication with range addition
    vector<lli> st, lazy; lli n;
    STree(lli n): st(4*n+5, 1), lazy(4*n+5, 0), n(n) {}
    void init(int k, int s, int e, lli *a){
        lazy[k] = 0;  // lazy neutral element
        if(s+1 == e) {st[k] = a[s]; return;}
        int m = (s+e)/2;
        init(2*k, s, m, a); init(2*k+1, m, e, a);
        st[k] = st[2*k] * st[2*k+1]; // operation
    }
    void push(int k, int s, int e){
        if(!lazy[k]) return; // if neutral, nothing to do
        st[k] *= pow(lazy[k], e-s); // update st according to lazy
        if(s+1 < e) { // propagate to children
            lazy[2*k] += lazy[k];
            lazy[2*k+1] += lazy[k];
        }
        lazy[k] = 0; // clear node lazy
    }
    void upd(int k, int s, int e, int a, int b, lli v){
        push(k, s, e);
        if(s >= b || e <= a) return;
        if(s >= a && e <= b) {
            lazy[k] += v; // accumulate lazy
            push(k, s, e); return;
        }
        int m = (s+e)/2;
        upd(2*k, s, m, a, b, v); upd(2*k+1, m, e, a, b, v);
        st[k] = st[2*k] * st[2*k+1]; // operation
    }
    lli query(int k, int s, int e, int a, int b){
        if(s >= b || e <= a) return 1; // operation neutral
        push(k, s, e);
        if(s >= a && e <= b) return st[k];
        int m = (s+e)/2;
        return query(2*k, s, m, a, b) * query(2*k+1, m, e, a, b); // operation
    }
    void init(lli *a) {init(1, 0, n, a);}
    void upd(int a, int b, lli v) {upd(1, 0, n, a, b, v);}
    lli query(int a, int b) {return query(1, 0, n, a, b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

void printST(STree &st) {
    print("st: ");
    fore(i, 0, st.st.size()) {
        cout << st.st[i] << " ";
    }cout << endl;
    print("lazy: ");
    fore(i, 0, st.lazy.size()) {
        cout << st.lazy[i] << " ";
    }cout << endl;
    cout << endl;
}

int main() { _

    lli arr[] = {0, 0, 0, 0, 0, 0, 0};
    lli n = sizeof(arr)/sizeof(arr[0]);

    STree st(n); // Initialize the segment tree with size n
    st.init(arr); // Build the segment tree with array arr

    printST(st);

    st.upd(0, 3, 5);
    printST(st);
    st.upd(2, 6, 5);
    printST(st);

    fore(i, 0, n) {
        cout << st.query(i, i+1) << " ";
    }cout << endl << endl;;
    printST(st);

    return 0;
}