#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// CodeForces problem Gravity Flip
// 900

vector<int> solve();

int main() {
  solve();
}

vector<int> solve() {
  int n;
  cin >> n;
  vector<int> nums(n);

  for(int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  for(int i : nums) {
    cout << i << " ";
  }
  return nums;
}
