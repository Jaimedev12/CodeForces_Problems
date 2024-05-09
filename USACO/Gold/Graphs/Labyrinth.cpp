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

vector<vector<char>> mat;
vector<vector<int>> dist;
vector<vector<char>> parent;

unordered_map<char, pair<int, int>> 
mp = {
    {'R', {0, -1}},
    {'L', {0, 1}},
    {'D', {-1, 0}},
    {'U', {1, 0}}
};

vector<pair<char, pair<int, int>>> getAdj(pair<int, int> x) {
    vector<pair<char, pair<int, int>>> ans;
    int i = x.first;
    int j = x.second;
    vector<char> letras = {'L', 'R', 'D', 'U'};
    vector<int> iPos = {0, 0, 1, -1};
    vector<int> jPos = {-1, 1, 0, 0};

    fore(d, 0, 4) {
        if (mat[ i+iPos[d] ][ j+jPos[d] ] != '#' && dist[i+iPos[d]][j+jPos[d]] == INT_MAX) {
            ans.pb({letras[d], {i+iPos[d], j+jPos[d]}});
        }
    }
    
    return ans;
}

int main() { _

    int n, m;
    cin >> n >> m;
    mat = vector<vector<char>>(n+2, vector<char>(m+2, '#'));
    dist = vector<vector<int>>(n+2, vector<int>(m+2, INT_MAX));
    parent = vector<vector<char>>(n+2, vector<char>(m+2, '#'));
    pair<int, int> start, end;
    fore(i, 1, n+1) {
        fore(j, 1, m+1) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                start.first = i;
                start.second = j;
            }
            if (mat[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }

    queue<pair<int, int>> q;
    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        pair<int, int> x = q.front();
        int i = x.first;
        int j = x.second;
        q.pop();
        for (auto t : getAdj(x)) {
            parent[t.second.first][t.second.second] = t.first;
            dist[t.second.first][t.second.second] = dist[i][j]+1;
            q.push({t.second.first, t.second.second});
        }
    }

    if (dist[end.first][end.second] == INT_MAX) {
        print("NO");
        return 0;
    }

    print("YES");
    print(dist[end.first][end.second]);

    string path;
    int curI = end.first;
    int curJ = end.second;
    while (dist[curI][curJ]) {
        path.push_back(parent[curI][curJ]);
        pair<int, int> move = mp[parent[curI][curJ]];
        curI += move.first;
        curJ += move.second;
    }

    reverse(path.begin(), path.end());
    print(path);
    cout << endl;

    // fore(i, 1, n+1) {
    //     fore(j, 1, m+1) {
    //         cout << parent[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // fore(i, 1, n+1) {
    //     fore(j, 1, m+1) {
    //         if (dist[i][j] == INT_MAX) {
    //             cout << "- ";
    //         } else {
    //             cout << dist[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

	return 0;
}