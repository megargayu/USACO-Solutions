#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

int N;
vector<int> arr(MAX_N);
vector<bool> seen(MAX_N+1);
vector<int> ans;

int getMEX()
{
  fill_n(seen.begin(), N, false);
  for (int i = 0; i < N; ++i)
    seen[arr[i]] = true;

  for (int i = 0; i < N; ++i)
    if (!seen[i])
      return i;
  return N;
}

int main()
{
  int T;
  cin >> T;
  
  for (int t = 0; t < T; ++t)
  {
    cin >> N;
    int needToFix = 0;
    for (int i = 0; i < N; ++i)
    {
      cin >> arr[i];
      needToFix += (i != arr[i]);
    }

    ans.clear();
    while (true)
    {
      int mex = getMEX();
      if (mex == N)
      {
        if (needToFix == 0) break;

        for (int j = 0; j < N; ++j)
          if (arr[j] != j)
          {
            ans.push_back(j + 1);
            arr[j] = N;
            break;
          }
      }
      else
      {
        ans.push_back(mex + 1);
        arr[mex] = mex;
        --needToFix;
      }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}