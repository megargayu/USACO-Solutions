// https://oj.uz/problem/view/IOI19_shoes
#include "shoes.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 100000

// https://cp-algorithms.com/data_structures/segment_tree.html
vector<int> tree(4 * 2*MAX_N, 0);
int sum(int v, int tl, int tr, int l, int r)
{
  if (l > r) return 0;
  if (l == tl && r == tr) return tree[v];

  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, min(r, tm))
         + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val)
{
  if (tl == tr) tree[v] = new_val;
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v*2, tl, tm, pos, new_val);
    else           update(v*2+1, tm+1, tr, pos, new_val);

    tree[v] = tree[v*2] + tree[v*2+1];
  }
}

map<int, set<int>> ind;
vector<bool> ignored(MAX_N * 2, false);
ll count_swaps(vector<int> S)
{
  for (int i = 0; i < S.size(); ++i)
    ind[S[i]].insert(i);
  
  ll ans = 0;
  for (int i = 0; i < S.size(); ++i)
  {
    if (ignored[i]) continue;
    auto index = ind[-S[i]].lower_bound(i);
    ignored[*index] = true;

    ans += *index - i - sum(1, 0, S.size() - 1, i, *index);
    if (S[i] < 0) --ans;

    update(1, 0, S.size() - 1, *index, 1);

    ind[-S[i]].erase(index);
  }

  return ans;
}
