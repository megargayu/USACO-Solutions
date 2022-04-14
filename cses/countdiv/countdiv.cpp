// https://cses.fi/problemset/task/1713
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int a;
  for (int q = 0; q < N; ++q)
  {
    cin >> a;
    int ans = 0;
    for (int i = 1; i * i <= a; ++i)
    {
      if (a % i == 0)
      {
        ans += (i * i != a) + 1;
      }
    }

    cout << ans << '\n';
  }
}
