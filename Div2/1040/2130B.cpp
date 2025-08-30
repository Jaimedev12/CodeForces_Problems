#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

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
#define fore(i, a, b) for (lli i = (a), TT = (b); i < TT; ++i)

const lli MOD = 1e9 + 7;

lli sumMod(lli a, lli b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

lli multMod(lli a, lli b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

void solve()
{
    lli n, s;
    cin >> n >> s;
    vi count(3);

    lli temp;
    lli sum = 0;
    fore(i, 0, n)
    {
        cin >> temp;
        count[temp]++;
        sum += temp;
    }

    if (sum == s)
    {
        print(-1);
        return;
    }

    if (sum > s)
    {
        fore(i, 0, count[0])
        {
            cout << 0 << " ";
        }

        fore(i, 0, count[1])
        {
            cout << 1 << " ";
        }

        fore(i, 0, count[2])
        {
            cout << 2 << " ";
        }
        cout << endl;
        return;
    }

    if (sum + 1 != s)
    {
        print(-1);
        return;
    }

    //////////////////      1 2  0   1 2 0
    // while(count[0]>0 || count[1]>0 || count[2]>0){

    // }
    /////////              11111       2       0000
    fore(i, 0, count[0])
    {
        cout << 0 << " ";
    }
    fore(i, 0, count[2])
    {
        cout << 2 << " ";
    }
    fore(i, 0, count[1])
    {
        cout << 1 << " ";
    }
    cout << endl;
}

int main()
{
    _

        int t;
    cin >> t;
    // int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}