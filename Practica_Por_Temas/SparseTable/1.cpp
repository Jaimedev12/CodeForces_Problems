#include <bits/stdc++.h>
using namespace std;

// Código de https://www.youtube.com/watch?v=0jWeUdxrGm4

const int MAX_N = 100'005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];
int log_precom[MAX_N];

int query(int L, int R) {
    int length = R - L + 1;
    int k = log_precom[length];

    return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
    int n; cin >> n;
    int numGroups; cin >> numGroups;

    // Log precomputation to n
    log_precom[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_precom[i] = log_precom[i/2]+1;
    }

    int maxElement = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxElement = max(maxElement, a[i]);
        m[i][0] = a[i];
    }

    // Preprocessing
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1<<k) -1 < n; i++) {
            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
        }
    }

    // Queries
    int k_len = n/numGroups;

    if (numGroups == 1) {
        cout << query(0, n-1) << endl;
        return 0;
    }

    else if (numGroups == 2) {
        cout << max(a[0], a[n-1]) << endl;
        return 0;
    }

    else {
        cout << maxElement << endl;
        return 0;
    }

}

