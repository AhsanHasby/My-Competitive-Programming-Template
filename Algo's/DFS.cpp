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


void dfs (int src, vector<vector<ll>> &adj, vector<bool> &vis) {
    if (vis[src]) return;
    vis[src] = true;
    cout << src << " ";

    for (auto &neigh: adj[src]) {
        if(!vis[neigh]) {
            dfs(neigh, adj, vis);
        }
    }
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
            dfs(i, adj, vis);
            cout << endL;
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