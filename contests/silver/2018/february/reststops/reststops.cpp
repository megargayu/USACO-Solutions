#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define ll long long

vector<int> x(MAX_N), t(MAX_N);
vector<bool> isMax(MAX_N);

int main()
{
  freopen("reststops.in", "r", stdin);
  freopen("reststops.out", "w", stdout);

  int L, N, rf, rb;
  cin >> L >> N >> rf >> rb;

  for (int i = 0; i < N; ++i)
    cin >> x[i] >> t[i];

  int max = 0;
  for (int i = N - 1; i >= 0; --i)
    if (t[i] > max)
    {
      isMax[i] = true;
      max = t[i];
    }
  
  ll ans = 0;
  int lastX = 0;
  for (int i = 0; i < N; ++i)
    if (isMax[i])
    {
      const ll fpos = (x[i] - lastX) * (ll)rf;
      const ll bpos = (x[i] - lastX) * (ll)rb;
      ans += (fpos - bpos) * (ll)t[i];
      lastX = x[i];
    }

  cout << ans << '\n';

  return 0;
}