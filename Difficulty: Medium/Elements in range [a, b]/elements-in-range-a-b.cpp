class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for(auto i:queries)
        {
            int l = lower_bound(arr.begin(),arr.end(),i[0])-arr.begin();
            int r = upper_bound(arr.begin(),arr.end(),i[1])-arr.begin();
            ans.push_back(r-l);
        }
        return ans;
    }
};