#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int n; cin >> n;
    vector<string> vec;
    unordered_set<string> people;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vec.push_back(s);
    }

    // cout << vec.size() << endl;
    // cout << people.size() << endl;

    for (int i = vec.size()-1; i >= 0; i--) {
        if (people.find(vec[i]) == people.end()) {
            cout << vec[i] << endl;
            people.insert(vec[i]);
        }
    }

    return 0;

}