// A. Is your horseshoe on the other hoof?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    
    int cnt = 0;
    
    vector<int> hs{s1, s2, s3, s4};
    sort(hs.begin(), hs.end());
    
    for (int i = 0; i < hs.size(); i++){
        if (hs[i] == hs[i+1])
            cnt++;
    }
    
    cout << cnt << endl;
}
