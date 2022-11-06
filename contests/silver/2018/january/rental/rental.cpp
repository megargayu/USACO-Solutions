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

  int i;
  for (i = 0; i < N; ++i)
    fin >> cows[i];

  ll totalUnits = 0;
  for (i = 0; i < M; ++i)
  {
    fin >> stores[i].quantity >> stores[i].money;
    totalUnits += stores[i].quantity;
  }

  for (i = 0; i < R; ++i)
    fin >> rentals[i];

  sort(cows.begin(), cows.begin() + N, greater<int>());
  sort(stores.begin(), stores.begin() + M, [](const auto &a, const auto &b)
       { return a.money > b.money; });
  sort(rentals.begin(), rentals.begin() + R);

  ll ans = 0;
  ll curr = 0;
  for (i = R - 1; i >= R - min(R, N); --i)
    curr += rentals[i];
  ans = max(ans, curr);

  // if we can milk more than we can sell out of the first N - R
  // cows, then sell the first N - R cows and rent the rest of the R cows
  ll totalCowMilk = 0;
  for (int i = 0; i < N - R; ++i)
    totalCowMilk += cows[i];

  if (totalCowMilk >= totalUnits)
  {
    for (int i = 0; i < M; ++i)
      curr += stores[i].quantity * stores[i].money;
    fout << curr << '\n';
    return 0;
  }

  // try renting out all cows
  ll rent = 0;
  for (int i = 0; i < min(R, N); ++i)
    rent += rentals[i];
  ans = max(ans, rent);

  ll milked = 0;
  int storeI = 0, rentalsI = N < R ? R - N : 0;
  for (int i = 0; i < N; ++i)
  {
    // cow 0..i are milked (inclusive) and cows (i+1)..(n-1) are rented out (inclusive)
    ll milkSold = milked;
    milked += cows[i];

    while (storeI < M)
    {
      Store &store = stores[storeI];
      const int units = store.quantity - store.bought;

      // this is the last store we can sell to, sell and break out of loop
      if (milkSold + units >= milked)
      {
        const int unitsToSell = milked - milkSold;
        store.bought += unitsToSell;
        curr += unitsToSell * store.money;
        milkSold = milked;
        break;
      }

      // sell everything to this store and continue
      curr += units * store.money;
      store.bought = store.quantity;
      milkSold += units;
      ++storeI;
    }

    if (i >= N - R)
    {
      curr -= rentals[rentalsI];
      ++rentalsI;
    }

    ans = max(ans, curr);
  }

  fout << ans << '\n';

  return 0;
}
