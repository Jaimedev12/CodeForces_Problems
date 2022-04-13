
// A. Word

#include <iostream>
#include <string>

using namespace std;

int lowerCnt = 0, upperCnt = 0;

void stringToUpper(string &s){
    for (int i = 0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
}

void stringToLower(string &s){
    for (int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}

void countUpAndLow(string &s){
    for (int i = 0; i < s.length(); i++){
        if (isupper(s[i]))
            upperCnt++;
        else
            lowerCnt++;
    }
}

int main()
{
    
    string s;
    
    cin >> s;
    
    countUpAndLow(s);
    
    if(upperCnt <= lowerCnt){
        stringToLower(s);
    } else{
        stringToUpper(s);
    }

    cout << s;

}
