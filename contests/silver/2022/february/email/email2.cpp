#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5
#define MAX_M 1e4

list<int> emails;
vector<int> needToBeFiled(MAX_M);
int main()
{
  int T;
  cin >> T;

  int M, N, K;
  for (int t = 0; t < T; ++t)
  {
    cin >> M >> N >> K;
    emails.clear();
    fill(needToBeFiled.begin(), needToBeFiled.end(), false);

    int a;
    for (int i = 0; i < N; ++i)
    {
      cin >> a;
      emails.push_back(a - 1);
      ++needToBeFiled[a - 1];
    }

    // folder window is from folderStart ... folderStart + K
    int folderStart = 0;

    // email window is from emailStart ... emailStart + K, and "it" is the current element being checked.
    auto it = emails.begin();
    int curr = 0;

    while (it != emails.end())
    {
      for (int i = 0; i < K && curr < N && it != emails.end();)
      {
        if (folderStart <= *it && *it < folderStart + K) // can file this, so file it
        {
          --needToBeFiled[*it];
          for (; folderStart < M && needToBeFiled[folderStart] == 0; ++folderStart);
          //cout << i << '\n';
          it = emails.erase(it);

          if (folderStart == M) break;
        }
        else
        {
          ++it; ++i;
        }
      }
    }

    if (emails.size() == 0) cout << "YES\n";
    else cout << "NO\n";
  }
  

  return 0;
}