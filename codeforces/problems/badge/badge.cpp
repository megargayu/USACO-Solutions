// https://codeforces.com/contest/1020/problem/B

#include <iostream>
#include <string>

#include <array>

using namespace std;

array<int, 1000> students;
array<bool, 1000> visited{};
int main()
{
  int n;
  cin >> n;

  for (int i{0}; i < n; ++i)
  {
    cin >> students[i];
    --students[i];
  }

  for (int i{0}; i < n; ++i)
  {
    fill(visited.begin(), visited.end(), false);

    int curr{i};
    while (!visited[curr])
    {
      visited[curr] = true;
      curr = students[curr];
    }

    cout << curr + 1 << ' ';
  }
  cout << '\n';

  return 0;
}
