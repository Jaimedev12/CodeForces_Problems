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

int r, c;
bool flag = 0;
bitset<100> tuerca;
vector<bitset<100>> maze(1000);
vector<bitset<100>> rotations(100);
vector<vector<bool>> possible;
vector<vector<bool>> vis;

// Initialize direction vectors
int dRow[] = { 0, 1, 0, -1 };
int dCol[] = { -1, 0, 1, 0 };

bool canEnter(bitset<100> &tuerca, bitset<100> &row) {
    int cnt1 = tuerca.count();
    int cnt2 = row.count();
    int cnt3 = (tuerca ^ row).count();
    return (cnt1 + cnt2) == cnt3;
}

bool isValid(int &row, int &col) {

    if (col < 0) col = c-1;

    if (col >= c) col = 0;

    if (row < 0 || row >= r)
        return false;
 
    if (vis[row][col])
        return false;
 
    return possible[row][col];
}

void DFS() {
    stack<pair<int, int>> st;

    fore(i, 0, c) {
        if (possible[0][i]){
            st.push({0, i});
        }
    }    
 
    while (!st.empty()) {
        pair<int, int> curr = st.top();
        st.pop();
        int row = curr.first;
        int col = curr.second;
 
        if (!isValid(row, col))
            continue;
 
        vis[row][col] = true;

        if (row == r-1) {
            flag = 1;
            break;
        }
 
        for (int i = 0; i < 4; i++) {
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];
            st.push({ adjx, adjy });
        }
    }
}

int main() { _

    cin >> r >> c;
    possible = vector<vector<bool>>(r, vector<bool>(c));
    vis = vector<vector<bool>> (r, vector<bool>(c));

    string s; cin >> s;
    tuerca = bitset<100>(s);

    fore(i, 0, r) {
        string row; cin >> row;
        maze[i] = bitset<100>(row);
    }

    // Crear rotaciones
    fore(i, 0, c) {
        rotations[i] = tuerca;
        int prevVal = tuerca[0];
        tuerca >>= 1;
        tuerca[c-1] = prevVal;
        rotations[i] = tuerca;
    }

    // Contruir matriz de posibles posiciones
    fore(i, 0, r) {
        fore(j, 0, c) {
            possible[i][j] = canEnter(rotations[j], maze[i]);
        }
    }

    DFS();


    if (flag) {
        print("Y");
        return 0;
    }

    reverse(all(s));
    tuerca = bitset<100>(s);
    possible = vector<vector<bool>>(r, vector<bool>(c));
    vis = vector<vector<bool>> (r, vector<bool>(c));

    // Crear rotaciones
    fore(i, 0, c) {
        rotations[i] = tuerca;
        int prevVal = tuerca[0];
        tuerca >>= 1;
        tuerca[c-1] = prevVal;
        rotations[i] = tuerca;
    }

    // Contruir matriz de posibles posiciones
    fore(i, 0, r) {
        fore(j, 0, c) {
            possible[i][j] = canEnter(rotations[j], maze[i]);
        }
    }

    DFS();

    print((flag ? "Y" : "N"));
    return 0;

    // fore(i, 0, c) {
    //     if (vis[r-1][i] == 1) {
    //         cout << "Y" << endl;
    //         return 0;
    //     }
    // }

    // print("N");
    // return 0;

    // cout << isValid(0, 8) << " " << isValid(0, 9) << endl;
    // print(isValid(1, -1));
    // print(isValid(2, -1));

    // fore(i, 0, r) {
    //     cout << maze[i] << endl;
    // }

    // fore(i, 0, 100) {
    //     cout << rotations[i] << endl;
    // }

    // fore(i, 0, r) {
    //     fore(j, 0, c) {
    //         cout << possible[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    // fore(i, 0, r) {
    //     fore(j, 0, c) {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;



}