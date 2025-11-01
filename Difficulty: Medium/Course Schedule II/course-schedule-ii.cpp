class Solution {
  public:
    vector<int> res;
    void solve(int u,vector<bool>& vis,vector<vector<int>>& adj){
        if(vis[u]){
            return;
        }
        vis[u]=true;
        for(auto& it:adj[u]){
            solve(it,vis,adj);
        }
        res.push_back(u);
    }
  
  
  
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        for(auto& it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,vis,adj);
            }
        }
        return res;
    }
};