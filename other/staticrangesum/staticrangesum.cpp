// https://judge.yosupo.jp/problem/static_range_sum

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500000
#define ll long long

vector<ll> ps(MAX_N + 1);

int main()
{
  int N, Q;
  cin >> N >> Q;

  ps[0] = 0;

  int a, b;
  for (int i = 1; i <= N; ++i)
  {
    cin >> a;
    ps[i] = ps[i - 1] + a;
  }

  for (int i = 0; i < Q; ++i)
  {
    cin >> a >> b;
    cout << ps[b] - ps[a] << '\n';
  }

  return 0;
}
