// Jaime Eduardo López Castro
// A00833173

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

struct point {
    int x, y;
    point(){x = 0; y = 0;}
};

double calcDist(point a, point b) {
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int main() { _

    int n; cin >> n;
    vector<point> points(n);

    fore(i, 0, n) {
        cin >> points[i].x >> points[i].y;
    }

    double minAvg = INT_MAX;
    double sumOfDists = 0;

    fore(i, 0, n) {
        sumOfDists = 0;
        fore(j, 0, n) {

            if (i == j) continue;

            sumOfDists += calcDist(points[i], points[j]);
        }
        minAvg = min(minAvg, (sumOfDists/(n-1)));
    }

    print(fixed << setprecision(9) << minAvg);
    return 0;    

}
