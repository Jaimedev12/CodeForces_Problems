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

char board[8][8];
bool attacked[8][8];
string fen;

void fillLines(int i, int j) {

    int curI = i-1;
    int curJ = j;

    while (curI >= 0) { // Arriba
        if (board[curI][curJ] != ' ') break;
        attacked[curI][curJ] = true;
        curI--;
    }

    curI = i+1;
    curJ = j;

    while (curI < 8) { // Abajo
        if (board[curI][curJ] != ' ') break;
        attacked[curI][curJ] = true;
        curI++;
    }

    curI = i;
    curJ = j+1;

    while (curJ < 8) { // Derecha
        if (board[curI][curJ] != ' ') break;
        attacked[curI][curJ] = true;
        curJ++;
    }

    curI = i;
    curJ = j-1;

    while (curJ >= 0) { // Izquierda
        if (board[curI][curJ] != ' ') break;
        attacked[curI][curJ] = true;
        curJ--;
    }

    return;
}

void fillDiagonals(int i, int j) {

    int curI = i-1;
    int curJ = j+1;

    while (curI >= 0 && curJ < 8) { // Arriba - Derecha
        if (board[curI][curJ] != ' ')  break;
        attacked[curI][curJ] = true;
        curI--;
        curJ++;
    }

    curI = i+1;
    curJ = j+1;

    while (curI < 8 && curJ < 8) { // Abajo - Derecha
        if (board[curI][curJ] != ' ')  break;
        attacked[curI][curJ] = true;
        curI++;
        curJ++;
    }

    curI = i-1;
    curJ = j-1;

    while (curJ >= 0 && curI >= 0) { // Arriba - Izquierda
        if (board[curI][curJ] != ' ')  break;
        attacked[curI][curJ] = true;
        curJ--;
        curI--;
    }

    curI = i+1;
    curJ = j-1;

    while (curJ >= 0 && curI < 8) { // Abajo - Izquierda
        if (board[curI][curJ] != ' ')  break;
        attacked[curI][curJ] = true;
        curI++;
        curJ--;
    }
    return;
}

void fillKnight(int i, int j) {
    vector<int> movesI = {2, 1, -1, -2, 2, 1, -1, -2};
    vector<int> movesJ = {-1, -2, -2, -1, 1, 2, 2, 1};

    fore (k, 0, 8) {
        int newI = i+movesI[k];
        int newJ = j+movesJ[k];
        bool isInside = (newI >= 0 && newJ < 8 && newJ >= 0 && newJ < 8);
        if (isInside && board[newI][newJ] == ' ') {
            attacked[newI][newJ] = true;
        }
    }

    return;
}

void fillKing(int i, int j) {
    vector<int> movesI = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> movesJ = {-1, 0, 1, -1, 1, -1, 0, 1};

    fore (k, 0, 8) {
        int newI = i+movesI[k];
        int newJ = j+movesJ[k];
        bool isInside = (newI >= 0 && newJ < 8 && newJ >= 0 && newJ < 8);
        if (isInside && board[newI][newJ] == ' ') {
            attacked[newI][newJ] = true;
        }
    }
    return;
}

void fillBlackP(int i, int j) {
    vector<int> movesI = {1, 1};
    vector<int> movesJ = {-1, 1};

    fore (k, 0, 2) {
        int newI = i+movesI[k];
        int newJ = j+movesJ[k];
        bool isInside = (newI >= 0 && newJ < 8 && newJ >= 0 && newJ < 8);
        if (isInside && board[newI][newJ] == ' ') {
            attacked[newI][newJ] = true;
        }
    }
    return;
}

void fillWhiteP(int i, int j) {
    vector<int> movesI = {-1, -1};
    vector<int> movesJ = {-1, 1};

    fore (k, 0, 2) {
        int newI = i+movesI[k];
        int newJ = j+movesJ[k];
        bool isInside = (newI >= 0 && newJ < 8 && newJ >= 0 && newJ < 8);
        if (isInside && board[newI][newJ] == ' ') {
            attacked[newI][newJ] = true;
        }
    }
    return;
}

void solve() {
    memset(board, ' ', sizeof(board));
    memset(attacked, 0, sizeof(attacked));

    int row = 0;
    int col = 0;
    fore(i, 0, fen.size()) {
        if (fen[i] == '/') {
            row++;
            col = 0;
            continue;
        }

        if (isdigit(fen[i])) {
            col += fen[i]-'0';
            continue;
        }

        board[row][col] = fen[i];
        attacked[row][col] = true;
        col++;
    }

    fore(i, 0, 8) {
        fore(j, 0, 8) {
            switch (board[i][j]) {
                case 'r':
                case 'R':
                    fillLines(i, j);
                    break;
                case 'n':
                case 'N':
                    fillKnight(i, j);
                    break;
                case 'b':
                case 'B':
                    fillDiagonals(i, j);
                    break;
                case 'q':
                case 'Q':
                    fillLines(i, j);
                    fillDiagonals(i, j);
                    break;
                case 'k':
                case 'K':
                    fillKing(i, j);
                    break;
                case 'p':
                    fillBlackP(i, j);
                    break;
                case 'P':
                    fillWhiteP(i, j);
                    break;
            }
        }
    }

    int ans = 0;

    fore(i, 0, 8) {
        fore(j, 0, 8) {
            if (!isalpha(board[i][j]) && !attacked[i][j]) {
                ans++;
            }
        }
    }

    print(ans);

    // fore(i, 0, 8) {
    //     fore(j, 0, 8) {
    //         cout << attacked[i][j];
    //     }cout << endl;
    // }cout << endl;

}

int main() { _

    while(cin >> fen) {
        solve();
    }

	return 0;
}