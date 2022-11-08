// https://csacademy.com/contest/archive/task/sure-bet

#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5

vector<double> a(MAX), b(MAX);

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];

  sort(a.begin(), a.begin() + n, greater<double>());
  sort(b.begin(), b.begin() + n, greater<double>());

  double ans = 0;
  double valA = 0, valB = 0;
  int i = 0, j = 0;

  while (true)
  {
    if (valA > valB)
    {
      if (j == n) break;
      valB += b[j] - 1;
      --valA;
      ++j;
    }
    else
    {
      if (i == n) break;
      valA += a[i] - 1;
      --valB;
      ++i;
    }

    ans = max(ans, min(valA, valB));
  }

  printf("%.4lf", ans);

  return 0;
}
