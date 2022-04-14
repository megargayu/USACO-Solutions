#include <bits/stdc++.h>
using namespace std;

// TODO

enum class NodeType
{
  Wall,
  Empty,
  Note
};

struct Node
{
  NodeType type;
  char ch;
  int row, col;
};

#define MAX_N 25

const array<int, 4> dr{0, 1, 0, -1},
                    dc{1, 0, -1, 0};

array<array<Node, MAX_N>, MAX_N> grid;
array<array<bool, MAX_N>, MAX_N> visited;
unordered_set<string> boards;
int N;

bool inGrid(int row, int col)
{
  return 0 <= row && row < N && 0 <= col && col < N;
}

bool winning(const string &board)
{
  // 0 1 2
  // 3 4 5
  // 6 7 8

  // rows
  for (int row = 0; row < 3; ++row)
  {
    if (board[row * 3] == 'M' && board[row * 3 + 1] == 'O' && 
                                 board[row * 3 + 2] == 'O')
      return true;
    if (board[row * 3 + 2] == 'M' && board[row * 3] == 'O' && 
                                     board[row * 3 + 1] == 'O')
      return true;
  }

  // columns
  for (int col = 0; col < 3; ++col)
  {
    if (board[col] == 'M' && board[col + 3] == 'O' && board[col + 6] == 'O')
      return true;
    if (board[col + 6] == 'M' && board[col] == 'O' && board[col + 3] == 'O')
      return true;
  }

  // diagonals
  if (board[0] == 'M' && board[4] == 'O' && board[8] == 'O') return true;
  if (board[2] == 'M' && board[4] == 'O' && board[6] == 'O') return true;
  if (board[6] == 'M' && board[4] == 'O' && board[2] == 'O') return true;
  if (board[8] == 'M' && board[4] == 'O' && board[0] == 'O') return true;

  // not winning
  return false;
}

void floodfill(int row, int col, string board)
{
  visited[row][col] = true;
  if (grid[row][col].type == NodeType::Note)
    board[grid[row][col].row * 3 + grid[row][col].col] = grid[row][col].ch;

  cout << board << '\n';
  if (winning(board))
  {
    boards.insert(board);
    cout << "WON!!\n";
  }

  for (int i = 0; i < 4; ++i)
  {
    int nrow = row + dr[i], ncol = col + dc[i];
    if (inGrid(nrow, ncol) && !visited[nrow][ncol])
      floodfill(nrow, ncol, board);
  }
}

int main()
{
  cin >> N;

  array<char, 3> chars;
  int sr, sc;
  for (int row = 0; row < N; ++row)
    for (int col = 0; col < N; ++col)
    {
      cin >> chars[0] >> chars[1] >> chars[2];
      switch (chars[0])
      {
        case '#': grid[row][col].type = NodeType::Wall; break;
        case '.': grid[row][col].type = NodeType::Empty; break;
        case 'B': 
          grid[row][col].type = NodeType::Empty;
          sr = row, sc = col;
          break;
        default:
          grid[row][col] = { NodeType::Note, chars[0], chars[1] - '1', chars[2] - '1' };
          break;
      } 
    }

  floodfill(sr, sc, ".........");
  cout << winning("MOO......") << '\n';

  return 0;
}
