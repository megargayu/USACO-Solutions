#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<int> c(MAX_N);

int main()
{
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  int N;
  cin >> N;

  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    cin >> a >> b;
    --a, --b;
    ++c[a], ++c[b];
  }

  int ans = *max_element(c.begin(), c.begin() + N) + 1;
  cout << ans << '\n';
}