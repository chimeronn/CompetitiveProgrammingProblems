#include <iostream>
#include <queue>
using namespace std;

// CodeForces problem Two Buttons
// 1400

long long solve(int, int);

int main() {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m);
}

long long solve(int start, int target) {
  int numMult = 0;
  long long startClone = start;
  while(startClone < target) {
    ++numMult;
    startClone *= 2;
  }
  if(target <= start) {
    return start - target;
  }
  if(target % 2 == 0) return min(startClone - target + numMult, solve(start, target / 2) + 1);
  else return min(startClone - target + numMult, solve(start, (target + 1) / 2) + 2);
}
