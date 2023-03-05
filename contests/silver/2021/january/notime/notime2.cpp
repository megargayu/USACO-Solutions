#include <bits/stdc++.h>
using namespace std;

#define MAX_NQ 1e5

int N, Q;
string s;
vector<int> prefix(MAX_NQ), suffix(MAX_NQ);

void precomute(vector<int> &ans)
{
  stack<char> intervals;
  ans[0] = 1;
  intervals.push(s[0]);
  for (int i = 1; i < N; ++i)
  {
    while (intervals.size() > 0 && intervals.top() > s[i])
      intervals.pop();

    ans[i] = ans[i - 1] + (intervals.size() == 0 || intervals.top() != s[i]);
    intervals.push(s[i]);
  }
}

int main()
{
  cin >> N >> Q;
  cin >> s;

  precomute(prefix);
  reverse(s.begin(), s.end());
  precomute(suffix);

  int a, b;
  for (int i = 0; i < Q; ++i)
  {
    cin >> a >> b;
    --a, --b;
    cout << (a == 0 ? 0 : prefix[a - 1]) + 
            (b == N - 1 ? 0 : suffix[N - b - 2]) << '\n';
  }

  return 0;
}