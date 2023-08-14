#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int t; cin >> t;
    
    while (t--) {

        string a, b, c;
        cin >> a >> b >> c;
        int n = a.length();
        bool flag = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == c[i] || b[i] == c[i]) continue;

            cout << "NO" << endl;
            flag = true;
            break;
        }

        if (!flag) {
            cout << "YES" << endl;
        }
        
    }

    return 0;

}