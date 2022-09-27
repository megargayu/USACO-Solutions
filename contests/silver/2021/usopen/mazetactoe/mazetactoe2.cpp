#include <bits/stdc++.h>
using namespace std;

#define MAX_N 25

struct Cell
{
  char c;
  int i = -1, j = -1;

  bool hasData()
  {
    return c == 'M' || c == 'O';
  }
};

const vector<int> pow3{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683};
vector<vector<vector<bool>>> seen(MAX_N, vector<vector<bool>>(MAX_N, vector<bool>(pow3[9])));
set<int> answers;

struct Board
{
  int state;

  Board(const int &s) : state(s) {}
  Board &operator=(const int &newState)
  {
    state = newState;
    return *this;
  }
  operator int const &() const { return state; }

  bool won()
  {
    vector<vector<int>> cells(3, vector<int>(3));
    int b = state;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
      {
        cells[i][j] = b % 3;
        b /= 3;
      }

    for (int r = 0; r < 3; r++)
    {
      if (cells[r][0] == 1 && cells[r][1] == 2 && cells[r][2] == 2)
        return true;
      if (cells[r][0] == 2 && cells[r][1] == 2 && cells[r][2] == 1)
        return true;
    }

    for (int c = 0; c < 3; c++)
    {
      if (cells[0][c] == 1 && cells[1][c] == 2 && cells[2][c] == 2)
        return true;
      if (cells[0][c] == 2 && cells[1][c] == 2 && cells[2][c] == 1)
        return true;
    }

    if (cells[0][0] == 1 && cells[1][1] == 2 && cells[2][2] == 2)
      return true;
    if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 1)
      return true;
    if (cells[2][0] == 1 && cells[1][1] == 2 && cells[0][2] == 2)
      return true;
    if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 1)
      return true;
    return false;
  }

  void set(int i, int j, int num)
  {
    int index = i * 3 + j;
    int currChar = (state / pow3[index]) % 3;
    if (currChar == 0)
    {
      state = (state % pow3[index]) + num * pow3[index] + (state - state % pow3[index + 1]);
      cout << won() << '\n';
      if (!seen[i][j][state] && won())
      {
        answers.insert(state);
        return;
      }
      seen[i][j][state] = true;
    }
  }
};

const vector<int> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};

int N;
vector<vector<Cell>> grid(MAX_N, vector<Cell>(MAX_N));

void dfs(int i, int j, Board board)
{
  if (seen[i][j][board])
    return;
  seen[i][j][board] = true;

  cout << grid[i][j].c << '\n';
  if (grid[i][j].hasData())
  {
    cout << "hi!" << endl;
    board.set(grid[i][j].i, grid[i][j].j, (grid[i][j].c != 'M') + 1);
  }

  for (int d = 0; d < 4; ++d)
    if (grid[i + dx[d]][j + dy[d]].c != '#')
      dfs(i + dx[d], j + dy[d], board);
}

int main()
{
  cin >> N;
  int si, sj;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
      cin >> grid[i][j].c;
      if (grid[i][j].c == 'M' || grid[i][j].c == 'O')
      {
        char tmpI, tmpJ;
        cin >> tmpI >> tmpJ;
        grid[i][j].i = tmpI - '1';
        grid[i][j].j = tmpJ - '1';
      }
      else
        cin >> grid[i][j].c >> grid[i][j].c;

      //cout << grid[i][j].c << grid[i][j].i << grid[i][j].j << '\n';

      if (grid[i][j].c == 'B')
      {
        si = i;
        sj = j;
      }
    }

  dfs(si, sj, 0);
  cout << answers.size() << '\n';

  return 0;
}