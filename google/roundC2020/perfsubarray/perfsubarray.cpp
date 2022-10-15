// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define ll long long

// maximum sum is 1e5 * 100 = 1e7, so the last possible square is 3162^2 = 9998244
#define LAST_PERF_SQ 3162

#define OFFSET 2e7 + 5

vector<int> perfSqs(LAST_PERF_SQ + 1);
vector<int> ps(MAX_N + 1);
vector<int> seen(4 * MAX_N * 100 + 1000);

int main()
{
  for (int i = 0; i <= LAST_PERF_SQ; ++i)
    perfSqs[i] = i * i;

  int T;
  cin >> T;

  int N;
  int x;
  for (int t = 1; t <= T; ++t)
  {
    cin >> N;

    ps[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
      cin >> x;
      ps[i] = ps[i - 1] + x;
    }

    fill(seen.begin(), seen.end(), 0);
    seen[0 + OFFSET] = 1;

    ll ans = 0;
    for (int i = 1; i <= N; ++i)
    {
      for (int s = 0; s <= LAST_PERF_SQ; ++s)
      {
        // ps[i] - x = perfSqs[s]
        // -x = perfSqs[s] - ps[i]
        // x = ps[i] - perfSqs[s]
        const int needToGet = ps[i] - perfSqs[s];
        const int num = seen[needToGet + OFFSET];
        if (num != 0)
          ans += num;
      }

      ++seen[ps[i] + OFFSET];
    }

    cout << "Case #" << t << ": " << ans << '\n';
  }

  return 0;
}
