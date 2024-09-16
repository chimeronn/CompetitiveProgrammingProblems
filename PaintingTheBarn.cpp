//10 out of 10 Test Cases Passed
//Silver

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  fstream file("paintbarn.in");
  int n;
  int k;

  file >> n >> k;

  vector<vector<int>> barn(1001, vector<int>(1001));

  for(int i = 0; i < n; i++)
    {
      int x1, x2, y1, y2;
      file >> x1 >> y1 >> x2 >> y2;

      barn[x1][y1]++;
      barn[x1][y2]--;
      barn[x2][y1]--;
      barn[x2][y2]++;
    }

  int ans = 0;

  for(int i = 0; i < 1001; i++)
    {
      for(int j = 0; j < 1001; j++)
        {
          if(i > 0)
            barn[i][j] += barn[i - 1][j];
          if(j > 0)
            barn[i][j] += barn[i][j - 1];
          if(i > 0 && j > 0)
            barn[i][j] -= barn[i - 1][j - 1];

          if(barn[i][j] == k)
            ans++;
        }
    }

  ofstream out("paintbarn.out");

  out << ans << endl;
}
