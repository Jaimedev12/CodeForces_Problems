// Plantilla de Tsurus Tuneados

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
typedef pair<int, pair<int, int>> intTruple;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


///-------------------------------------------------------------------------
///-------------------------------------------------------------------------

const lli MOD = 1e9 + 7;

///-------------------------------------------------------------------------

lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}

int r, c;
vector<vector<int>> matrix;
vector<pair<int, int>> positions;
priority_queue<int, vector<int>, greater<int>> pq;
bitset<1000010> visited;
bitset<1000010> visited2;
 

void printPQ(priority_queue<int, vector<int>, greater<int>> pq) {
    while (!pq.empty()) {
        cout << pq.top()<< " ";
        pq.pop();
    }
    cout << endl;
}

bool isValid(int curNum, int i, int j) {
    return (i < r && i >= 0 && j < c && j >= 0) && (matrix[i][j] > curNum) && !visited[matrix[i][j]];
}

void addValidAdj(int curNum, int i, int j) {
    if (isValid(curNum, i-1, j)) {
        pq.push(matrix[i-1][j]);
        visited[matrix[i-1][j]] = 1;
        visited2[matrix[i-1][j]] = 1;
    }
    if (isValid(curNum, i+1, j)) {
        pq.push(matrix[i+1][j]);
        visited[matrix[i+1][j]] = 1;
        visited2[matrix[i+1][j]] = 1;
    }
    if (isValid(curNum, i, j-1)) {
        pq.push(matrix[i][j-1]);
        visited[matrix[i][j-1]] = 1;
        visited2[matrix[i][j-1]] = 1;
    }
    if (isValid(curNum, i, j+1)) {
        pq.push(matrix[i][j+1]);
        visited[matrix[i][j+1]] = 1;
        visited2[matrix[i][j+1]] = 1;
    }
}

int main() { _

    cin >> r >> c;

    matrix.resize(r, vector<int>(c));
    positions.resize((r*c)+1);

    for (int i = 0; i < r; i++) { // O(n^2)
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            positions[matrix[i][j]] = make_pair(i, j);
        }
    }

    int ans = 0;

    for (int i = 1; i <= r*c; i++) { // O(n)

        visited.reset();

        if (visited2[i] == 1) {
            continue;   
        }
        
        addValidAdj(i, positions[i].first, positions[i].second);
        int curAns = 1;

        //printPQ(pq);

        int minNum = 0;
        while (!pq.empty()) {
            curAns++;
            minNum = pq.top();
            pq.pop();
            addValidAdj(minNum, positions[minNum].first, positions[minNum].second);
            //printPQ(pq);
        }

        ans = max(ans, curAns);
        

    }

    cout << ans << endl;

  
}   
