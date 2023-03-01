/*
ID: megarga1
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

using namespace std;

enum class Wall
{
  South = 8,
  East = 4,
  North = 2,
  West = 1
};

constexpr array<Wall, 4> wallOrder{Wall::South, Wall::East, Wall::North, Wall::West};
constexpr array<int, 4> dx{0, 1, 0, -1};
constexpr array<int, 4> dy{1, 0, -1, 0};

class Room
{
public:
  array<bool, 4> walls{false};
  bool visited{false};
  int roomNum{-1};

  Room() {}

  void parse(int num)
  {
    for (size_t i{0}; i < wallOrder.size(); ++i)
      if (num >= static_cast<int>(wallOrder[i]))
      {
        walls[i] = true;
        num -= static_cast<int>(wallOrder[i]);
      }
  }
};

array<array<Room, 50>, 50> rooms;
int M, N;
int totalRooms{0}, largestRoom{0};

bool inGrid(int row, int col)
{
  return 0 <= row && row < N && 0 <= col && col < M;
}

// Returns the size of the room
int dfs(int roomNum, int row, int col)
{
  int size{1};
  rooms[row][col].visited = true;
  rooms[row][col].roomNum = roomNum;

  for (size_t i{0}; i < dx.size(); ++i)
  {
    int newRow{row + dy[i]}, newCol{col + dx[i]};
    if (inGrid(newRow, newCol) && !rooms[newRow][newCol].visited &&
        !rooms[row][col].walls[i])
      size += dfs(roomNum, newRow, newCol);
  }

  return size;
}

int main()
{
  ofstream fout("castle.out");
  ifstream fin("castle.in");

  fin >> M >> N;
  for (int row{0}; row < N; ++row)
    for (int col{0}; col < M; ++col)
    {
      int num;
      fin >> num;
      rooms[row][col].parse(num);
    }

  vector<int> roomSizes;
  for (int startRow{0}; startRow < N; ++startRow)
    for (int startCol{0}; startCol < M; ++startCol)
      if (!rooms[startRow][startCol].visited)
      {
        roomSizes.push_back(dfs(totalRooms, startRow, startCol));
        largestRoom = max(largestRoom, roomSizes[totalRooms]);
        ++totalRooms;
      }

  int roomRow{0}, roomCol{0};
  char wallDir{'\0'};
  int maxRoomAfterWallRemoved{0};
  for (int col{0}; col < M; ++col)
    for (int row{N - 1}; row >= 0; --row)
    {
      if (inGrid(row - 1, col) && rooms[row][col].walls[2] &&
          rooms[row][col].roomNum != rooms[row - 1][col].roomNum)
      {
        int newRoomSize{roomSizes[rooms[row][col].roomNum] +
                        roomSizes[rooms[row - 1][col].roomNum]};

        if (newRoomSize > maxRoomAfterWallRemoved)
        {
          maxRoomAfterWallRemoved = newRoomSize;
          roomRow = row;
          roomCol = col;
          wallDir = 'N';
        }
      }

      if (inGrid(row, col + 1) && rooms[row][col].walls[1] &&
          rooms[row][col].roomNum != rooms[row][col + 1].roomNum)
      {
        int newRoomSize{roomSizes[rooms[row][col].roomNum] +
                        roomSizes[rooms[row][col + 1].roomNum]};

        if (newRoomSize > maxRoomAfterWallRemoved)
        {
          maxRoomAfterWallRemoved = newRoomSize;
          roomRow = row;
          roomCol = col;
          wallDir = 'E';
        }
      }
    }

  fout << totalRooms << '\n';
  fout << largestRoom << '\n';
  fout << maxRoomAfterWallRemoved << '\n';
  fout << roomRow + 1 << ' ' << roomCol + 1 << ' ' << wallDir << '\n';

  return 0;
}
