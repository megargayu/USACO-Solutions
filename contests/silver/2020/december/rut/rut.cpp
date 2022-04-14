#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define x first
#define y second

vector<int> eCows, nCows;
vector<int> ans(MAX_N);
vector<bool> stopped(MAX_N);
vector<pair<int, int>> loc(MAX_N);
int main()
{
  int N;
  cin >> N;

  char c;
  for (int i = 0; i < N; ++i)
  {
    cin >> c;
    if (c == 'E') eCows.push_back(i);
    else nCows.push_back(i);
    cin >> loc[i].x >> loc[i].y;
  }

  sort(eCows.begin(), eCows.end(), [&](const int &a, const int &b)
  { return loc[a].y < loc[b].y; });
  sort(nCows.begin(), nCows.end(), [&](const int &a, const int &b)
  { return loc[a].x < loc[b].x; });

  for (const int &j : eCows)
    for (const int &k : nCows)
    {
      if (!stopped[j] && !stopped[k] && loc[k].x > loc[j].x && loc[j].y > loc[k].y)
      {
        if (loc[k].x - loc[j].x > loc[j].y - loc[k].y) {
          stopped[j] = true;
          ans[k] += 1 + ans[j];
        } else if (loc[j].y - loc[k].y > loc[k].x - loc[j].x) {
          stopped[k] = true;
          ans[j] += 1 + ans[k];
        }
      }
    }
  
  for (int i = 0; i < N; ++i)
    cout << ans[i] << '\n';

  return 0;
}
