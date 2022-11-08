// https://codeforces.com/contest/862/problem/E

#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5
#define ll long long

vector<int> a(MAX), b(MAX);

// bij[j] is the sum of b_{i+j}
vector<ll> bij(MAX);

int main()
{
  // 0. input
  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i)
    cin >> a[i];
  
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  // 1. compute z and b[0]
  ll z = 0;
  bij[0] = 0;
  int sign = 1;
  for (int i = 0; i < n; ++i)
  {
    z += sign * a[i];
    bij[0] += sign * b[i];
    sign *= -1;
  }

  // 2. compute b_{i+j} for all j using sliding window
  int l = 0, r = n - 1;
  for (int j = 1; j <= m - n; ++j)
  {
    if (l % 2 == 0) // b[l] was added, so subtract it
      bij[j] = bij[j - 1] - b[l];
    else // b[l] was subtracted, so add it
      bij[j] = bij[j - 1] + b[l];
    
    if ((r + 1) % 2 == 0)
      bij[j] += b[r + 1];
    else
      bij[j] -= b[r + 1];
    
    ++l, ++r;
  }

  // we need to flip the signs because when calculating bij the first element
  // is always negative, which is not accounted for in the sliding window
  for (int j = 1; j <= m - n; j += 2)
    bij[j] *= -1;

  // 3. print out best j without any updates
  sort(bij.begin(), bij.begin() + (m - n + 1));

  const auto getMin = [&m, &n](const ll &z)
  {
    auto ge = lower_bound(bij.begin(), bij.begin() + (m - n + 1), z);
    if (ge == bij.begin() + (m - n + 1)) --ge;

    ll result = abs(z - *ge);

    if (ge != bij.begin())
      result = min(result, abs(z - *(--ge)));

    return result;
  };

  ll ans = getMin(z);
  cout << ans << '\n';

  // 4. handle queries
  int x;
  for (int i = 0; i < q; ++i)
  {
    cin >> l >> r >> x;
    
    if ((r - l + 1) % 2 == 1)
    {
      // have to either add one more or subtract one more
      if (l % 2 == 1)
        z += x;
      else
        z -= x;
    }

    cout << getMin(z) << '\n';
  }

  return 0;
}