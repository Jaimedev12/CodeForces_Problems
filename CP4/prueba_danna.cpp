#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> nums(1e6+10);
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        nums[temp]++;
    }


    int suma = 0;
    for (int i = 0; i < 1e6+10  ; i++) {
        suma += nums[i]%2;
    }
    cout << suma << endl;

       
    return 0;
}