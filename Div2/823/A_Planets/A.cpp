/*
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < prueba.txt
 */

#include <iostream>
#include <map>
using namespace std;

int main() {

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {

    // nOrbit, nPlanets
    map<int, int> solarSystem;
    int nPlanets, cost;

    cin >> nPlanets >> cost;

    for (int i = 0; i < nPlanets; i++) {
      int nOrbit;
      cin >> nOrbit;

      solarSystem[nOrbit]++;
    }

    int ans = 0;
    for (auto it = solarSystem.begin(); it != solarSystem.end(); it++) {
      ans += min(it->second, cost);
    }

    cout << ans << "\n";
  }
}