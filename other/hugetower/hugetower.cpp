// https://oj.uz/problem/view/CEOI10_tower

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD ((ll)1e9 + 9)
#define MAX_N 1e7

vector<int> a(MAX_N);

int main()
{
  int N, D;
  cin >> N >> D;

  for (int i = 0; i < N; ++i)
    cin >> a[i];

  sort(a.begin(), a.begin() + N);

  ll ans = 1;
  int j = 0;
  for (int i = 0; i < N; ++i)
  {
    while (j < N - 1 && a[j + 1] - a[i] <= D) ++j;
    ans = (ans * static_cast<ll>(j - i + 1)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
