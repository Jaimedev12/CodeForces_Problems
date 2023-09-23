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
#define print(s) write << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

vector<vector<int>> mat(2005, vector<int>(2005));
int posI = 1000;
int posJ = 1000;
int ans = -1;
int step = 0;

vector<int> iMove = {1, -1, 0, 0};
vector<int> jMove = {0, 0, 1, -1};

void move(char dir, int steps) {

    int index = 0;

    switch (dir)
    {
    case 'N':
        index = 0;
        break;
    case 'S':
        index = 1;
        break;
    case 'E':
        index = 2;
        break;
    case 'W':
        index = 3;
        break;
    default:
        return;
        break;
    }


    fore(i, 0, steps) {
        step++;
        posI = posI + iMove[index];
        posJ = posJ + jMove[index];

        if (mat[posI][posJ] != 0) {
            if (ans == -1) {
                ans = step-mat[posI][posJ];
            } else {
                ans = min(ans, step-mat[posI][posJ]);
            }
        }

        mat[posI][posJ] = step;
    }

}

int main() { _

    ifstream read("mowing.in");
	ofstream write("mowing.out");

    int n; read >> n;

    fore(i, 0, n) {
        char dir; read >> dir;
        int steps; read >> steps;

        move(dir, steps);
    }

    print(ans);
	return 0;
}