// A. Games

#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0;

void readInputs(vector<int> &home, vector<int> &guest){
    for (int i = 0; i < n; i++){
        cin >> home[i] >> guest[i];
    }
}

void calcChanges(vector<int> &home, vector<int> &guest){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (home[i] == guest[j]) {
                cnt++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    vector<int> home(n), guest(n);
    
    readInputs(home, guest);
    calcChanges(home, guest);
    
    cout << cnt;
}
