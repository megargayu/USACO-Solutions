#include <bits/stdc++.h>
using namespace std;

string s, t;
vector<int> timesFound(18), timesFound2(18);
int main()
{
  cin >> s >> t;

  for (int i = 0; i < s.size(); ++i)
    ++timesFound[s[i] - 'a'];
  for (int i = 0; i < t.size(); ++i)
    ++timesFound2[t[i] - 'a'];

  int Q;
  cin >> Q;

  string q;
  for (int query = 0; query < Q; ++query)
  {
    cin >> q;
    /*int sum = 0, sum2 = 0;
    for (int i = 0; i < q.size(); ++i)
      sum += timesFound[i];
    for (int i = 0; i < q.size(); ++i)
      sum2 += timesFound2[i];
    if (sum != sum2)
    {
      cout << 'N';
      continue;
    }*/

    int i = 0, j = 0;
    bool valid = true;
    while (i < s.size() && j < t.size())
    {
      while (i < s.size() && q.find(s[i]) == string::npos) ++i;
      while (j < t.size() && q.find(t[j]) == string::npos) ++j;

      if (i < s.size() && j < t.size() && s[i] != t[j])
      {
        valid = false;
        break;
      }
      ++i, ++j;
    }

    cout << (valid ? 'Y' : 'N');
  }
}
