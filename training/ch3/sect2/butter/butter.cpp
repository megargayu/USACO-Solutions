/*
ID: megarga1
TASK: butter
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define MAX_P 800
#define MAX_C 1450
#define INF 1000000000

// TODO

int N, P, C;
vector<int> cows(MAX_N);
vector<vector<pair<int, int>>> adj(MAX_C);
// dist of each pasture to each other pasture
vector<vector<int>> dist(MAX_P, vector<int>(MAX_P, INF));

void dijkstra(int pasture)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < P; ++i)
        if (i != pasture)
            q.push(i);

    // this cow's distance to the pasture it's on is 0
    dist[][cow] = 0;

    while (!q.empty())
    {
        int u = q.top();
    }
}

int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");

    fin >> N >> P >> C;
    for (int i = 0; i < N; ++i)
    {
        fin >> cows[i];
        --cows[i];
    }
    
    int a, b, w;
    for (int i = 0; i < C; ++i)
    {
        fin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }



    return 0;
}
