#include <bits/stdc++.h>
using namespace std;

int N;

void solve()
{
  for (int line = 0; line < 2; ++line)
  {
    int hi = line == 0 ? N * 2 : N + 1, lo = 2 - line;
    for (int i = 0; i < N; ++i)
    {
      int num;
      if (i % 2 == line)
        num = hi, hi += line == 0 ? -2 : 2;
      else
        num = lo, lo += 2;

      cout << num;
      if (i < N - 1)
        cout << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    cin >> N;
    solve();
  }

  return 0;
}