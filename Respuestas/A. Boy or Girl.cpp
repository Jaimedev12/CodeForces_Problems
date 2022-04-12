// A. Boy or Girl

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt = 0;

void countUniqueLetters(string s){
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++){
        if (s[i] != s[i+1]){
            cnt++;
        }
    }
}

void printResult(){
    if (cnt % 2 == 0){
        cout << "CHAT WITH HER!";
    } else{
        cout << "IGNORE HIM!";
    }
}

int main()
{
    
    string s;
    
    cin >> s;
    
    countUniqueLetters(s);
    printResult();
}
