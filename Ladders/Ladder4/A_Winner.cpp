
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> players(n);
    vector<int> scores(n);

    unordered_map<string, int> finalScores;

    for (int i = 0; i < n; i++) {
        cin >> players[i] >> scores[i];
        finalScores[players[i]] += scores[i];
    }


    int m = 0;

    for (auto score : finalScores) {
        m = max(m, score.second);
    }

    unordered_map<string, int> currentScores;

    for (int i = 0; i < n; i++) {
        currentScores[players[i]] += scores[i];
        if (currentScores[players[i]] >= m && finalScores[players[i]] == m) {
            cout << players[i] << endl;
            return 0;
        }
    }

    return 0;
}