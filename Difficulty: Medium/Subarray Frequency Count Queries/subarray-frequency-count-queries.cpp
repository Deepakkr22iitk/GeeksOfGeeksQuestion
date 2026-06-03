class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int m=queries.size();
        vector<int> ans(m);
        unordered_map<int, vector<int>> mp;
    
        // Mapping val to index
        for(int i=0;i<n;++i) {
            mp[arr[i]].push_back(i);
        }
        
        for(int i=0;i<m;++i)
        {
            int lbVal = queries[i][0];
            int ubVal = queries[i][1];
            vector<int> &v = mp[queries[i][2]];
            
            // Lower Bound & Upper Bound for range
            int LB = lower_bound(v.begin(), v.end(), lbVal) - v.begin();
            int UB = upper_bound(v.begin(), v.end(), ubVal) - v.begin();
            
            ans[i] = UB - LB;
        }
        
        return ans;
    }
};