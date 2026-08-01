#include<bits/stdc++.h>
using namespace std;

// Typedefs
using ll   = long long;
using ull  = unsigned long long;
// Constants
const char endL = '\n';
const ll   MOD  = (1e9+7);
// Fast IO
#define NAH    ios_base::sync_with_stdio(false);
#define I_D   cin.tie(nullptr);
#define WIN cout.tie(nullptr);

//==========(->MAIN CODE<-)==========


void bfs (int src, vector<vector<ll>> &adj, vector<bool> &vis) {
    if (vis[src]) return;
    vis[src] = true;
    queue<ll> q;
    q.push(src);
    
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        cout << curr << " ";

        for(auto &neigh : adj[curr]) {
            if(!vis[neigh]) {
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endL;
    
}

void graph () {
    ll V, E;
    cin >> V >> E;

    vector<vector<ll>> adj(V+1);
    for (int i = 0; i < E; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); //undirected-unweighted graph
    }
    vector<bool> vis(adj.size(), false);
    
    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            bfs(i, adj, vis);
        }
    }
}

int main() {
    NAH I_D WIN

    //test cases
    int test = 1;
    cin >> test;

    for(int i = 1; i <= test; i++) {
        //cout << "Case " << i <<": ";
        graph();
    }
    return 0;
}