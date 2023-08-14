#include <bits/stdc++.h>
#include <set>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _

    int n; cin >> n;
    int k; cin >> k;
    vector<int> nums(n);
    unordered_set<int> ans;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (auto num : nums) {
        if (num%k != 0) {
            ans.insert(num);
        } else {
            if (ans.find(num/k) == ans.end()) {
                ans.insert(num);
            }
        }
    }

    cout << ans.size() << endl;

    return 0;

}