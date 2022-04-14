#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 100000

struct Store
{
  int quantity, money, bought = 0;
};

array<int, MAX> cows;
array<Store, MAX> stores;
array<int, MAX> rentals;
int main()
{
  ifstream fin("rental.in");
  ofstream fout("rental.out");
  int N, M, R;
  fin >> N >> M >> R;

  int i; ll rentedMoney = 0;
  for (i = 0; i < N; ++i) fin >> cows[i];
  for (i = 0; i < M; ++i) fin >> stores[i].quantity >> stores[i].money;
  for (i = 0; i < R; ++i) fin >> rentals[i], rentedMoney += rentals[i];

  sort(cows.begin(), cows.begin() + N, greater<int>());
  sort(stores.begin(), stores.begin() + M, [](const auto &a, const auto &b)
  { return a.money > b.money; });
  sort(rentals.begin(), rentals.begin() + R);

  if (R + M <= N)
  {
    ll ans = rentedMoney;
    for (int i = 0; i < M; ++i)
      ans += stores[i].quantity * stores[i].
  }

  // TODO: check if R > M or R < M
  // rent out worst cows
  ll soldMoney = 0;
  for (int i = 0; i < N; ++i)
  {
    
  }

  ll maxMoney = rentedMoney;
  int gMilked = 0, gSold = 0, currStore = 0;
  for (int currMilked = 0; currMilked < N; ++currMilked)
  {
    gMilked += cows[currMilked];
    while (gSold < gMilked)
    {
      if (stores[currStore].quantity <= gMilked - gSold)
      { // sell all the milk possible to this store if we can
        gSold += stores[currStore].quantity - stores[currStore].bought;
        soldMoney += (stores[currStore].quantity - stores[currStore].bought) * stores[currStore].money;
        stores[currStore].bought = stores[currStore].quantity;
        ++currStore;
      } else
      { // otherwise, just sell the rest of the milk to this store
        soldMoney += (gMilked - gSold) * stores[currStore].money;
        gSold = gMilked;
      }
    }
    rentedMoney -= rentals[currMilked];
    cout << gMilked << ' ' << rentedMoney << ' ' << soldMoney << '\n';

    maxMoney = max(maxMoney, soldMoney + rentedMoney);
  }
  cout << maxMoney << '\n';

  return 0;
}
