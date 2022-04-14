#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5 + 3

vector<int> numTimes(MAX_N);
list<int> emails;
int main()
{
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t)
  {
    emails.clear();
    fill(numTimes.begin(), numTimes.end(), 0);

    int M, N, K;
    cin >> M >> N >> K;

    int a;
    for (int i = 0; i < N; ++i)
    {
      cin >> a;
      emails.push_back(a - 1);
      ++numTimes[a - 1];
    }
    
    auto it = emails.begin();
    int folder = 0, i = 0;

    for (; it != emails.end();)
    {
      for (int j = 0; j < K;)
      {
        if (it == emails.end()) break;
        if (folder <= *it && *it < folder + K)
        {
          --numTimes[*it];
          while (numTimes[folder] == 0) ++folder;
          it = emails.erase(it);

          if (K > emails.size())
          {
            it = emails.begin();
            i = 0;
          } else if (i + K > emails.size())
          {
            --it;
            --i;
          }
        }
        else
        {
          ++it;
          ++i;
          ++j;
        }
      }
    }

    if (emails.size() == 0) cout << "YES\n";
    else cout << "NO\n";
  }
  

  return 0;
}
