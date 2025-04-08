//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int c, int d) {
        vis[node] = 1;
        for (int neighbor : adj[node]) {
            // Skip the edge (c, d) or (d, c)
            if (!vis[neighbor] && !((node == c && neighbor == d) || (node == d && neighbor == c))) {
                dfs(neighbor, adj, vis, c, d);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> vis(V, 0);
    
        // Start DFS from vertex c, skipping the edge (c, d)
        dfs(c, adj, vis, c, d);
    
        // If d is not visited, (c, d) was a bridge
        return !vis[d];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends