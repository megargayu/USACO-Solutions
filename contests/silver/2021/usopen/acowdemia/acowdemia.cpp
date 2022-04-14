#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define ll long long

int N, K, L;
vector<int> citations(MAX_N);
bool valid(int h)
{
  ll need = 0;
  int maxA = 0;

  for (int i = 0; i < h; ++i)
    if (citations[i] < h)
    {
      need += h - citations[i];
      maxA = max(maxA, h - citations[i]);
    }
  
  if (maxA > K) return false; // cannot use more than K articles

  return static_cast<ll>(K) * static_cast<ll>(L) >= need;
}

int main()
{
  cin >> N >> K >> L;

  for (int i = 0; i < N; ++i)
    cin >> citations[i];

  sort(citations.begin(), citations.begin() + N, greater<int>());
  
  int lo = 0, hi = N, mid, ans;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (valid(mid))
    {
      ans = mid;
      lo = mid + 1;
    }
    else hi = mid - 1;
  }

  cout << ans << '\n';

  return 0;
}
