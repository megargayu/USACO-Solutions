// https://codeforces.com/contest/1791/problem/F

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_NQ 2e5

int N, Q;
vector<ll> a(MAX_NQ+100);

set<int> num_done;

void update(int i)
{
  int ans = 0;
  while (a[i] > 0)
  {
    ans += a[i] % 10ll;
    a[i] /= 10ll;
  }

  a[i] = ans;
}

void solve()
{
  cin >> N >> Q;

  for (int i = 0; i < N; ++i)
    cin >> a[i];

  for (int i = 0; i < N; ++i)
    num_done.insert(i);

  int type, l, r;
  for (int i = 0; i < Q; ++i)
  {
    cin >> type;
    if (type == 1)
    {
      cin >> l >> r;
      --l, --r;

      // max of O(3 * N)
      while (true)
      {
        auto it = num_done.lower_bound(l);
        if (it == num_done.end() || *it > r)
          break;

        update(*it);

        l = *it + 1;

        if (a[*it] / 10ll == 0)
          num_done.erase(it);
      }
    }
    else
    {
      cin >> l;
      cout << a[l - 1] << '\n';
    }
  }
}

int main()
{
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}

