// A. Magnets

#include <iostream>
#include <vector>

using namespace std;

int n = 0, s = 0, d = 0;

void readCards(vector<int> &v){
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
}

void calcSum(vector<int> &v){
    int l = 0, r = n-1;
    for (int i = 0; i < n; i++){
        
        // Sereja turn
        if (v[l] > v[r]){
            s += v[l];
            l++;
        } else{
            s += v[r];
            r--;
        }
        
        if (l > r){
            return;
        }
        
        i++;
        
        // Dima turn
        if (v[l] > v[r]){
            d += v[l];
            l++;
        } else{
            d += v[r];
            r--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    vector<int> v(n);
    
    readCards(v);
    calcSum(v);
    
    cout << s << " " << d << "\n";

}