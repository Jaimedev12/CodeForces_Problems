
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


const int MAXN = 1002;

int trainA[MAXN], trainB[MAXN], trainC[MAXN<<1];
int mat[MAXN][MAXN];
int n1, n2;
bool flag;

void solve(int posA, int posB, int posC) {

    //cout << "A: " << posA << " B: " << posB << endl;

    if(posA == n1+1 && posB == n2+1){
        flag = 1;
        return;
    }

    if (mat[posA][posB]) return;

   if(!flag && trainA[posA] == trainC[posC]){
        mat[posA][posB] = 1;
        solve(posA+1, posB, posC+1);
   }

   if (!flag && trainB[posB] == trainC[posC]) {
        mat[posA][posB] = 1;
        solve(posA, posB+1, posC+1);
    }

}

void readVec(int n,int vec[]) {

    fore(i, 1, n+1) {
        cin >> vec[i];
    }
}

int main() { _

    while(cin >> n1 >> n2 && n1+n2 != 0)
    {
        readVec(n1, trainA);
        trainA[n1+1]=-1;

        readVec(n2, trainB);
        trainB[n2+1]=-1;

        readVec(n1+n2, trainC);

        flag = 0;
        memset(mat, 0, sizeof(mat));
        solve(1,1,1);

        print((flag ? "possible" : "not possible"));
    }
    return 0;
}