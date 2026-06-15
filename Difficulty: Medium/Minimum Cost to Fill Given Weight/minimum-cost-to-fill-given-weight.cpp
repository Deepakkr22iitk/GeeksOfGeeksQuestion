class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        int n=cost.size();
        
        vector<int> curr(w+1, 1e8);
        vector<int> prev(w+1, 1e8);
        prev[0] = curr[0] = 0;
        
        for(int i = 1; i <= n; i++){
            curr[0] = 0;
            for(int idx = 0; idx <= w; idx++){
                int nontake = prev[idx];
                int take = 1e8;
                if(cost[i-1] != -1 && i <= idx){
                    take = cost[i-1] + curr[idx-i];
                }
                curr[idx] = min(take, nontake);
            }
            prev = curr;
        }
        if(prev[w] == 1e8) return -1;
        return prev[w];
    }
};
