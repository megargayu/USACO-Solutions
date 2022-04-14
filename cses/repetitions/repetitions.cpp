// https://cses.fi/problemset/task/1069

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int answer = 0;
  string line;
  cin >> line;

  int curr = 1;
  for (int i = 1; i < line.length(); ++i)
  {
    if (line[i] == line[i - 1])
      ++curr;
    else
    {
      answer = max(curr, answer);
      curr = 1;
    }
  }

  cout << max(curr, answer) << '\n';

  return 0;
}
