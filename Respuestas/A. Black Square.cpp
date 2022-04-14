// A. Black Square

#include <iostream>
#include <string>

using namespace std;

int a1, a2, a3, a4, cnt = 0;
string s;

void countCalories(){
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '1'){
            cnt += a1;
        } else if (s[i] == '2'){
            cnt += a2;
        } else if (s[i] == '3'){
            cnt += a3;
        } else{
            cnt += a4;
        }
    }
}

int main()
{
    cin >> a1 >> a2 >> a3 >> a4;
    cin >> s;
    
    countCalories();
    
    cout << cnt;
}
