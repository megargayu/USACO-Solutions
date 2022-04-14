#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

// always sorted in ascending order; binary search
vector<vector<int>> stacks;
int N;

int findGreater(int val)
{
  int lo = 0, hi = stacks.size() - 1, mid, ans = -1;
  while (lo <= hi)
  {
    mid = lo + (hi - lo) / 2;
    if (stacks[mid][0] > val)
    {
      ans = mid;
      hi = mid - 1;
    }
    else lo = mid + 1;
  }

  return ans;
}

int main()
{
  ifstream fin("dishes.in");
  ofstream fout("dishes.out");
  
  fin >> N;

  int plate;
  int maxWashed = -1;
  for (int i = 0; i < N; ++i)
  {
    fin >> plate;

    if (plate < maxWashed)
    {
      // cannot wash anymore!!
      fout << i << '\n';
      return 0;
    }

    int greater = findGreater(plate);
    // no values greater, make new stack
    if (greater == -1) 
    {
      stacks.push_back({ plate });
      continue;
    }

    // can add to this stack!
    if (plate < stacks[greater].back())
    {
      stacks[greater].push_back(plate);
      continue;
    }

    // cannot add to the stack!! this means we have
    // to start washing dishes until we can add it to the stack.

    // NOTE: potentially do binary search here as well, but there really
    // is no use (this is still very fast because all the dishes are distributed
    // over multiple stacks so this stack doesn't have that many dishes)
    for (int i = stacks[greater].size() - 1; i >= 0 && stacks[greater].back() < plate; --i)
    {
      maxWashed = max(maxWashed, stacks[greater].back());
      stacks[greater].pop_back();
    }
    stacks[greater].push_back(plate);
  }

  fout << N << '\n';
  return 0;
}
