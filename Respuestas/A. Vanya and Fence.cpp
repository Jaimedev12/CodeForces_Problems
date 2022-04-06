
// A. Vanya and Fence 

#include <vector>
#include <iostream>
using namespace std;

void initializeVector(vector<int> &x, int n){
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
}

int countWidth(vector<int> a, int n, int h){
    int w = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= h)
            w++;
        else
            w += 2;
    }
    return w;
}

int main(){
    int n, h;
    cin >> n >> h;
    
    // Create a vector the size of the number of friends
    vector<int> a(n);
    initializeVector(a, n);
    
    int w = countWidth(a, n, h);
    cout << w;
}

