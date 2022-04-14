#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

vector<set<int>> reaches(MAX_N);
vector<int> cows(MAX_N), cycle(MAX_N, -1);
vector<int> ans(MAX_N);

int main()
{
  int N, K;
  cin >> N >> K;

  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cows[i] = i;
    reaches[i].insert(i);
  }

  for (int i = 0; i < K; ++i)
  {
    cin >> a >> b;
    --a, --b;

    reaches[cows[a]].insert(b);
    reaches[cows[b]].insert(a);
    swap(cows[a], cows[b]);
  }

  set<int> tmp;
  int curr = 0;
  for (int i = 0; i < N; ++i)
  {
    if (cycle[i] != -1) continue;

    tmp.clear();
    for (int x : reaches[i]) tmp.insert(x);
    cycle[i] = curr;

    for (int j = cows[i]; j != i;)
    {
      cycle[j] = curr;
      for (int x : reaches[j]) tmp.insert(x);
      j = cows[j];
    }

    ans[curr] = tmp.size();
    ++curr;
  }

  for (int i = 0; i < N; ++i)
    cout << ans[cycle[i]] << '\n';

  return 0;
}
