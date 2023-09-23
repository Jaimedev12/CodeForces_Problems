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

const double EPS = 1e-6;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator == (point other) const {
   return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS)); } 
  bool operator <(const point &p) const {
   return x < p.x || (abs(x-p.x) < EPS && y < p.y); } };

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x-a.x, b.y-a.y); }


double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) < EPS;
}

vector<point> CH_Andrew(vector<point> &Pts) {    // overall O(n log n)
  int n = Pts.size(), k = 0;
  vector<point> H(2*n);
  sort(Pts.begin(), Pts.end());                  // sort the points by x/y
  for (int i = 0; i < n; ++i) {                  // build lower hull
    while ((k >= 2) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
    H[k++] = Pts[i];
  }
  for (int i = n-2, t = k+1; i >= 0; --i) {       // build upper hull
    while ((k >= t) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
    H[k++] = Pts[i];
  }
  H.resize(k);
  return H;
}

int main() {
    
    int n; cin >> n;
    vector<point> P;
    vector<vector<int>> plane (10010, vector<int>(10010, 0));

    // if (n <= 2) {
    //     fore(i, 0, n) {
    //         cout << i+1 << " ";
    //     }
    //     cout << endl;
    //     return 0;
    // }

    fore(i, 0, n) {
        int x, y;
        cin >> x >> y;
        P.emplace_back(x, y);

        if (!plane[x][y]) plane[x][y] = i+1;
    }

    P = CH_Andrew(P);
    vector<int> ans;
    
    fore(i, 0, P.size()-1) {
        //cout << P[i].x << " " << P[i].y << endl;
        ans.emplace_back(plane[P[i].x][P[i].y]);
    }

    sort(all(ans));

    fore(i, 0, ans.size()) {

        if (i > 0) {
            if (ans[i-1] == ans[i])
                continue;
        }
        cout << ans[i] << " ";

    }
    cout << endl;

    return 0;
}