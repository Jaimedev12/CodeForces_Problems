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

void solve() {

    lli n; cin >> n;
    vector<lli> A(n);
    vector<lli> B(n);

    vector<lli> sum(n);

    fore(i, 0, n) {
        cin >> A[i];
    }

    fore(i, 0, n) {
        cin >> B[i];
    }

    fore(i, 0, n) {
        sum[i] = A[i] + B[i];
    }

    vector<pair<lli, lli>> sumPair(n);
    fore(i, 0, n) {
        sumPair[i] = make_pair(sum[i], i);
    }

    sort(sumPair.begin(), sumPair.end());

    lli index = n-1;
    lli maxi = sumPair[index].first;
    lli maxiIndx = sumPair[index].second;
    fore(i, 0, n) {

        // fore(j, 0, n) {
        //     if (sum[j] > maxi) {
        //         maxi = sum[j];
        //         maxiIndx = j;
        //     }
        // }

        if (i % 2 == 0) {
            A[maxiIndx] = A[maxiIndx]-1;
            B[maxiIndx] = 0;
        } else {
            B[maxiIndx] = B[maxiIndx]-1;
            A[maxiIndx] = 0;
        }

        sum[maxiIndx] = -1;

        index--;
        maxi = sumPair[index].first;
        maxiIndx = sumPair[index].second;
    }

    lli sumA = 0;
    lli sumB = 0;
    fore(i, 0, n) {
        sumA += A[i];
        sumB += B[i];
    }

    print(sumA - sumB);

    return;
}

int main() { _

    int t; cin >> t;
    while(t--) {
        solve();
    }

	return 0;
}