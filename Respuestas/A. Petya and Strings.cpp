// A. Pethya and Strings

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void lowerCase(string &s){
    for (int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}

int main()
{
    string string1, string2;
    cin >> string1 >> string2;
    vector<char> temp;

    lowerCase(string1);
    lowerCase(string2);
    
    if (string1 == string2){
        cout << 0;
    } else if (string1 < string2){
        cout << -1;
    } else{
        cout << 1;
    }
}
