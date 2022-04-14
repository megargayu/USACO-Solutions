#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5

vector<vector<int>> adj(MAX_N);
vector<int> distL(MAX_N), distK(MAX_N);
queue<int> q;
int ans = 0;

void bfs(vector<int> &dist)
{
    //everything initially in the queue, dist = 0
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w : adj[v])
        {
            //adjustment to the bfs
            if (dist[w] >= dist[v] + 1)
            {
                dist[w] = dist[v]+1;
                q.push(w);
            }
        }
    }
}

void dfs(int cur, int par)
{
    for (int w : adj[cur])
    {
        if (w == par) continue;
        if(distK[w] >= distL[w]) ans++;
        else dfs(w, cur);
    }
}
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}
int main()
{
    setIO("atlarge", 1);
   // ifstream fin("atlarge.in");
   // ofstream fout("atlarge.out");


    int N, K;
    cin >> N >> K;
    --K;

    int a, b;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(distL.begin(), distL.end(), 1e9);
    for (int i = 0; i < N; ++i)
    {
        if (adj[i].size() == 1 && i!=K)
        {
            q.push(i);
            distL[i] = 0;
        }
    }
    bfs(distL);
    fill(distK.begin(), distK.end(), 1e9);

    q.push(K);
    distK[K] = 0;
    bfs(distK);
    /*for (int i=0; i<N; i++){
        cout<<distL[i]<<endl;
    }*/

    dfs(K, -1);
    cout << ans << '\n';
}
