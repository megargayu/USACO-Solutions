#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

array<int, MAX_N> prefix, suffix;
array<bool, 26> seen;
int main()
{
  int N, Q;
  cin >> N >> Q;

  std::string fence;
  cin >> fence;
  
  prefix[0] = 1;
  seen.fill(false);
  seen[fence[0] - 'A'] = true;
  for (int i = 1; i < N; ++i)
  {
    if      (fence[i] >  fence[i - 1]) prefix[i] = prefix[i - 1] + 1;
    else if (fence[i] == fence[i - 1]) prefix[i] = prefix[i - 1];
    else
    {
      if (seen[fence[i] - 'A']) prefix[i] = prefix[i - 1];
      else                      prefix[i] = prefix[i - 1] + 1;
    }

    for (int j = fence[i] - 'A'; j < 26; ++j) seen[j] = false;
    seen[fence[i] - 'A'] = true;
  }

  suffix[N - 1] = 1;
  seen.fill(false);
  seen[fence[N - 1] - 'A'] = true;
  for (int i = N - 2; i >= 0; --i)
  {
    if      (fence[i] >  fence[i + 1]) suffix[i] = suffix[i + 1] + 1;
    else if (fence[i] == fence[i + 1]) suffix[i] = suffix[i + 1];
    else
    {
      if (seen[fence[i] - 'A']) suffix[i] = suffix[i + 1];
      else                      suffix[i] = suffix[i + 1] + 1;
    }

    for (int j = fence[i] - 'A'; j < 26; ++j) seen[j] = false;
    seen[fence[i] - 'A'] = true;
  }

  int a, b;
  for (int i = 0; i < Q; ++i)
  {
    cin >> a >> b;
    --a, --b;
    cout << (a == 0 ? 0 : prefix[a - 1]) + 
            (b == N - 1 ? 0 : suffix[b + 1]) << '\n';
  }

  return 0;
}