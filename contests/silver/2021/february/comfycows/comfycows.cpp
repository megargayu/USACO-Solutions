#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

const array<int, 4> dx{0, 1, 0, -1},
                    dy{1, 0, -1, 0};

array<array<bool, 2000>, 2000> arr;
queue<pair<int, int>> q;
int ans = 0;

void check(pair<int, int> loc)
{
  if (!arr[loc.first][loc.second]) return;
  pair<int, int> res;
  int numFound = 0;
  for (int i = 0; i < 4; ++i)
  {
    if (arr[loc.first + dx[i]][loc.second + dy[i]]) ++numFound;
    else res = {loc.first + dx[i], loc.second + dy[i]};
  }
  
  // if comfy, add remaining space
  if (numFound == 3) q.push(res);
}

int main()
{
  int N;
  cin >> N;

  pair<int, int> loc;
  for (int i = 0; i < N; ++i)
  {
    cin >> loc.first >> loc.second;
    loc.first += 500, loc.second += 500;
    q.push(loc);
    while (!q.empty())
    {
      const auto &loc = q.front(); q.pop();
      if (arr[loc.first][loc.second]) continue;
      ++ans; arr[loc.first][loc.second] = true;
      check(loc);
      for (int i = 0; i < 4; ++i)
        check({loc.first + dx[i], loc.second + dy[i]});
    }

    cout << ans - i - 1 << '\n';
  }

  return 0;
}
