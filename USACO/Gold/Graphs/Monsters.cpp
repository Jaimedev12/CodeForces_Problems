#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

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
#define fore(i, a, b) for (lli i = (a), TT = (b); i < TT; ++i)

vector<vector<char>> mat;
vector<vector<pair<int, bool>>> dist;
vector<vector<char>> parent;

struct casAdj
{
    char parent;
    pair<int, int> pos;
    bool isPlayer;
};

struct casilla
{
    pair<int, int> pos;
    bool isPlayer;
};

unordered_map<char, pair<int, int>>
    mp = {
        {'R', {0, -1}},
        {'L', {0, 1}},
        {'D', {-1, 0}},
        {'U', {1, 0}}};

vector<casAdj> getAdj(casilla x)
{
    vector<casAdj> ans;
    int i = x.pos.first;
    int j = x.pos.second;
    vector<char> letras = {'L', 'R', 'D', 'U'};
    vector<int> iPos = {0, 0, 1, -1};
    vector<int> jPos = {-1, 1, 0, 0};

    fore(d, 0, 4)
    {
        if (mat[i + iPos[d]][j + jPos[d]] != '#' && dist[i + iPos[d]][j + jPos[d]].first == INT_MAX)
        {
            casAdj newCasilla;
            newCasilla.pos = {i + iPos[d], j + jPos[d]};
            newCasilla.isPlayer = x.isPlayer;
            newCasilla.parent = letras[d];
            ans.pb(newCasilla);
        }
    }

    return ans;
}

void processOutput(int i, int j)
{
    print("YES");
    print(dist[i][j].first);

    string path;
    int curI = i;
    int curJ = j;
    while (dist[curI][curJ].first)
    {
        path.push_back(parent[curI][curJ]);
        pair<int, int> move = mp[parent[curI][curJ]];
        curI += move.first;
        curJ += move.second;
    }

    reverse(path.begin(), path.end());
    print(path);
    return;
}

int main()
{
    _

        int n,
        m;
    cin >> n >> m;
    mat = vector<vector<char>>(n + 2, vector<char>(m + 2, '#'));
    dist = vector<vector<pair<int, bool>>>(n + 2, vector<pair<int, bool>>(m + 2, {INT_MAX, false}));
    parent = vector<vector<char>>(n + 2, vector<char>(m + 2, '#'));
    pair<int, int> start;
    vector<pair<int, int>> monsters;
    fore(i, 1, n + 1)
    {
        fore(j, 1, m + 1)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
            if (mat[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
        }
    }

    queue<casilla> q;
    fore(i, 0, monsters.size())
    {
        dist[monsters[i].first][monsters[i].second] = {0, false};
        casilla newCasilla;
        newCasilla.isPlayer = false;
        newCasilla.pos = monsters[i];
        q.push(newCasilla);
    }

    dist[start.first][start.second] = {0, true};
    casilla playerCasilla;
    playerCasilla.isPlayer = true;
    playerCasilla.pos = start;
    q.push(playerCasilla);

    while (!q.empty())
    {
        casilla x = q.front();
        int i = x.pos.first;
        int j = x.pos.second;
        q.pop();
        for (casAdj t : getAdj(x))
        {
            parent[t.pos.first][t.pos.second] = t.parent;
            dist[t.pos.first][t.pos.second] = {dist[i][j].first + 1, x.isPlayer};
            casilla newCasilla;
            newCasilla.pos = {t.pos.first, t.pos.second};
            newCasilla.isPlayer = x.isPlayer;
            q.push(newCasilla);
        }
    }

    fore(i, 1, m + 1)
    { // up and down
        if (dist[1][i].second)
        {
            processOutput(1, i);
            return 0;
        }

        if (dist[n][i].second)
        {
            processOutput(n, i);
            return 0;
        }
    }

    fore(i, 1, n + 1)
    { // up and down
        if (dist[i][1].second)
        {
            processOutput(i, 1);
            return 0;
        }

        if (dist[i][m].second)
        {
            processOutput(i, m);
            return 0;
        }
    }

    print("NO");

    // fore(i, 1, n+1) {
    //     fore(j, 1, m+1) {
    //         cout << parent[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // fore(i, 1, n+1) {
    //     fore(j, 1, m+1) {
    //         if (dist[i][j].first == INT_MAX) {
    //             cout << "- ";
    //         } else {
    //             cout << dist[i][j].first << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // fore(i, 1, n+1) {
    //     fore(j, 1, m+1) {
    //         cout << dist[i][j].second << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}