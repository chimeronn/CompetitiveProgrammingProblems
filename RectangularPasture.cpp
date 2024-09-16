//20 out of 20 Test Cases Passed
//Silver

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool yCmp(pair<int, int> p1, pair<int, int> p2)
{
  return p1.second < p2.second;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> pfx(n + 1, vector<int>(n + 1));
  vector<pair<int, int>> coords(n);

  for(int i = 0; i < n; i++)
    {
      pair<int, int> coord;
      cin >> coord.first >> coord.second;
      coords[i] = coord;
    }

  sort(coords.begin(), coords.end());
  int i = 0;
  for(pair<int, int> &p : coords)
    {
      p.first = i;
      i++;
    }

  sort(coords.begin(), coords.end(), yCmp);
  int j = 0;
  for(pair<int, int> &p : coords)
    {
      p.second = j;
      j++;
    }

  sort(coords.begin(), coords.end());

  for(pair<int, int> p : coords)
    {
      pfx[p.first + 1][p.second + 1] = 1;
    }
  
  for(int i = 1; i < n + 1; i++)
    {
      for(int j = 1; j < n + 1; j++)
        {
          pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1] - pfx[i - 1][j - 1];
        }
    }

  /*for(int i = 0; i < n + 1; i++)
    {
      for(int j = 0; j < n + 1; j++)
        {
          cout << pfx[i][j] << " ";
        }
      cout << endl;
    }*/


  long long ans = n + 1;
  for(int i = 0; i < n - 1; i++)
    {
      for(int j = i + 1; j < n; j++)
        {
          pair<int, int> coord1 = coords[i];
          pair<int, int> coord2 = coords[j];

          int x1 = coord1.first + 1;
          int x2 = coord2.first + 1;

          int highY = max(coord1.second, coord2.second) + 1;
          int lowY = min(coord1.second, coord2.second) + 1;

          int high = 1;
          int low = 1;

          high += pfx[x2][n] - pfx[x2][highY] - pfx[x1 - 1][n] + pfx[x1 - 1][highY];
          low += pfx[x2][lowY - 1] - pfx[x1][lowY - 1];

          ans += high * low;
        }
    }

  cout << ans;
}
