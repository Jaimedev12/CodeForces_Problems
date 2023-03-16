#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define For(i,l,r) for(int i = l; i < (r); ++i)
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vd> MatrixD;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

double initPi[10100];
double initR[10100];


MatrixD operator*(MatrixD &a, MatrixD &b) {
    int columnsA = a.size() , rowsB = b.size(),z = a[0].size();

    MatrixD r(columnsA,vd(rowsB));
    if(columnsA != rowsB){
        cout << "Error" << endl;
    }
    else{
        For(i,0,columnsA){
            For(j,0,rowsB){
                For(k,0,z){
                    r[i][j] += a[i][k] * b[k][j];
                }
            }
        }
                
        // cout << "Mult " << endl;
        // For(i,0,columnsA){
        //     For(j,0,rowsB){
        //         cout << r[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
	        
	return r;
}


MatrixD MatrixPow(MatrixD base, int n){
    MatrixD ans(base[0].size(), vd(base.size() ));
    For(i,0,ans.size()){
        For(j,0,ans[0].size()){
            if(i == j)
                ans[i][j] = 1;
        }
    }
    
    while(n){
        if(n & 1) 
            ans = ans * base;

        n >>= 1;
        base = base * base;
    }
    
    return ans;
}


int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n; cin >> n;
    cout << setprecision(20) << fixed;
    if(n == 1){
        cout << "100 0" << endl;
    }
    else if(n == 2){
        cout << "0 100" << endl;
    }
    
    else if(n <= 10000){
        initPi[1] = 100; initPi[2] = 0;
        initR[1] = 0; initR[2] = 100;
        for(int i = 3; i <= 10000; ++i){
            initPi[i] = (initPi[i-1] + initPi[i-2]) / 2;
            initR[i] = (initR[i-1] + initR[i-2]) / 2;
        }
        cout << initPi[n] << " "  << initR[n] << endl;
    }
    
    else{
        
        MatrixD temp(2,vd(2));
        temp[0][0] = temp[1][0] = 0.5;
        temp[0][1] = 1;
        temp[1][1] = 0;

        temp = MatrixPow(temp,n-3);
        // We are
        MatrixD Pi(2,vd(2));
        Pi[0][0] = 50;
        Pi[0][1] = Pi[1][0] = 0;
        Pi[1][1] = 100;

        MatrixD R(2,vd(2));
        R[0][0] = 50;
        R[0][1] = R[1][0] = 100;
        R[1][1] = 0;

        Pi = Pi * temp;
        R = R * temp;
        //cout << "Power Pi and R " <<endl; 
        cout << Pi[0][0] << " " <<  R[0][0] << endl;
    }
    // cout << "Pi: " << endl;
    // cout << Pi[0][0] << " " << Pi[0][1] << endl;
    // cout << Pi[1][0] << " " << Pi[1][1] << endl;
    // cout << "R: " << endl;
    // cout << R[0][0] << " " << R[0][1] << endl;
    // cout << R[1][0] << " " << R[1][1] << endl;

    // For(i,1,10){
    //     cout << initPi[i] << " ";
    // }
    // cout << endl;
    
    // For(i,1,10){
    //     cout << initR[i] << " ";
    // }
    // cout << endl;
        
    return 0;
}