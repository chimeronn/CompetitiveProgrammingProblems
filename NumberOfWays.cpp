#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// CodeForces problem Number Of Ways
// 1700

long long solve();

int main() {
  cout << solve();
}

long long solve() {
  int n;
  cin >> n;
  vector<long long> pfx(n + 1);
  pfx[0] = 0;

  for(int i = 1; i < n + 1; ++i) {
    cin >> pfx[i];
    pfx[i] += pfx[i - 1];
    //cout << pfx[i] << " ";
  }

  if(pfx[pfx.size() - 1] % 3) return 0;
  long long target = pfx[pfx.size() - 1] / 3;
  //cout << target;

  int right = pfx.size() - 2;
  stack<int> st;

  while(right > 1) {
    long long rightSum = pfx[pfx.size() - 1] - pfx[right];
    if(rightSum == target) st.push(right);
    //if(rightSum == target) cout << right << " ";
    right--;
  }

  int left = 1;
  long long ans = 0;
  while(left < pfx.size() - 2 && !st.empty()) {
    if(left >= st.top()) st.pop();
    long long leftSum = pfx[left];
    if(leftSum == target) {
      //cout << left << " ";
      ans += st.size();
    }
    left++;
  }
  return ans;
}
