#include <bits/stdc++.h>
using namespace std;

#define MAX 50000

// https://cp-algorithms.com/data_structures/segment_tree.html
vector<int> tree(4 * 2*MAX, 0);
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

void update_add(int v, int tl, int tr, int pos, int new_val)
{
  if (tl == tr) tree[v] += new_val;
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update_add(v*2, tl, tm, pos, new_val);
    else           update_add(v*2+1, tm+1, tr, pos, new_val);

    tree[v] = tree[v*2] + tree[v*2+1];
  }
}
void update_add(int n, int pos, int new_val) { update_add(1, 0, n-1, pos, new_val); }

#define pii pair<int, int>
vector<pii> cows(MAX, { -1, -1 });
int main()
{
  ifstream fin("circlecross.in");
  ofstream fout("circlecross.out");

  int N;
  fin >> N;

  int a;
  for (int i = 0; i < 2*N; ++i)
  {
    fin >> a; --a;
    if (cows[a].first == -1) cows[a].first = i;
    else cows[a].second = i;
  }

  sort(cows.begin(), cows.begin() + N);

  int ans = 0;
  for (int i = 0; i < N; ++i)
  {
    ans += sum(2*N, cows[i].first, cows[i].second);
    update_add(2*N, cows[i].second, 1);
  }

  fout << ans << '\n';

  return 0;
}
