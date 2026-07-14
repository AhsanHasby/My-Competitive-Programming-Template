#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5 + 5;

int n, m;
ll dis[N];
vector<pair<int,ll>> adj[N];
bool vis[N];

void dijkstra(int start)
{
    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    pq.push({0, start});

    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        ll cost = p.first;
        int node = p.second;

        if(vis[node]) continue;

        vis[node] = true;
        dis[node] = cost;

        for(auto [next, weight] : adj[node])
        {
            if(!vis[next])
            {
                pq.push({cost + weight, next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++)
    {
        if(vis[i])
            cout << dis[i] << " ";
        else
            cout << -1 << " ";
    }
}