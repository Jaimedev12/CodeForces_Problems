#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> positions;

    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        if (num % 3 == 0){
            positions.push_back(i + 1);
        }
    }

    if (positions.size() == 0){
        cout << "No hay triples." << endl;
    }
    else{
        cout << positions.size()  << endl;    
    }

    for (int i = 0; i < positions.size(); i++) {
        cout << positions[i] << " ";
    }
    cout << endl;
    return 0;
}