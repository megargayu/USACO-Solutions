/*
ID: megarga1
TASK: holstein
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1e5

#define MAX_V 25
#define MAX_G 15

int V, G;
vector<int> target(MAX_V);
vector<vector<int>> feeds(MAX_G, vector<int>(MAX_V));

vector<int> feedUse(MAX_G, 0);

vector<int> ans(MAX_G, 1);

bool check()
{
  int curr;
  for (int i = 0; i < V; ++i)
  {
    curr = 0;
    for (int j = 0; j < G; ++j)
      curr += feeds[j][i] * feedUse[j];

    if (curr < target[i])
      return false;
  }

  return true;
}

void dfs(int feed)
{
  if (feed == G)
  {
    if (check())
    {
      
      int feedUseLen = accumulate(feedUse.begin(), feedUse.begin() + G, 0);
      int ansLen = accumulate(ans.begin(), ans.begin() + G, 0);
      if (feedUseLen < ansLen)
        ans = feedUse;
      else if (feedUseLen == ansLen)
      {
        int indexLenFeedUse = 0;
        int ansFeedUseLen = 0;

        for (int i = 0; i < G; ++i)
        {
          if (feedUse[i]) indexLenFeedUse += i + 1;
          if (ans[i]) ansFeedUseLen += i + 1;
        }

        if (indexLenFeedUse < ansFeedUseLen)
          ans = feedUse;
      }
    }

    return;
  }

  for (int i = 0; i < 2; ++i)
  {
    feedUse[feed] = i;
    dfs(feed + 1);
  }
}

int main()
{
  freopen("holstein.in", "r", stdin);
  freopen("holstein.out", "w", stdout);

  cin >> V;
  for (int i = 0; i < V; ++i)
    cin >> target[i];

  cin >> G;
  for (int i = 0; i < G; ++i)
    for (int j = 0; j < V; ++j)
      cin >> feeds[i][j];

  for (int i = 0; i < 2; ++i)
  {
    feedUse[0] = i;
    dfs(0);
  }

  cout << accumulate(ans.begin(), ans.begin() + G, 0);

  for (int i = 0; i < G; ++i)
    if (ans[i])
      cout << ' ' << i + 1;

  cout << '\n';

  return 0;
}
