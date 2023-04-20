#include <bits/stdc++.h>
using namespace std;

// number of 2's present in index i
vector<int> num_2(2e5 + 10);

void solve()
{
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
    
  int counter = n;
  for (int i = 0; i < n; ++i)
    counter -= __builtin_ctz(a[i]);

  counter = max(counter, 0);

  priority_queue<int> best_2s;
  
  for (int i = 1; i <= n; ++i)
    if (num_2[i] != 0)
      best_2s.push(num_2[i]);
  
  int answer = 0;
  while (best_2s.size() > 0)
  {
    if (counter >= best_2s.top())
    {
      counter -= best_2s.top();
      ++answer;
    }

    best_2s.pop();
  }
  
  cout << (counter == 0 ? answer : -1) << '\n';
}

int main()
{
  num_2[0] = 0;
  for (int i = 1; i <= num_2.size(); ++i)
    num_2[i] = i % 2 == 0 ? num_2[i / 2] + 1 : 0;

  int T;
  cin >> T;

  while (T--)
    solve();

  return 0;
}
