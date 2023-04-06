// https://codeforces.com/contest/1538/problem/F

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;

  int l, r;
  while (t--)
  {
    cin >> l >> r;

    int ans = 0;
    for (int i = 1; i <= r; i *= 10)
      ans += (r / i) - (l / i);

    cout << ans << '\n';
  }

  return 0;
}
