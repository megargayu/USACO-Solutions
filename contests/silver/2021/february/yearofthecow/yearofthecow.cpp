#include <bits/stdc++.h>
using namespace std;

set<int> cycles;
vector<int> skippable;

int main()
{
  int N, K;
  cin >> N >> K;

  int y;
  for (int i = 0; i < N; ++i)
  {
    cin >> y;
    cycles.insert((y + 11) / 12);
  }

  int cycle = *cycles.rbegin(), lastCycle = 0;
  for (const int &cycle : cycles)
  {
    skippable.push_back(cycle - lastCycle - 1);
    lastCycle = cycle;
  }

  sort(skippable.begin(), skippable.end(), greater<int>());

  for (int i = 0; i < K - 1 && i < skippable.size(); ++i)
    cycle -= skippable[i];
  
  cout << cycle * 12 << '\n';

  return 0;
}
