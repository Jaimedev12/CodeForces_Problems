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

#define EPS 10e-9

struct point{
    double x, y;
    point(){x = y = 0.0;}
    point(double _x, double _y) {x = _x; y = _y;}
};

struct line{double a, b, c;};

void pointsToLine(point &a, point &b, line &l) {
    l = {-(double)(a.y-b.y) / (a.x-b.x), 1.0L, -(double)(l.a*a.x) - a.y};
}

double radToDeg(double rad) {
    return (rad * (180.0L/M_PI));
}

bool hasIntersect(const line &l, int r, point &p) {

    // Assuming circle in (0, 0)

    double x0 = - (double)l.a*l.c / (double)(l.a*l.a + l.b*l.b);
    double y0 = - (double)(l.b*l.c) / (double)(l.a*l.a + l.b*l.b);

    if (l.c*l.c > r*r*(l.a*l.a + l.b*l.b) + EPS)
        return false;

    if (fabs(l.c*l.c - r*r*(l.a*l.a + l.b*l.b)) < EPS) {
        p.x = x0;
        p.y = y0;
        return true;
    }
    else {
        double d = r*r - l.c*l.c / (l.a*l.a + l.b*l.b);
        double mult = sqrt ((double)d / (double)(l.a*l.a + l.b*l.b));
        double ax, ay, bx, by;
        ax = x0 + l.b * mult;
        bx = x0 - l.b * mult;
        ay = y0 - l.a * mult;
        by = y0 + l.a * mult;

        if (ay < by) {
            p.x = ax;
            p.y = max(ay, 0.0);
        } else {
            p.x = bx;
            p.y = max(by, 0.0);
        }
        return true;
    }
}

int main() { _

    double y, x, r;
    cin >> y >> x >> r;
    
    point pUp = {0.0, y}, pSide = {x, 0.0}, orig = {0.0, 0.0};

    line ball;
    pointsToLine(pUp, pSide, ball);

    point intersect;
    if (!hasIntersect(ball, r, intersect)) {
        print(-1);
        return 0;
    }

    if (intersect.y < EPS) {
        print(0);
        return 0;
    }

    double ans = atan((double) intersect.y / (double)fabs(intersect.x));

    print(setprecision(16) << radToDeg(ans));

    return 0;
}

