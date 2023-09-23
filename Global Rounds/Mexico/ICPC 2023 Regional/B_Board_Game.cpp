#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 7, LOG = 20;
const int N_ = N * LOG, MAX = 1e9;
const long long linf = 9e18;
 
struct line {
    long long m, b;
    long long operator()(long long x) const {
        return m * x + b;
    }
    bool cmp(const line &a, long long x) {
        return (*this)(x) < a(x);
    }
};
 
namespace pli {
    line seg[N_];
    int roots[N], L[N_], R[N_], cnt = 1;

    void insert(int x, line a, int pcur = -1, int p = -1, long long l = -MAX, long long r = MAX) {
		if(pcur == -1) {
            pcur = roots[x] = cnt++;
        }
		
        if(p == -1) {
            p = roots[x - 1];
        }

        seg[pcur] = seg[p];
        L[pcur] = L[p];
        R[pcur] = R[p];
        long long mid = (l + r) >> 1;

        if(seg[p].cmp(a, mid)) {
            seg[pcur] = a;
            a = seg[p];
        }

        if(a.b == -linf) {
            return;
        }

        if(seg[pcur].cmp(a, l) != seg[pcur].cmp(a, mid)) {
            L[pcur] = cnt++;
            insert(x, a, L[pcur], L[p], l, mid - 1);
        } 
		else if(seg[pcur].cmp(a, r) != seg[pcur].cmp(a, mid)) {
            R[pcur] = cnt++;
            insert(x, a, R[pcur], R[p], mid + 1, r);
        }
    }

    long long query(int p, long long x, long long l = -MAX, long long r = MAX) {
        long long mid = (l + r) >> 1;
        long long calc = seg[p](x);

        if(calc == -linf) {
            return calc;
        }

        if(x < mid) {
            return max(calc, query(L[p], x, l, mid - 1));
        } 
		else {
            return max(calc, query(R[p], x, mid + 1, r));
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pli::seg[0] = {0, -linf};

    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n); // points
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) { // Inserting each line
        long long mm, b;
        cin >> mm >> b;
        pli::insert(i, {mm, b}); 
    }

    vector<vector<int>> ans(m + 2);
    for(int i = 0; i < n; i++) {
        int l = 1, r = m, cur = m + 1;
        while(l <= r) {
            //cout << "curDentro1: " << cur << endl;
            int mid = (l + r) >> 1;
            cout << "mid: " << mid << endl;
            cout << "p[i].second: " << p[i].second << endl;
            cout << "QueryResults: " << pli::query(pli::roots[mid], p[i].first) << endl << endl;
            if(p[i].second < pli::query(pli::roots[mid], p[i].first)) {
                cur = mid;
                r = mid - 1;
            } 
			else {
                l = mid + 1;
            }
            //cout << "curDentro2: " << cur << endl;
        }
        cout << "curFuera: " << cur << endl << endl;
        ans[cur].push_back(i + 1);
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i].size() << " ";
        for(auto e : ans[i]) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}