#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2e5
#define ll long long

struct Order
{
  int a, b;
  ll x;
};

int N;
ll avgWant;
vector<ll> h(MAX_N);
vector<vector<int>> adj(MAX_N);

vector<bool> vis(MAX_N, false);

vector<ll> subtree(MAX_N);
// vector<ll> update(MAX_N);
vector<int> num(MAX_N);
vector<Order> ans;

void dfs1(int v, int prev)
{
  num[v] = 1;
  subtree[v] = h[v];

  for (const int &w : adj[v])
    if (w != prev)
    {
      dfs1(w, v);
      subtree[v] += subtree[w];
      num[v] += num[w];
    }
}

void moveHay(int a, int b, ll x)
{
  ans.push_back({a, b, x});
}

void dfs2(int v)
{
  vis[v] = true;

  // suck hay up
  for (const int &w : adj[v])
    if (!vis[w] && num[w] * avgWant < subtree[w]) // needs less than has
    {
      dfs2(w);
      moveHay(w, v, subtree[w] - num[w] * avgWant); // suck up extra amount
      subtree[w] = num[w] * avgWant;
      assert (subtree[w] >= 0);
    }

  // cout << update[v] << '\n';

  // push hay down
  for (const int &w : adj[v])
    if (!vis[w] && num[w] * avgWant > subtree[w]) // needs more than has
    {
      moveHay(v, w, num[w] * avgWant - subtree[w]); // put down needed amount
      subtree[w] = num[w] * avgWant;
      assert (subtree[w] >= 0);
      dfs2(w);
    }

  // solve subtrees that have their values perfect
  for (const int &w : adj[v])
    if (!vis[w] && num[w] * avgWant == subtree[w])
      dfs2(w);
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> h[i];

  int a, b;
  for (int i = 0; i < N - 1; ++i)
  {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs1(0, -1);
  assert (subtree[0] % N == 0);
  avgWant = subtree[0] / N;

  // copy(subtree.begin(), subtree.end(), update.begin());

  dfs2(0);

  cout << ans.size() << '\n';
  for (const Order &order : ans)
    cout << order.a + 1 << ' ' << order.b + 1 << ' ' << order.x << '\n';

  return 0;
}
