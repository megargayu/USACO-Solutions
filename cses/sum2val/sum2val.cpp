#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000
#define ll long long

array<pair<ll, int>, MAX_N> arr;
int main()
{
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  
  sort(arr.begin(), arr.begin() + n, [](const auto &a, const auto &b)
  {
    return a.first < b.first;
  });

  int i = 0, j = n - 1;
  while (i < j)
  {
    if      (arr[i].first + arr[j].first < x) ++i;
    else if (arr[i].first + arr[j].first > x) --j;
    else
    {
      cout << arr[i].second + 1 << ' ' << arr[j].second + 1 << '\n';
      return 0;
    }
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}
