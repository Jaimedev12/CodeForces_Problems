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

#define MAXCRIBA 1e7 + 7

vector<lli> small_prime(MAXCRIBA);

void solve()
{
    lli n; cin >> n;
    lli even_cont = 0, odd_cont = 0, cont = 0;
    lli p_act = small_prime[n] , p_prev = small_prime[n];

    while (n >= 1)
    {
        p_act = small_prime[n];

        // print("p_act: " << p_act);
        if (p_act != p_prev)
        {
            //print("Entró");
            //print(cont);
            if (cont % 2 == 0)
                even_cont++;
            else
                odd_cont++;
            cont = 0;
        }

        cont++;

        n /= p_act;

        p_prev = p_act;
    }

    if (even_cont > odd_cont)
        print("Psycho Number" );
    else
        print("Ordinary Number");
}

int main()
{
    _

    lli t; cin >> t;

    small_prime[0] = 1e8;
    small_prime[1] = 1e8;

    fore(i, 2, 1e4)
    {
        if (small_prime[i] != 0)
                continue;
        for (lli j = i; j < MAXCRIBA; j += i)
        {
            if (small_prime[j] != 0)
                continue;
            small_prime[j] = i;
        }
    }

    while (t--)
    {
        solve();
    }
}