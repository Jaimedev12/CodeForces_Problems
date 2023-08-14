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

int main() { _

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> dict;

    fore(i, 0, n) {
        string name, ip;
        cin >> name >> ip;

        dict[ip] = name;
    }

    fore(i, 0, m) {
        string command, ip;
        cin >> command >> ip;

        cout << command << " " << ip << " " << "#" << dict[ip.substr(0, ip.length()-1)] << endl;
    }

    return 0;

}