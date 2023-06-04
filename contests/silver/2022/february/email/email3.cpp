#include <bits/stdc++.h>
using namespace std;

#define MAX_M 1e4

// TODO

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

    const function<bool()> update = [&]()
    {
      if (folderStart <= *iit && *iit < folderStart + K)
      {
        --leftToFile[*iit];
        
        // check all emails before this as we updated the folder start
        while (leftToFile[folderStart] == 0 && folderStart < M)
        {
          for (; folderStart < M && leftToFile[folderStart] == 0; ++folderStart);
          for (IndexedIterator iit2 = start; iit2.i < start.i + min(iit.i, K) && iit2.it != emails.end();)
          {
            cout << "done" << endl;
            if (folderStart <= *iit2 && *iit2 < folderStart + K)
            {
              --leftToFile[*iit2];

              cout << *iit2 << endl;
              //bool setStart = (start.it == iit2.it);
              //bool setIit = (iit.it == iit2.it);
              iit2.it = emails.erase(iit2.it);
              //if (setStart) start.it = iit2.it;
              //if (setIit) iit.it = iit2.it;
              //cout << *iit2 << endl;
            }
            else ++iit2;
            cout << "donex2" << endl;
          }
        }

        bool setStart = (start.it == iit.it);
        iit.it = emails.erase(iit.it);
        if (setStart) start.it = iit.it;

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
