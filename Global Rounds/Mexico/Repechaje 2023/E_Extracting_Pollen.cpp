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

int transform(int n) {
    int origN = n;
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }

    return origN - sum;
}

int totalSum(int n) {
    int sum = 0;
    while (n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() { _

    int n, k;
    cin >> n >> k;
    vi cnts(1000010);
    priority_queue<int> pq;

    fore(i, 0, n) {
        int temp;
        cin >> temp;

        cnts[temp]++;
        if (cnts[temp] == 1) {
            pq.push(temp);
        }
    }

    while (k > 0) {

        if (pq.empty()) break;

        int top = pq.top();
        pq.pop();

        if (cnts[top] >= k) {
            print(totalSum(top));
            return 0;
        } 
        else {
            int trans = transform(top);
            if(cnts[trans] == 0) {
                pq.push(trans);
            }

            k -= cnts[top];
            cnts[trans] += cnts[top];
            cnts[top] = 0;
        }
    }

    print(0);
	return 0;
}