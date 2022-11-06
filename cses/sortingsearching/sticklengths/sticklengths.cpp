#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long

vector<int> p(MAX_N);

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> p[i];

  sort(p.begin(), p.begin() + n);

  const int median = p[n / 2];
  
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += abs(median - p[i]);
  
  cout << ans << '\n';

  return 0;
}
