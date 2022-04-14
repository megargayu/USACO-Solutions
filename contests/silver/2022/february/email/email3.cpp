#include <bits/stdc++.h>
using namespace std;

#define MAX_M 1e4

struct IndexedIterator
{
  int i;
  list<int>::iterator it;

  IndexedIterator(list<int> &l): i(0), it(l.begin()) {}
  IndexedIterator& operator++() { ++i; ++it; return *this; }
  IndexedIterator& operator--() { --i; --it; return *this; }
  int operator*() const noexcept { return *it; }
};

vector<int> leftToFile(MAX_M);
list<int> emails;
int main()
{
  int T;
  cin >> T;

  int M, N, K;

  for (int t = 0; t < T; ++t)
  {
    emails.clear();
    fill(leftToFile.begin(), leftToFile.end(), false);

    cin >> M >> N >> K;

    int a;
    for (int i = 0; i < N; ++i)
    {
      cin >> a;
      emails.push_back(a - 1);
      ++leftToFile[a - 1];
    }

    IndexedIterator iit(emails), start(emails);
    int folderStart = 0, emailStart;

    const auto update = [&]()
    {
      if (folderStart <= *iit && *iit < folderStart + K)
      {
        --leftToFile[*iit];
        
        // check all emails before this as we updated the folder start
        if (leftToFile[folderStart] == 0)
        {
          for (; folderStart < M && leftToFile[folderStart] == 0; ++folderStart);
          IndexedIterator copy = iit;
          iit = start;
          while (iit.i < copy.i)
            if ()
        }

        iit.it = emails.erase(iit.it);
        return true;
      }

      return false;
    };

    while (iit.i < K) 
      if (!update()) ++iit;

    while (iit.it != emails.end())
      if (!update()) ++iit, ++emailStart, ++start;

    --iit;
    while (iit.i >= emails.size() - K)
    {
      update();
      --iit;
    }

    while (update()) --iit;
    
    cout << (emails.size() == 0 ? "YES\n" : "NO\n");
  }

  return 0;
}
