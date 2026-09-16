class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0}); // original edge
            adj[v].push_back({u, 1}); // reversed edge
        }

        vector<int> dist(n + 1, 1e9);

        // {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Ignore outdated entry
            if (d != dist[u])
                continue;

            for (auto &[v, cost] : adj[u]) {
                if (d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};