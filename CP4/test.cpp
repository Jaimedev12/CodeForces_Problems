#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> total_value;
vector<vector<pair<int, int>>> adjList;

int getTeamValue(int v) {
  if (total_value[v] != -1) return total_value[v];

  int value = 0;
  for (int i = 0; i < adjList[v].size(); i++) {
    value += adjList[v][i].second;
    value += getTeamValue(adjList[v][i].first);
  }
  total_value[v] = value;
  return value;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int numEmployees, numBosses, numEdges;
  cin >> numEmployees >> numBosses >> numEdges;

  total_value = vector<int>(numEmployees+1, -1);
  adjList = vector<vector<pair<int, int>>>(numEmployees+1);

  vector<int> bosses(numBosses);
  for (int i = 0; i < numBosses; i++) {
    cin >> bosses[i];
  }

  for (int i = 0; i < numEdges; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    adjList[a].push_back({b, c});
  }

  //        value  id
  vector<pair<int, int>> ans;
  for (int i = 0; i < numBosses; i++) {
    ans.push_back({getTeamValue(bosses[i]), bosses[i]});
  }

  sort(ans.rbegin(), ans.rend(), [](auto a, auto b){
    if (a.first == b.first){
        return a.second > b.second;
    }

    return a.first < b.first;
  });

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].second << " " << ans[i].first << endl;
  }
  
  return 0;
}