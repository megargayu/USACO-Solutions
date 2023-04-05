#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define INF (1111000000ll)
#define QUESTION INF
#define ll long long

ll n, k;
vector<ll> a(MAX_N+100);
vector<ll> end_range(MAX_N+100);

ll get_start_of_cluster(ll lo, ll hi, ll num)
{
  if (hi - lo - 1 < num)
    return INF; // impossible

  if (lo >= 0 && hi > 0)
    return lo + 1; // closest cluster to 0 starts at lo + 1

  if (lo < 0 && hi <= 0)
    return hi - num;

  // lo is negative and hi is positive (neither is 0, either)
  assert(lo < 0 && hi > 0);
  
  // create initial cluster 
  // num = 4 -> -2, -1, 0, 1
  // num = 5 -> -2, -1, 0, 1, 2
  int start = 0 - num / 2;

  // create an offset if required 
  if (start <= lo)
    start = lo + 1;
  else if (start + num - 1 >= hi)
    start = hi - num;

  return start;
}

bool solve(ll offset)
{
  for (int i = offset; i < n; i += k)
  {
    ll lo = i >= k ? a[i - k] : -INF;
    ll hi = i <= n - k - 1 ? a[i + k] : INF;

    // solve this range 
    if (a[i] == QUESTION)
    {
      hi = end_range[i] <= n - k - 1 ? a[end_range[i] + k] : INF;

      ll num = (end_range[i] - i) / k + 1;
      ll start = get_start_of_cluster(lo, hi, num);
      if (start == INF)
        return false;

      for (int j = i; j <= end_range[i] && j < n; j += k)
      {
        a[j] = start;
        ++start;
      }

      i = end_range[i] + k;
    }
    // check if this `i` is valid
    else
    {
      if (!(lo < a[i] && a[i] < hi))
        return false;
    }
  }

  return true;
}

int main()
{
  cin >> n >> k;

  string s;
  for (int i = 0; i < n; ++i)
  {
    cin >> s;
    if (s == "?") a[i] = QUESTION;
    else a[i] = stoll(s);
  }

  for (int offset = 1; offset <= k; ++offset)
  {
    // populate end_range of n - i...0
    int currEnd = -1;
    for (int j = n - offset; j >= 0; j -= k)
    {
      // cout << j << '\n';
      if (currEnd == -1 && a[j] == QUESTION)
        currEnd = j;
      else if (currEnd != -1 && a[j] != QUESTION)
        currEnd = -1;

      end_range[j] = currEnd;
    }
  }

  for (int i = 0; i < k; ++i)
    if (!solve(i))
    {
      cout << "Incorrect sequence\n";
      return 0;
    }

  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << '\n';

  return 0;
}
