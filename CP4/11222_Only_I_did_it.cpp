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

void solve(int testNum) {
    int n;

    cin >> n; 
    vector<int> vec1(n);
    unordered_set<int> set1;
    fore(i, 0, n) {
        cin >> vec1[i];
        set1.insert(vec1[i]);
    }

    cin >> n; 
    vector<int> vec2(n);
    unordered_set<int> set2;
    fore(i, 0, n) {
        cin >> vec2[i];
        set2.insert(vec2[i]);
    }

    cin >> n; 
    vector<int> vec3(n);
    unordered_set<int> set3;
    fore(i, 0, n) {
        cin >> vec3[i];
        set3.insert(vec3[i]);
    }

    // ---------------------------------------------

    vector<int> ans1;
    fore(i, 0, vec1.size()) {
        if (set2.find(vec1[i]) == set2.end() && set3.find(vec1[i]) == set2.end()) {
            ans1.push_back(vec1[i]);
        }
    }

    vector<int> ans2;
    fore(i, 0, vec2.size()) {
        if (set1.find(vec2[i]) == set1.end() && set3.find(vec2[i]) == set3.end()) {
            ans2.push_back(vec2[i]);
        }
    }

    vector<int> ans3;
    fore(i, 0, vec3.size()) {
        if (set1.find(vec3[i]) == set1.end() && set2.find(vec3[i]) == set2.end()) {
            ans3.push_back(vec3[i]);
        }
    }

    // ---------------------------------------------

    int maxSolved = max(ans1.size(), max(ans2.size(), ans3.size()));
    print("Case #" << testNum << ":");

    if (ans1.size() == maxSolved) {
        sort(all(ans1));

        cout << "1 " << maxSolved << " ";
        fore(i, 0, ans1.size()-1) {
            cout << ans1[i] << " ";
        } print(ans1[ans1.size()-1]);
    }

    if (ans2.size() == maxSolved) {
        sort(all(ans2));

        cout << "2 " << maxSolved << " ";
        fore(i, 0, ans2.size()-1) {
            cout << ans2[i] << " ";
        } print(ans2[ans2.size()-1]);
    }

    if (ans3.size() == maxSolved) {
        sort(all(ans3));

        cout << "3 " << maxSolved << " ";
        fore(i, 0, ans3.size()-1) {
            cout << ans3[i] << " ";
        } print(ans3[ans3.size()-1]);
    }
    
}

int main() { _

    int t; cin >> t;
    int cnt = 0;
    while (t--) {
        cnt++;
        solve(cnt);
    }

	return 0;
}