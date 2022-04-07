
// A. Gravity Flip

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;
int n;

void readNumbers(){
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
}

void merge(int l, int r) {

    int mid = l + (r-l)/2;
    
    vector<int> left(mid-l+1);
    for (int i = l; i <= mid; i++){
        left[i-l] = v[i];
    }
    
    vector<int> right(r-mid);
    for (int i = mid+1; i <= r; i++){
        right[i-mid-1] = v[i];
    }
    
    size_t leftIterator = 0, rightIterator = 0;
    while(leftIterator < left.size() && rightIterator < right.size()){
        if(left[leftIterator] <= right[rightIterator]){
            v[l+leftIterator+rightIterator] = left[leftIterator];
            leftIterator++;
        } else {
            v[l+leftIterator+rightIterator] = right[rightIterator];
            rightIterator++;
        }
    }
    
    while(leftIterator < left.size()){
        v[l+leftIterator+rightIterator] = left[leftIterator];
        leftIterator++;
    }
    while(rightIterator < right.size()){
        v[l+leftIterator+rightIterator] = right[rightIterator];
        rightIterator++;
    }
    
}

void mergeSort(int l, int r) {

    if (l >= r){
        return;
    }
    
    int mid = l + (r-l)/2; //Equivalente a (l+r)/2 pero escrito así para 
    
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    
    merge(l, r);
}

void printNumbers(){
    for (size_t i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<int> v2(n);
    v = v2;
    
    readNumbers();
    mergeSort(0, (int) v.size()-1);
    printNumbers();
}

