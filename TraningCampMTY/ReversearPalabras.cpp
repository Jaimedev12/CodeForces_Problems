#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void imprimirPalabraConComa(string p) {
    reverse(p.begin(), p.end());
    cout << p << ",";
}  

void imprimirPalabraConFinDeLinea(string p) {
    reverse(p.begin(), p.end());
    cout << p << endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string palabra = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            imprimirPalabraConComa(palabra);
            palabra = "";
        }
        else {
            palabra.push_back(s[i]);
        }
    }

    imprimirPalabraConFinDeLinea(palabra);

    return 0;
}