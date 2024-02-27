// brute force
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> coefs(n);
    for (int i = 0; i < n; i++)
        cin >> coefs[i].first;

    for (int i = 0; i < n; i++)
        cin >> coefs[i].second;

    ll globalMax = 0;
    ll curSum = 0;
    ll maxCoef = -1;
    for (int pref = 1; pref <= min(n, k); pref++)
    {
        maxCoef = max(maxCoef, (ll)coefs[pref - 1].second);
        curSum += (ll)coefs[pref - 1].first;
        ll curMax = curSum + (k - pref) * maxCoef;
        globalMax = max(globalMax, curMax);
    }
    cout << globalMax << "\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
