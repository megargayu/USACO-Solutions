#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int N, M;
const vector<int> dr{0, 1, 0, -1};
const vector<int> dc{1, 0, -1, 0};

vector<vector<char>> grid(MAX, vector<char>(MAX));
int answer = 0;

bool inGrid(int row, int col)
{
  return 0 <= row && row < N && 0 <= col && col < M;
}

bool isCow(int row, int col)
{
  return inGrid(row, col) && grid[row][col] == 'C';
}

int main()
{
  cin >> N >> M;

  for (int row = 0; row < N; ++row)
    for (int col = 0; col < M; ++col)
      cin >> grid[row][col];
  
  // all cows on other sides of the same grass patch can only become friends
  // through that grass patch
  for (int row = 0; row < N; ++row)
    for (int col = 0; col < M; ++col)
      if (grid[row][col] == 'G' && 
          ((isCow(row + 1, col) && isCow(row - 1, col)) || 
           (isCow(row, col + 1) && isCow(row, col - 1))))
      {
        grid[row][col] = '.';
        ++answer;
      }
  
  // any other pair of cows that are both adjacent to a grass patch
  // can become friends through 2 different grass patches - make sure to not
  // double count them!
  set<pair<pair<int, int>, pair<int, int>>> cowPairs;
  for (int row = 0; row < N; ++row)
    for (int col = 0; col < M; ++col)
      if (grid[row][col] == 'G')
      {
        // bottom left & right
        if (isCow(row + 1, col))
        {
          if (isCow(row, col - 1))
            cowPairs.insert(minmax<pair<int, int>>({row + 1, col}, {row, col - 1}));
          else if (isCow(row, col + 1))
            cowPairs.insert(minmax<pair<int, int>>({row + 1, col}, {row, col + 1}));
        }
        else if (isCow(row - 1, col))
        {
          if (isCow(row, col - 1))
            cowPairs.insert(minmax<pair<int, int>>({row - 1, col}, {row, col - 1}));
          else if (isCow(row, col + 1))
            cowPairs.insert(minmax<pair<int, int>>({row - 1, col}, {row, col + 1}));
        }
      }

  cout << answer + cowPairs.size() << '\n';

  return 0;
}
