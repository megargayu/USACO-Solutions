// https://codeforces.com/contest/276/problem/C

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long

vector<int> a(MAX_N);
vector<int> mult(MAX_N + 1);

int main()
{
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int l, r;
  for (int i = 0; i < q; ++i)
  {
    cin >> l >> r;
    --l, --r;
    ++mult[l];
    --mult[r + 1];
  }

  int curr = 0;
  for (int i = 0; i <= n; ++i)
  {
    curr += mult[i];
    mult[i] = curr;
  }

  sort(mult.begin(), mult.begin() + n, greater<int>());
  sort(a.begin(), a.begin() + n, greater<int>());

  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += (ll)mult[i] * (ll)a[i];

  cout << ans << '\n';

  return 0;
}