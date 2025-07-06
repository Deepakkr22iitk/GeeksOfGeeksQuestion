class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // Step 1: Sort both arrays in ascending order
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int n = a.size();
        
        // Max-heap to store {sum, {i, j}} pairs
        priority_queue<pair<int, pair<int,int>>> pq;
        
        // Visited set to avoid duplicate pairs
        set<pair<int,int>> vis;
        
        // Push the largest possible sum (a[n-1] + b[n-1])
        pq.push({a[n-1] + b[n-1], {n-1, n-1}});
        vis.insert({n-1, n-1});
        
        vector<int> ans;
        
        // Step 2: Extract top k sums
        while(ans.size() < k) {
            // Get the current largest sum
            auto current = pq.top();
            int sum = current.first;
            int i = current.second.first;
            int j = current.second.second;
            
            // Add sum to the result
            ans.push_back(sum);
            pq.pop();
            
            // Explore (i-1, j) if not visited
            if(i-1 >= 0 && !vis.count({i-1, j})) {
                pq.push({a[i-1] + b[j], {i-1, j}});
                vis.insert({i-1, j});
            }
            
            // Explore (i, j-1) if not visited
            if(j-1 >= 0 && !vis.count({i, j-1})) {
                pq.push({a[i] + b[j-1], {i, j-1}});
                vis.insert({i, j-1});
            }
        }
        
        return ans;
    }
};