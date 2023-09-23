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

int N = ;

struct line {
    long double m, b;

    long double operator()(long double x)
    {
        return m * x + b;
    }
};
 
vector<line> a(N * 4);

void insert(int l, int r, line segment, int idx = 0)
{
	if (l + 1 == r) {
		if (segment(l) > a[idx](l))
			a[idx] = segment;
		return;
	}

	int mid = (l + r) / 2;
	int leftson = idx * 2 + 1, rightson = idx * 2 + 2;

	if (a[idx].m > segment.m)
		swap(a[idx], segment);

	if (a[idx](mid) < segment(mid)) {
		swap(a[idx], segment);
		insert(l, mid, segment, leftson);
	}
	else
		insert(mid, r, segment, rightson);
}

long double query(int l, int r, int x, int idx = 0)
{
	if (l + 1 == r)
		return a[idx](x);

	int mid = (l + r) / 2;
	int leftson = idx * 2 + 1;
	int rightson = idx * 2 + 2;

	if (x < mid)
		return max(a[idx](x), query(l, mid, x, leftson));

	else
		return max(a[idx](x), query(mid, r, x, rightson));
}



int main() { _

    int T; cin >> T;
    vector<pair<int, int>> points(T+1);

    fore(i, 1, T+1) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    int P;
    vector<line>(P+1);

    fore(i, 1, P+1) {
        int m, b;
        cin >> m >> b;
        // add line to the line vector
    }

    // For each point, check por the first line in the line vector 
    // that is strictly greater that the point, that is for point(X,Y) Y < mX + b


	return 0;
}