/*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < prueba.txt
*/

#include "bits/stdc++.h"
using namespace std;

int main() {

  int n;
  scanf("%d", &n);

  string s;
  //        <nombre, repeticiones>
  unordered_map<string, int> database;
  for (int i = 0; i < n; i++) {    
    cin >> s;

    if (database.count(s) == 0) {
      database.insert({s, 1});
      cout << "OK" << endl;
    } else {
      cout << s << database[s] << endl;
      database[s]++;
    } 
  }
}