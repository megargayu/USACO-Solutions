#include <bits/stdc++.h>
using namespace std;

#define MAX_N 3e5
#define ll long long

vector<int> heights(MAX_N);
int N;
ll ans = 0;

void find()
{
  stack<int> s;
  for (int i = N - 1; i >= 0; --i)
  {
    // find valid element to the right
    while (!s.empty() && heights[s.top()] < heights[i]) s.pop();

    // add element to answer
    if (!s.empty()) ans += s.top() - i + 1;

    // add this to stack to check if it is valid with another left value later
    s.push(i);
  }
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> heights[i];

  find();
  reverse(heights.begin(), heights.begin() + N);
  find();

  cout << ans << '\n';
  return 0;
}
