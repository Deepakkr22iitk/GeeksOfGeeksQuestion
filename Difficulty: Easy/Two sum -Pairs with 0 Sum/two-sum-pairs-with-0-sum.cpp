class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int n=arr.size();
        int j=n-1;
        for(int i=0;i<n-1&&j>i;)
        {
            while(arr[i]+arr[j] > 0) j--;
            if(i<j && arr[i]+arr[j]==0) ans.push_back({arr[i],arr[j]});
            while(arr[i+1]==arr[i])i++;
            ++i;
        }
        return ans;
    }
};