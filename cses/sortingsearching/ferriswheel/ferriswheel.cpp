// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

vector<int> p(MAX_N);

int main()
{
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
    cin >> p[i];

  sort(p.begin(), p.begin() + n);

  int j = n - 1, ans = 0;
  for (int i = 0; i <= n / 2; ++i)
  {
    while (j > i && p[i] + p[j] > x)
    {
      --j;
      ++ans;
    }
    
    ++ans;

    if (j <= i)
    {
      ans -= i - j;
      break;
    }

    --j;
  }

  cout << ans << '\n';

  return 0;
}