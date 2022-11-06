// https://cses.fi/problemset/task/1641

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 5000

vector<pair<int, int>> a(MAX_N);

int main()
{
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
    cin >> a[i].first, a[i].second = i + 1;

  sort(a.begin(), a.begin() + n, [](const auto &a, const auto &b)
       { return a.first < b.first; });

  for (int i = 0; i < n; ++i)
  {
    const int need = x - a[i].first;
    int l = 0, r = n - 1;
    while (l != r)
    {
      if (l != i && r != i && a[l].first + a[r].first == need)
      {
        cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << '\n';
        return 0;
      }

      if (a[l].first + a[r].first < need)
        ++l;
      else
        --r;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}