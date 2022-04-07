
// A. Team

#include <vector>
#include <iostream>
using namespace std;

void countSureProblems(int n, int &cnt){
    vector<int> v(3);
    for (int i = 0; i < n, i++){
        cin >> v[0] >> v[1] >> v[2];
        
        if (v[0] + v[1] + v[2] >= 2){
            cnt++
        }
    }
}

int main(){
    int n = 0, cnt = 0;
    
    cin >> n
    
    countSureProblems(n, cnt)
    
    cout << cnt;
}

