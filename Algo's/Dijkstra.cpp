#include<bits/stdc++.h>
using namespace std;

// Typedefs
using ll   = long long;
using ull  = unsigned long long;
// Constants
const char endL = '\n';
const ll   MOD  = (1e9+7);
const ll   INF  = 1e18; // Infinity for initial distances

// Fast IO
#define NAH   ios_base::sync_with_stdio(false);
#define I_D   cin.tie(nullptr);
#define WIN   cout.tie(nullptr);

//==========(->MAIN CODE<-)==========

void dijkstra(ll src, vector<vector<pair<ll, ll>>> &adj, ll V) {
    vector<ll> dist(V + 1, INF);
    set<pair<ll, ll>> st; 
    
    dist[src] = 0;
    st.insert({0, src}); // {dist, node}
    
    while (!st.empty()) {
        auto it = st.begin();
        ll curr_dist = it->first;
        ll curr = it->second;
        st.erase(it); // Remove it (increment-type[don't need it++])

        for(auto &edge : adj[curr]) {
            ll neigh = edge.first;
            ll weight = edge.second;

            // Relaxation
            if (dist[curr] + weight < dist[neigh]) {
                if (dist[neigh] != INF) {
                    st.erase({dist[neigh], neigh});
                }

                dist[neigh] = dist[curr] + weight;
                st.insert({dist[neigh], neigh});
            }
        }
    }
    
    // Print the shortest distances from the source
    cout << "Shortest distances from node " << src << ":" << endL;
    for (int i = 0; i < V; ++i) { 
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endL;
}

void graph () {
    ll V, E;
    cin >> V >> E;

    // Adjacency list {neighbor, weight}
    vector<vector<pair<ll, ll>>> adj(V + 1);
    for (int i = 0; i < E; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected-weighted graph
    }
    
    ll src;
    cin >> src; // source node for Dijkstra
    
    dijkstra(src, adj, V);
}

int main() {
    NAH I_D WIN

    //test cases
    int test = 1;
    cin >> test;

    for(int i = 1; i <= test; i++) {
        //cout << "Case " << i <<":\n";
        graph();
    }
    return 0;
}