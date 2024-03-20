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

    string s; cin >> s;

    fore(i, 0, s.size()) {
        if ((s[i]-'0')%8 == 0) {
            print("YES");
            print(s[i]);
            return 0;
        }
    }

    fore(i, 0, s.size()) {
        fore(j, i+1, s.size()) {
            int num = 0;
            num += (s[j]-'0') + ((s[i]-'0')*10);
            if (num%8 == 0) {
                print("YES");
                print(num);
                return 0;
            }   
        }
    }

    fore(i, 0, s.size()) {
        fore(j, i+1, s.size()) {
            fore(k, j+1, s.size()) {
                int num = 0;
                num += ((s[i]-'0')*100) + ((s[j]-'0')*10) + (s[k]-'0');
                if (num%8 == 0) {
                    print("YES");
                    print(num);
                    return 0;
                }
            }
        }
    }

    print("NO");

	return 0;
}