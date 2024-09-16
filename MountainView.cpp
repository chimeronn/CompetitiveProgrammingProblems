//10 out of 11 Test Cases Passed
//Silver

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
  fstream file("mountains.in");
  int n;

  file >> n;

  vector<pair<int, int>> peaks(n);

  for(int i = 0; i < n; i++)
    {
      pair<int, int> peak;
      int x, y;
      file >> x >> y;

      peak.first = x - y;
      peak.second = x + y;

      peaks[i] = peak;
    }

  sort(peaks.begin(), peaks.end());

  int rightmost = peaks[0].second;
  int ans = 1;
  
  for(int i = 1; i < n; i++)
    {
      if(peaks[i].second > rightmost)
      {
        ans++;
        rightmost = peaks[i].second;
      }
    }

  ofstream out("mountains.out");
  out << ans;
}
