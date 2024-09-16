//12 out of 12 Test Cases
//Silver

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int cities;
int roads;
vector<bool> vis;
int numRoads = 0;
vector<int> need;

void dfs(vector<vector<int>> &cities, int start)
{
  vis[start] = true;
  for(auto i : cities[start])
    {
      if(!vis[i])
      {
        dfs(cities, i);
      }
    }
}

int main() {
  cin >> cities;
  cin >> roads;

  vis = vector<bool>(cities);
  need = vector<int>();

  vector<vector<int>> adj(cities);

  for(int i = 0; i < roads; i++)
    {
      int city1;
      int city2;

      cin >> city1 >> city2;

      adj[city1 - 1].push_back(city2 - 1);
      adj[city2 - 1].push_back(city1 - 1);
    }

  for(int i = 0; i < cities; i++)
    {
      if(!vis[i])
      {
        numRoads++;
        need.push_back(i);
        dfs(adj, i);
      }
    }
  
  cout << numRoads - 1 << endl;
  for(int i = 1; i  < (int)need.size(); i++)
    {
      cout << need[0] + 1 << " " << need[i] + 1 << endl;
    }
}
