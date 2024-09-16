#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int bfs(pair<int, int> start, pair<int, int> end, int size, vector<vector<string>> graph);

bool inBounds(pair<int, int>, int size);

int main() {
  int n;
  vector<vector<string>> graph;
  fstream file("lines.txt");
  file >> n;
  
  pair<int, int> start;
  pair<int, int> end;

  for(int i = 0; i < n; i++){
    string line;
    file >> line;
    graph.push_back(vector<string>());
    for(int j = 0; j < n; j++){
      char ch = line.at(j);
      string val(1, ch);
      
      graph[i].push_back(val);

      if(val == "@"){
        start.first = i;
        start.second = j;
      }
      else if(val == "X"){
        end.first = i;
        end.second = j;
      }
    }
  }

  cout << bfs(start, end, n, graph) << endl;
}

int bfs(pair<int, int> start, pair<int, int> end, int size, vector<vector<string>> graph){
  int ans = 0;
  vector<vector<bool>> vis(size, vector<bool>(size));
  vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  queue<pair<int, int>> q;
  q.push(start);
  vis[start.first][start.second] = true;
  
  while(!q.empty()){
    pair<int, int> currPoint = q.front();
    q.pop();
    if(currPoint.first == end.first && currPoint.second == end.second){
      return ans;
    }
    for(pair<int, int> dir : directions){
      pair<int, int> newPoint;
      newPoint.first = currPoint.first + dir.first;
      newPoint.second = currPoint.second + dir.second;

      if(inBounds(newPoint, size) && graph[newPoint.first][newPoint.second] != "O" &&
        !vis[newPoint.first][newPoint.second]){
        q.push(newPoint);
        vis[newPoint.first][newPoint.second] = true;
      }
    }

    ans++;
  }

  return -1;
}

bool inBounds(pair<int, int> point, int size){
  if(point.first >= 0 && point.first < size && point.second >= 0 && point.second < size)
    return true;
  return false;
}
