#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50
#define INF 2147483647

struct Cow
{
  int x, y, eaten = INF;
  char dir;
};

vector<Cow> cows(MAX_N);
vector<int> differences;
int main()
{
  int N;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    cin >> cows[i].dir >> cows[i].x >> cows[i].y;
  }
  
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
    {
      differences.push_back(abs(cows[j].x - cows[i].x));
      differences.push_back(abs(cows[j].y - cows[i].y));
    }

  sort(differences.begin(), differences.end());

  for (const int &diff : differences)
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
      {
        if (cows[i].dir == 'E' && cows[j].dir == 'N' && cows[i].x < cows[j].x && 
                                                        cows[j].y < cows[i].y)
        {
          if (cows[i].x + diff == cows[j].x && 
              cows[j].y + min(cows[j].eaten, diff) > cows[i].y)
          {
            cows[i].eaten = min(cows[i].eaten, diff);
          }
          else if (cows[j].y + diff == cows[i].y && 
                   cows[i].x + min(cows[i].eaten, diff) > cows[j].x)
          {
            cows[j].eaten = min(cows[j].eaten, diff);
          }
        }
      }
  
  for (int i = 0; i < N; ++i)
  {
    cout << (cows[i].eaten == INF ? "Infinity" : to_string(cows[i].eaten)) << '\n';
  }

  return 0;
}
