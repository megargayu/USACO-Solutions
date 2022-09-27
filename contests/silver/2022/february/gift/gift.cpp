#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500

vector<vector<int>> wishlists(MAX_N, vector<int>(MAX_N));
int N;

bool willingToSwitch(int cow, int source)
{
  for (int i = 0; i < N && wishlists[cow][i] != cow; ++i)
    if (wishlists[cow][i] == source) // cow wants the source gift more than it's currently assigned one
      return true;
  return false;
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      cin >> wishlists[i][j];
      --wishlists[i][j];
    }
  
  for (int cow = 0; cow < N; ++cow)
  {
    int answer = cow;
    for (int i = 0; i < N && wishlists[cow][i] != cow; ++i)
    {
      if (willingToSwitch(wishlists[cow][i], cow))
      {
        answer = wishlists[cow][i];
        break;
      }
    }
    cout << answer + 1 << '\n';
  }

  return 0;
}
