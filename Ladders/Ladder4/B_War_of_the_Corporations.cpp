#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() { _

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> vec = zFunction(s2 + "$" + s1);

    int cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == s2.length()) {
            cnt++;
            i += vec[i]-1;
        }
    }

    cout << cnt << endl;

    return 0;

}