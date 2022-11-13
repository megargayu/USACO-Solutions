#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<int> bales(MAX_N);

int main()
{
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);

  int N, Q;
  cin >> N >> Q;

  for (int i = 0; i < N; ++i)
    cin >> bales[i];

  sort(bales.begin(), bales.begin() + N);

  int a, b;
  for (int i = 0; i < Q; ++i)
  {
    cin >> a >> b;
    auto l = lower_bound(bales.begin(), bales.begin() + N, a);
    auto r = upper_bound(bales.begin(), bales.begin() + N, b);
    --r;

    const int li = l - bales.begin();
    const int ri = r - bales.begin();

    cout << ri - li + 1 << '\n';
  }

  return 0;
}
