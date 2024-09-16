//15 out of 15 Test Cases Passed
//Silver

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, q;

int main() {
  fstream file("bcount.in");
  file >> n >> q;

  vector<vector<int>> cows(n + 1, vector<int>(3));
  cows[0] = {0, 0, 0};

  for(int i = 1; i < n + 1; i++)
    {
      int c;
      file >> c;

      cows[i] = cows[i - 1];
      cows[i][c - 1]++;
    }

  ofstream out("bcount.out");
  for(int i = 0; i < q; i++)
    {
      int a, b;
      file >> a >> b;

      out << cows[b][0] - cows[a - 1][0] << " " << cows[b][1] - cows[a - 1][1] << " " <<
        cows[b][2] - cows[a - 1][2] << endl;
    }
}
