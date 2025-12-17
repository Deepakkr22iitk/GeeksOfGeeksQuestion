class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int open=arr[i][0];
            int idx=i+1;
            int close=arr[i][1];
            while(idx<n && arr[idx][0]<=close) 
            {
                close=max(close,arr[idx][1]);
                i=idx;
                idx++;
            }
            idx--;
            i=idx;
            ans.push_back({open,close});
        }
        return ans;
    }
};