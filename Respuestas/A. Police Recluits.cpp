// A. Police Recruits

#include <iostream>

using namespace std;

int n = 0, crimeCnt = 0, policeCnt = 0;

void processEvents(){
    int event;
    for (int i = 0; i < n; i++){
        cin >> event;
        
        if (event > 0){
            policeCnt += event;
        }
        
        if (event < 0){
            if(policeCnt != 0){
                policeCnt--;
            } else{
                crimeCnt++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    processEvents();
    
    cout << crimeCnt;
}
