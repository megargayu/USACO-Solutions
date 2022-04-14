#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

// https://cp-algorithms.com/data_structures/segment_tree.html
vector<int> tree(4 * MAX_N, 0);
void build(vector<int> a, int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    tree[v] = tree[v*2] + tree[v*2+1];
  }
}
void build(vector<int> a) { build(a, 1, 0, a.size() - 1); }

int sum(int v, int tl, int tr, int l, int r)
{
  if (l > r) return 0;
  if (l == tl && r == tr) return tree[v];

  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, min(r, tm))
         + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
int sum(int n, int l, int r) { return sum(1, 0, n-1, l, r); }

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
void update(int n, int pos, int new_val) { update(1, 0, n-1, pos, new_val); }
