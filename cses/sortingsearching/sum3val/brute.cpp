#include <bits/stdc++.h>
using namespace std;

vector<int> a(5000);

int main()
{
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 2; i < n; ++i)
    for (int j = 1; j < i; ++j)
      for (int k = 0; k < j; ++k)
        if (a[i] + a[j] + a[k] == x)
        {
          cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
          return 0;
        }

  cout << "IMPOSSIBLE\n";
  return 0;
}