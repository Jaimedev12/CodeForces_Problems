#include <bits/stdc++.h>
using namespace std;

int main () {

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        vector<int> a(N);
        vector<int> b(N);

        int nOnesA = 0;
        int nOnesB = 0;


        // Leer input
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            
            if (a[i]) {
                nOnesA++;
            }

        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];

            if (b[i]) {
                nOnesB++;
            }

        }

        int nOps1 = 0, nOps2 = 0;

        // N OPS 1 
        for (int i = 0; i < N; i++) {
            if (a[i] != b[i]) {
                nOps1++;
            }
        }

        nOps2 = 1 + abs(nOnesA - nOnesB);

        cout << min(nOps1, nOps2) << endl;

    }

    return 0;
}