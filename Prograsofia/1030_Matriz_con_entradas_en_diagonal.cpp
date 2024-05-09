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


void fillNextSpace(int curPosI, int curPosJ, int curNum, int mat[][1000]) {
    int nextPosI = curPosI-1;
    int nextPosJ = curPosJ-1;

    if (nextPosJ < 0 || nextPosI < 0) {
        nextPosI = 0;
        nextPosJ = curPosJ + curPosI;
    }

    mat[nextPosI][nextPosJ] = curNum;
}

int main() { _
  int n, m; 
  cin >> n >> m;
  int mat[1000][1000];
  mat[0][0] = 1;

  int curPosI = 0;
  int curPosJ = 0;
  int curNum = 2;
  while (curNum <= n*m) {
    fillNextSpace(curPosI, curPosJ, curNum, mat);
    curNum++;
  }


  return 0;
}