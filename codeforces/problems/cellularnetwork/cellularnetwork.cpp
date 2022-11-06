// https://codeforces.com/contest/702/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5

vector<int> a(MAX), b(MAX);
vector<int> dist(MAX, 2e9);

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    cin >> a[i];
  
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  int j = 0;
  for (int i = 0; i < n; ++i)
  {
    while (j < m - 1 && b[j + 1] <= a[i]) ++j;
    dist[i] = min(dist[i], abs(a[i] - b[j]));
  }

  j = m - 1;
  for (int i = n - 1; i >= 0; --i)
  {
    while (j > 0 && b[j - 1] >= a[i]) --j;
    dist[i] = min(dist[i], abs(a[i] - b[j]));
  }

  cout << *max_element(dist.begin(), dist.begin() + n) << '\n';

  return 0;
}

