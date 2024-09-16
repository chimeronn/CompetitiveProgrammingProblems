//9 out of 10 Test Cases Passed
//Silver

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool cmpStore(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}

int main() {
  fstream file("rental.in");

  int n, m, r;

  file >> n >> m >> r;

  vector<int> milk(n);
  vector<pair<int, int>> stores(m);
  vector<int> neighbors(r);

  for(int i = 0; i < n; i++)
    {
      file >> milk[i];
    }

  for(int i = 0; i < m; i++)
    {
      pair<int, int> store;
      file >> store.first >> store.second;

      stores[i] = store;
    }

  for(int i = 0; i < r; i++)
    {
      file >> neighbors[i];
    }

  sort(milk.begin(), milk.end(), greater<int>());
  sort(stores.begin(), stores.end(), cmpStore);
  sort(neighbors.begin(), neighbors.end(), greater<int>());

  long long ans = 0;
  pair<int, int> currStore = stores[0];
  int storeIndex = 0;
  for(int i = 0; i < n; i++)
    {
      int milkAmt = 0;
      int sellAmt = 0;

      int cowsLeft = min(n - i, r);
      sellAmt = neighbors[cowsLeft - 1];

      int numMilk = milk[i];
      pair<int, int> tempStore = currStore;
      int tempStoreIndex = storeIndex;
      while(numMilk > 0)
        {
          int milkSold = min(numMilk, tempStore.first);
          tempStore.first -= milkSold;
          milkAmt += milkSold * tempStore.second;

          numMilk -= milkSold;
          if(tempStore.first == 0)
          {
            tempStoreIndex++;
            tempStore = stores[tempStoreIndex];
          }
        }

      if(milkAmt > sellAmt)
      {
        ans += milkAmt;
        currStore = tempStore;
        storeIndex = tempStoreIndex;
      }
      else{
        ans += sellAmt;
      }
    }

  ofstream out("rental.out");
  out << ans;
}
