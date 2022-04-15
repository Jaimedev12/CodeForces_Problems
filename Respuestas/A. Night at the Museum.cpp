// A. Night at the Museum

#include <iostream>
#include <string>

using namespace std;

int steps = 0;
string s;

void countSteps(){
    int start = 0; // a
    int index = 0, walk = 0;
    for (int i = 0; i < s.length(); i++){
        index = (int) s[i] - 97;
        walk = abs(start - index);
        if (walk < 13){
            steps += walk;
        } else{
            steps += 26 - walk;
        }
        start = index;
    }
}

int main()
{
    cin >> s;
    
    countSteps();
    
    cout << steps;
}
