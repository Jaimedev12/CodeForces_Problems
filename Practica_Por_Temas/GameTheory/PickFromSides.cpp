#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<pair<int, int>>> mat(n, vector<pair<int, int>>(n));

    for (int i = 0; i < n; i++) {
        mat[i][i] = {nums[i], 0};
    }

    for (int i = n-2; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            
            int left = nums[i] + mat[i+1][j].second;
            int right = nums[j] + mat[i][j-1].second;
            mat[i][j].first = max(left, right);
            
            if (left > right) {
                mat[i][j].second = mat[i+1][j].first;
            } else {
                mat[i][j].second = mat[i][j-1].first;
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(" << mat[i][j].first << ", " << mat[i][j].second << ")\t";
        }
        cout << "\n";
    }


}


