// https://cses.fi/problemset/task/1091

#include <iostream>
#include <string>

#include <set>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  multiset<int> tickets{};
  int price;
  for (int i{0}; i < n; ++i)
  {
    cin >> price;
    tickets.insert(price);
  }

  for (int i{0}; i < m; ++i)
  {
    if (tickets.size() == 0)
    {
      cout << "-1\n";
      continue;
    }
    cin >> price;
    auto maximumMin{tickets.lower_bound(price)};
    if (maximumMin == tickets.end())
      --maximumMin;

    if (maximumMin == tickets.begin() && *maximumMin > price)
      cout << "-1\n";
    else
    {
      if (*maximumMin > price)
        --maximumMin;
      cout << *maximumMin << '\n';
      tickets.erase(maximumMin);
    }
  }

  return 0;
}
