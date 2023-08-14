
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> players;
    vector<int> scores;

    int m = 0;

    for (int i = 0; i < n; i++) {
        cin >> players[i] >> scores[i];
        m = max(m, scores[i]);
    }

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        mp[players[i]] += scores[i];
        if (mp[players[i]] == m) {
            cout << players[i] << endl;
            return 0;
        }
    }

    return 0;
}