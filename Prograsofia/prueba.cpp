#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int mat[n][n];

    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;

    int num = 1;

    while (num <= n*n) {

        for (int i = left; i <= right; i++) { // TOP
            mat[top][i] = num;
            num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) { // RIGHT
            mat[i][right] = num;
            num++;
        }
        right--;

        for (int i = right; i >= left; i--) { // BoTTOM
            mat[bottom][i] = num;
            num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) { // LEFT
            mat[i][left] = num;
            num++;
        }
        left++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}