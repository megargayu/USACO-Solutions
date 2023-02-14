// https://codeforces.com/contest/1793/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5

int N;
vector<int> a(MAX_N);

void solve()
{
  int l = 0, r = N - 1;
  int cmin = 1, cmax = N;
  while (l < r)
  {
    // cout << l << ' ' << r << ' ' << cmin << ' ' << cmax << '\n';
    if (a[l] == cmin)
      ++l, ++cmin;
    
    else if (a[l] == cmax)
      ++l, --cmax;
    
    else if (a[r] == cmin)
      --r, ++cmin;
    
    else if (a[r] == cmax)
      --r, --cmax;

    else
      break;
  }

  if (l >= r)
    cout << "-1\n";
  else
    cout << l + 1 << ' ' << r + 1 << '\n';
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    cin >> N;
    for (int i = 0; i < N; ++i)
      cin >> a[i];
    
    solve();
  }

  return 0;
}
