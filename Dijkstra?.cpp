#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <stack>
using namespace std;

// CodeForces problem Dijkstra?
// 1900

void solve() {
  int v, e;
  cin >> v >> e;
  vector<vector<pair<int, int>>> adj(v);

  for(int i = 0; i < e; ++i) {
    int row;
    pair<int, int> conn;
    cin >> row >> conn.first >> conn.second;
    adj[row - 1].push_back(conn);
    adj[conn.first - 1].push_back({row, conn.second});
  }
  vector<int> vals(v);
  vector<bool> vis(v);
  for(int i = 0; i < v; ++i) {
    vals[i] = INT_MAX;
  }
  vals[0] = 0;
  queue<int> q;
  q.push(1);
  //vis[0] = true;
  //vector<vector<int>> track(v);
  //track[0].push_back(1);
  while(!q.empty()) {
    int curr = q.front() - 1;
    q.pop();

    for(pair<int, int> i : adj[curr]) {
      int next = i.first;
      int weight = i.second;

      if(vals[curr] + weight < vals[next - 1]) {
        vals[next - 1] = vals[curr] + weight;
        //track[next - 1] = track[curr];
        //track[next - 1].push_back(next);
        q.push(next);
      }
    }
  }

  if(vals[v - 1] != INT_MAX) {
    stack<int> st;
    int curr = v;
    st.push(curr);
    while(curr != 1) {
      for(pair<int, int> i : adj[curr - 1]) {
        int conn = i.first;
        int weight = i.second;

        if(vals[curr - 1] - weight == vals[conn - 1]) {
          st.push(conn);
          curr = conn;
        }
      }
    }
    while(!st.empty()) {
      cout << st.top() << " ";
      st.pop();
    }
    //for(int i : track[v - 1]) cout << i << " ";
  }
  else cout << -1;
  /*cout << (vals[v - 1] == INT_MAX ? -1 : vals[v - 1]) << "\n";\
  for(int i : vals) {
    cout << i << " ";*/
  
}

int main() {
  solve();
}
