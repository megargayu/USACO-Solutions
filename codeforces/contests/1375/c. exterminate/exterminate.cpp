#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;

  int N, a, b;
  for (int t = 0; t < T; ++t)
  {
    cin >> N >> a;
    for (int i = 1; i < N; ++i) cin >> b;
    cout << (a < b ? "YES\n" : "NO\n");
  }

  return 0;
}
