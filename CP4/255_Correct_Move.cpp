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

int q, k, target;

void getQueenMoves(vector<int> &queenMoves, vector<int> &kingMoves) {
    int curPosition = q;
    while (true) { // Arriba
        curPosition -= 8;

        // Si se topa con el rey
        // Si se sale del tablero
            // break;
        if (curPosition == k || curPosition < 0) break;

        // Agregar el movimiento al arreglo
        queenMoves.pb(curPosition);
    }

    curPosition = q;

    while (true) { // Abajo
        curPosition += 8;
        if (curPosition == k || curPosition > 63) break;
        queenMoves.pb(curPosition);
    }

    curPosition = q;

    while (true) { // Derecha
        if (curPosition%8 == 7) break;
        curPosition++;
        if (curPosition == k) break;
        queenMoves.pb(curPosition);
    }

    curPosition = q;

    while (true) { // Izquierda
        if (curPosition%8 == 0) break;
        curPosition--;
        if (curPosition == k) break;
        queenMoves.pb(curPosition);
    }
}

int main() { _

    while(cin >> k >> q >> target) {

        if (k == q) {
            print("Illegal state");
            continue;
        }

        vector<int> kingMoves;
        if (k > 8) kingMoves.pb(k-8); // Arriba
        if (k < 56) kingMoves.pb(k+8); // Abajo
        if (k%8 != 0) kingMoves.pb(k-1); // Izquierda
        if (k%8 != 7) kingMoves.pb(k+1); // Derecha

        vector<int> queenMoves;
        getQueenMoves(queenMoves, kingMoves);

        if (find(all(queenMoves), target) == queenMoves.end()) {
            print("Illegal move");
            continue;
        }

        if (find(all(kingMoves), target) != kingMoves.end()) {
            print("Move not allowed");
            continue;
        }

        queenMoves.clear();
        q = target;
        getQueenMoves(queenMoves, kingMoves);

        int notAllowed = 0;
        fore(i, 0, sz(kingMoves)) {
            if (find(all(queenMoves), kingMoves[i]) != queenMoves.end()) {
                notAllowed++;
            }
        }

        if (notAllowed == sz(kingMoves)) {
            print("Stop");
            continue;
        } 

        print("Continue");
    }

	return 0;
}